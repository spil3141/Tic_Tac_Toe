#include "CustomClient.h"

CustomClient::CustomClient()
{
}

CustomClient::~CustomClient()
{

}
//
////void CustomClient::PingServer()
////{
////	Tiny::net::message<CustomMsgTypes> msg;
////	msg.header.id = CustomMsgTypes::ServerPing;
////
////	// Caution with this...
////	std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();
////
////	msg << timeNow;
////	Send(msg);
////
////}
//
//void CustomClient::MessageAll()
//{
//	Tiny::net::message<CustomMsgTypes> msg;
//	msg.header.id = CustomMsgTypes::MessageAll;
//	Send(msg);
//}