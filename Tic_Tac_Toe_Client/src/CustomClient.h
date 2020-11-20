#pragma once
#include "Tiny.h"

// IMPORTANT DO NOT CHANGE THE ORDER 
enum class CustomMsgTypes : uint32_t
{
	ServerAccept,
	FindMatch,
	MatchFound,
	BoardUpdate,
	MoveRegister,
	SignalServerDisconnect
};


class CustomClient : public Tiny::net::client_interface<CustomMsgTypes>
{
public:
	CustomClient();
	~CustomClient();

	//void PingServer();
	//void MessageAll();
	void SetNetID(uint32_t& id) { m_NetID = id; }
	uint32_t GetNetID() const { return m_NetID; }
private:
	uint32_t m_NetID;
};

