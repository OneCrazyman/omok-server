#include "Server.h"
#include "ConsoleLogger.h"

#include "NetLib/Define.h"
#include "NetLib/TcpNetwork.h"

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

    return ERROR_CODE();
}

void Server::Release() {
    if (m_pNetwork) {
        m_pNetwork->Release();
    }
}

ERROR_CODE Server::LoadConfig() {
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