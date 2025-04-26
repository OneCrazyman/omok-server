#include "Server.h"
#include "ConsoleLogger.h"

#include "NetLib/Define.h"
#include "NetLib/TcpNetwork.h"
#include "UserManager.h"

using NET_ERROR_CODE = NServerNetLib::NET_ERROR_CODE;
using LOG_TYPE = NServerNetLib::LOG_TYPE;

Server::Server() {
}

Server::~Server() {
    Release();
}

ERROR_CODE Server::Init() {
    // ILog상속받은 ConsoleLog객체를 동적생성하여 m_pLogger가 관리하도록 할당
    m_pLogger = std::make_unique<ConsoleLog>();

    LoadConfig();

    m_pNetwork = std::make_unique<NServerNetLib::TcpNetwork>();
    auto result = m_pNetwork->Init(m_pServerConfig.get(), m_pLogger.get());

    if (result != NET_ERROR_CODE::NONE) {
        m_pLogger->Write(LOG_TYPE::L_ERROR, "%S | Init Fail. NetErrorCode(%s)", __FUNCTION__, (short)result);
        return ERROR_CODE::MAIN_INIT_NETWORK_INIT_FAIL;
    }

    m_pUserMgr = std::make_unique<UserManager>();   // 하나의 객체만 관리
    m_pUserMgr->Init(m_pServerConfig->MaxClientCount);  // Config 값에 따라 Init (세팅 파일 분리)

    // do

    return ERROR_CODE();
}

void Server::Release() {
    if (m_pNetwork) {
        m_pNetwork->Release();
    }
}

ERROR_CODE Server::LoadConfig() {
    // 하드코딩X -> 실제론 파일로 빼야한다
    m_pServerConfig = std::make_unique<NServerNetLib::ServerConfig>();

    // Define.h 임포트 필요, 구조체의 변수 정보 필요
    m_pServerConfig->Port = 11021;
    m_pServerConfig->BackLogCount = 128;
    m_pServerConfig->MaxClientCount = 1000;

    m_pServerConfig->MaxClientSockOptRecvBufferSize = 10240;
    m_pServerConfig->MaxClientSockOptSendBufferSize = 10240;
    m_pServerConfig->MaxClientRecvBufferSize = 8192;
    m_pServerConfig->MaxClientSendBufferSize = 8192;

    m_pServerConfig->ExtraClientCount = 64;
    m_pServerConfig->MaxRoomCount = 20;
    m_pServerConfig->MaxRoomUserCount = 4;

    m_pLogger->Write(NServerNetLib::LOG_TYPE::L_INFO, "%s | Port(%d), Backlog(%d)", __FUNCTION__, m_pServerConfig->Port, m_pServerConfig->BackLogCount);
    return ERROR_CODE::NONE();
}