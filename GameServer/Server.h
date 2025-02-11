#pragma once
#include <memory>
#include "ErrorCode.h"

namespace NServerNetLib {
	struct ServerConfig;
	class ILog;
	class ITcpNetwork;
}

class Server {
public:
	Server();
	~Server();

	ERROR_CODE Init();

	void Run();

	void Stop();

private:
	void Release();
	ERROR_CODE LoadConfig();

private:
	std::unique_ptr<NServerNetLib::ServerConfig> m_pServerConfig;
	std::unique_ptr<NServerNetLib::ILog> m_pLogger;
	std::unique_ptr<NServerNetLib::ITcpNetwork> m_pNetwork;
};