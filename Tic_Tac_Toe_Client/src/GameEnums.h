#pragma once

enum class BlockType
{
	NONE = 0,
	// Black is other. 
	BLACK = 1,
	//white is HOME
	WHITE = 2
};

enum class Player
{
	NONE = 0,
	PLAYER_1, // Always BlACK
	PLAYER_2, // Always White
	AI
};