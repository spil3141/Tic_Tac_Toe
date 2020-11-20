#pragma once
#include "Tiny.h"


#include "Board.h"
#include "Block.h"
#include "GameEnums.h"
#include <vector>
#include <array>


class Scene
{
public:
	Scene();
	~Scene();

	void OnAttach();
	void OnUpdate(Tiny::Timestep dt);
	void OnEvent(Tiny::Event& e);
	void OnImGuiRender();

private:
	bool OnKeyPressed(Tiny::KeyPressedEvent& event);
	bool OnMousePressed(Tiny::MouseButtonReleasedEvent event);
	bool ValidMoveCheck(int32_t index);
	void ChangePlayer();
	void UpdateBoardRef();
	void CheckMove(int x, int y, BlockType s);
	void GameOver(BlockType winner);
	void GameOver(); // Draw
	void ResetScene();

	bool CheckCursorClickOnObject(Block& block);


private:
	Board m_Board;
	Tiny::OrthoCameraController main_cam;


	// Gameplay Variables
	std::vector<Block> m_Blocks;
	BlockType BoardRef[3][3] = {
		{BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{BlockType::NONE, BlockType::NONE, BlockType::NONE},
		{BlockType::NONE, BlockType::NONE, BlockType::NONE}};
	Player m_CurrentPlayer = Player::NONE;
	int m_MoveCount = 0;



	//TEMP 
	Block BoardSmallThingy[3][3] = {
		{Block(BlockType::NONE,0,0.05f), Block(BlockType::NONE,1,0.05f), Block(BlockType::NONE,2,0.05f)},
		{Block(BlockType::NONE,3,0.05f), Block(BlockType::NONE,4,0.05f), Block(BlockType::NONE,5,0.05f)},
		{Block(BlockType::NONE,6,0.05f), Block(BlockType::NONE,7,0.05f), Block(BlockType::NONE,8,0.05f)} };

};

