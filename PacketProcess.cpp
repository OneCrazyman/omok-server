#include <cstring>

#include "NetLib/ILog.h"
#include "NetLib/TcpNetwork.h"
#include "User.h"
#include "UserManager.h"
#include "Room.h"
#include "RoomManager.h"
#include "PacketProcess.h"

using LOG_TYPE = NServerNetLib::LOG_TYPE;
using ServerConfig = NServerNetLib::ServerConfig;

PacketProcess::PacketProcess() {}
PacketProcess::~PacketProcess() {}

void PacketProcess::Init(TcpNet* pNetwork, UserManager* pUserMgr, RoomManager* pRoomMgr, NServerNetLib::ServerConfig* pConfig, ILog* pLogger) {
	m_pRefLogger = pLogger;
	m_pRefNetwork = pNetwork;
	m_pRefUserMgr = pUserMgr;
	m_pRefRoomMgr = pRoomMgr;
}


void PacketProcess::Process(PacketInfo packetInfo){
	using netLibPacketId = NServerNetLib::PACKET_ID;
	using commonPacketId = PACKET_ID;
	
	auto packetId = packetInfo.PacketId;

	switch (packetId) {
	case (int)netLibPacketId::NTF_SYS_CONNECT_SESSION:
		NtfSysConnectSession(packetInfo);
		break;
	case (int)netLibPacketId::NTF_SYS_CLOSE_SESSION:
		NtfSysCloseSession(packetInfo);
		break;
	case (int)commonPacketId::LOGIN_IN_REQ:
		Login(packetInfo);
		break;
	}
}

ERROR_CODE PacketProcess::NtfSysConnectSession(PacketInfo packetInfo)
{
	m_pRefLogger->Write(LOG_TYPE::L_INFO, "%s | NtfSysConnectSession. sessionIndex(%d)", __FUNCTION__, packetInfo.SessionIndex);
	return ERROR_CODE::NONE;
}

ERROR_CODE PacketProcess::NtfSysCloseSession(PacketInfo packetInfo)
{
	auto pUser = std::get<1>(m_pRefUserMgr->GetUser(packetInfo.SessionIndex));

	if (pUser) {
		m_pRefUserMgr->RemoveUser(packetInfo.SessionIndex);
	}

	m_pRefLogger->Write(LOG_TYPE::L_INFO, "%s | NtfSysCloseSession. sessionIndex(%d)", __FUNCTION__, packetInfo.SessionIndex);

	return ERROR_CODE::NONE;
}

ERROR_CODE PacketProcess::Login(PacketInfo packetInfo)
{
	// 패스워드는 무조건 pass해준다.
	// ID 중복이면 에러 처리한다.
	PktLogInRes resPkt;
	auto reqPkt = (PktLogInReq*)packetInfo.pRefData;

	auto addRet = m_pRefUserMgr->AddUser(packetInfo.SessionIndex, reqPkt->szID);

	if (addRet != ERROR_CODE::NONE) {
		resPkt.SetError(addRet);
		m_pRefNetwork->SendData(packetInfo.SessionIndex, (short)PACKET_ID::LOGIN_IN_RES, sizeof(PktLogInRes), (char*)&resPkt);
		return addRet;
	}
	
	resPkt.ErrorCode = (short)addRet;
	m_pRefNetwork->SendData(packetInfo.SessionIndex, (short)PACKET_ID::LOGIN_IN_RES, sizeof(PktLogInRes), (char*)&resPkt);

	return ERROR_CODE::NONE;
}


