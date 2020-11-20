#include "CustomServer.h"


CustomServer::CustomServer(std::string ServerIP,uint16_t nPort)
	: Tiny::net::server_interface<CustomMsgTypes>(ServerIP,nPort)
{
}

CustomServer::~CustomServer()
{
}

bool CustomServer::OnClientConnect(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client)
{
	if (m_deqConnections.size() >= 2) 
	{
		return false;
	}
	Tiny::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::ServerAccept;

	// TEMP -> Please find a better solution
	if(!m_deqConnections.empty())
		msg << m_deqConnections.back()->GetID() + 1;
	else
		msg << 10000 + client->GetID();

	client->Send(msg);
	return true;
}

void CustomServer::OnClientDisconnect(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client)
{
	std::cout << "Removing client [" << client->GetID() << "]\n";
}

void CustomServer::OnMessage(Tiny::Ref<Tiny::net::connection<CustomMsgTypes>> client, Tiny::net::message<CustomMsgTypes>& msg)
{

	switch (msg.header.id)
	{
		case CustomMsgTypes::FindMatch:
		{
			std::cout << "[ " << client->GetID() << " ]: Find Match" << std::endl;

			if (m_deqConnections.size() == 2)
			{
				// Initialize Board with NONE 
				/*for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						m_BoardRef[i][j] = BlockType::NONE;*/
				
				// Assign Current Player to client ID
				m_CurrentPlayer = client->GetID();

				// Message All Clients with Match Found and current player ID
				auto& msg = Tiny::net::message<CustomMsgTypes>();
				msg.header.id = CustomMsgTypes::MatchFound;
				//msg << m_BoardRef << m_CurrentPlayer;
				msg << m_CurrentPlayer;

				MessageAllClients(msg);
			}
			
			break;
		}
		case CustomMsgTypes::MoveRegister:
		{
			std::cout << "[ " << client->GetID() << " ]: Move Register" << std::endl;
			
			// Get the client Move Index 
			uint32_t temp_Playermove[2];
			msg >> temp_Playermove;


			//// Sync Server Board Reference 
			//if(client->GetID() == m_CurrentPlayer)
			//m_BoardRef[temp_Playermove[0]][temp_Playermove[1]] = client->GetID() == m_CurrentPlayer ? BlockType::WHITE : BlockType::BLACK;

			// Message all clients with BoardSync and CurrentPlayerID
			auto& msg = Tiny::net::message<CustomMsgTypes>();
			msg.header.id = CustomMsgTypes::BoardUpdate;

			// Swapt Current Player
			if (client->GetID() == m_CurrentPlayer)
			{
				for(auto& c : m_deqConnections)
					if(client->GetID() != c->GetID())
						m_CurrentPlayer = c->GetID();
			}


			// Simply bounce message back to clients
			msg << temp_Playermove << m_CurrentPlayer;
			MessageAllClients(msg);
			break;
		}
		case CustomMsgTypes::SignalServerDisconnect:
		{
			std::cout << "[ " << client->GetID() << " ]: Disconnected" << std::endl;
			
			// Disconnect Client
			client->Disconnect();

			break;
		}
	}
}

//Tiny::net::connection<CustomMsgTypes>& CustomServer::GetClientRef(uint32_t ID)
//{
//	for (auto& client : m_deqConnections)
//	{
//		if (client->GetID() == ID)
//		{
//			return *client;
//		}
//	}
//	T_ASSERT(false, "Could Not found a Client with that ID.!");
//}

//void CustomServer::MatchMaking(uint32_t seeker_ID)
//{
//	std::pair<uint32_t, uint32_t> _pair;
//	_pair.first = seeker_ID;
//	for (auto& client : m_deqConnections)
//	{
//		if (client->GetID() == seeker_ID)
//		{
//			for (auto& [one, two] : m_InMatchClientsID)
//			{
//				if (seeker_ID != one || seeker_ID != two)
//				{
//					auto& msg = Tiny::net::message<CustomMsgTypes>();
//					msg.header.id = CustomMsgTypes::MatchFound;
//					msg << _pair.second;
//					client->Send(msg);
//				}
//			}
//		}
//		/*else if (client->GetID() == _pair.second)
//		{
//			auto& msg = Tiny::net::message<CustomMsgTypes>();
//			msg.header.id = CustomMsgTypes::MatchFound;
//			msg << _pair.first;
//			client->Send(msg);
//		}*/
//	}
//}

//
//else
//			{
//			auto& msg = Tiny::net::message<CustomMsgTypes>();
//			msg.header.id = CustomMsgTypes::LookingForMatch;
//			client->Send(msg);
//			}
//
//			/*std::cout << "[" << client->GetID() << "]: Request Match Making.\n";
//
//			if (m_deqConnections.size() > 2)
//			{
//				MatchMaking(client->GetID());
//			}
//			else
//			{
//				Tiny::net::message<CustomMsgTypes> msg;
//				msg.header.id = CustomMsgTypes::MatchNotFound;
//				client->Send(msg);
//			}*/