#pragma once
#include "Tiny.h"

#include <queue>
#include <thread>

// IMPORTANT DO NOT CHANGE THE ORDER 
enum class CustomMsgTypes : uint32_t
{
	ServerAccept,
	FindMatch,
	MatchFound,
	BoardUpdate,
	MoveRegister,
	SignalServerDisconnect,
	ServerPing
};

enum class BlockType
{
	NONE = 0,
	BLACK = 1,
	WHITE = 2
};

enum class Player
{
	NONE = 0,
	PLAYER_1, // Always BlACK
	PLAYER_2, // Always White
	AI
};


class CustomServer : public Tiny::net::server_interface<CustomMsgTypes>
{
public:
	CustomServer(std::string ServerIP, uint16_t nPort);
	~CustomServer();

	//void MatchMaking(uint32_t seeker_ID);
//
//private:
//	Tiny::net::connection<CustomMsgTypes>& GetClientRef(uint32_t ID);
protected:
	virtual bool OnClientConnect(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client) override;
	// Called when a client appears to have disconnected
	virtual void OnClientDisconnect(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client) override;
	// Called when a message arrives
	virtual void OnMessage(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client, Tiny::net::message<CustomMsgTypes>& msg) override;

private:

	uint32_t m_CurrentPlayer;
	BlockType m_BoardRef[3][3] = {
		{BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{BlockType::NONE, BlockType::NONE, BlockType::NONE} };
};