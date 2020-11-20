#include "Scene.h"

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "ImGui/imgui.h"


Scene::Scene()
	: main_cam((float)12 / 7)
{

}

Scene::~Scene()
{

}

void Scene::OnAttach()
{
	m_Board.Start();
	// Set current player Randomly
	m_CurrentPlayer = (Tiny::Random::IntRange(0,2)) == 0 ? Player::PLAYER_1 : Player::PLAYER_2;
}

void Scene::OnUpdate(Tiny::Timestep dt)
{
	// Cam Update 
	/*main_cam.OnUpdate(dt);*/

	// Update Entities
	m_Board.Update(dt.GetSeconds());
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BoardSmallThingy[i][j].Update(dt.GetSeconds());
		}
	}

	for (auto& block : m_Blocks)
		block.Update(dt.GetSeconds());
	

	// OnRender ->  Entities
	Tiny::RenderCommand::SetClearColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
	Tiny::RenderCommand::Clear();
	Tiny::Renderer2D::SceneBegin(main_cam.GetCamera());
	// Render Board
	m_Board.OnRender();
	// Render Board Clickers
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			BoardSmallThingy[i][j].OnRender();
		}
	}
	// Render Blocks
	for (auto& block : m_Blocks)
		block.OnRender();
	Tiny::Renderer2D::SceneEnd();
	Tiny::RenderCommand::Shutdown();

	

}

void Scene::OnEvent(Tiny::Event& e)
{
	main_cam.OnEvent(e);
	Tiny::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Tiny::KeyPressedEvent>(T_BIND_EVENT_FN(&Scene::OnKeyPressed));
	dispatcher.Dispatch<Tiny::MouseButtonReleasedEvent>(T_BIND_EVENT_FN(&Scene::OnMousePressed));
}

void Scene::OnImGuiRender()
{
	/*ImGui::Begin("Board Ref");
	for (int i = 0; i < 3; i++)
	{
		std::string temp = "";
		for (int j = 0; j < 3; j++)
		{
			switch (m_Board_Blocks[i][j].GetType())
			{
			case BlockType::NONE:
			{
				temp += "X";
				break;
			}
			case BlockType::BLACK:
			{
				temp += "B";
				break;
			}
			case BlockType::WHITE:
			{
				temp += "W";
				break;
			}
			}
		}
		ImGui::Text(temp.data());
	}
	ImGui::End();*/
	ImGui::Begin("Current Board Player");
	switch (m_CurrentPlayer)
	{
	case Player::NONE:
	{
		ImGui::Text("None");
		break;
	}
	case Player::PLAYER_1:
	{
		ImGui::Text("Player 1");
		break;
	}
	case Player::PLAYER_2:
	{
		ImGui::Text("Player 2");
		break;
	}
	case Player::AI:
	{
		ImGui::Text("AI");
		break;
	}
	}
	std::string temp = "Moves: " + std::to_string(m_MoveCount);
	ImGui::Text(temp.data());
	ImGui::End();
}

bool Scene::OnKeyPressed(Tiny::KeyPressedEvent& event)
{/*
	switch (event.GetKeyCode())
	{
	case Tiny::KeyCode::KP1:
	{
		int32_t index = 0;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(0, 0, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}

		break;
	}
	case Tiny::KeyCode::KP2:
	{
		int32_t index = 1;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(1, 0, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP3:
	{
		int32_t index = 2;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(2, 0, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP4:
	{
		int32_t index = 3;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(0, 1, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP5:
	{
		int32_t index = 4;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(1, 1, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP6:
	{
		int32_t index = 5;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(2, 1, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP7:
	{
		int32_t index = 6;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(0, 2, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP8:
	{
		int32_t index = 7;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(1, 2, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	case Tiny::KeyCode::KP9:
	{
		int32_t index = 8;
		if (ValidMoveCheck(index))
		{
			m_Blocks.push_back(Block(
				m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
				index));
			CheckMove(2, 2, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
			ChangePlayer();
		}
		break;
	}
	}
	UpdateBoardRef();*/
	return false;
}

bool Scene::OnMousePressed(Tiny::MouseButtonReleasedEvent event)
{
	if (event.GetMouseButton() == Tiny::MouseCode::Button1)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (CheckCursorClickOnObject(BoardSmallThingy[i][j]))
				{
					int32_t index = BoardSmallThingy[i][j].GetIndex();
					if (ValidMoveCheck(index))
					{
						m_Blocks.push_back(Block(
							m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK,
							index));
						CheckMove(i, j, m_CurrentPlayer == Player::PLAYER_1 ? BlockType::WHITE : BlockType::BLACK);
						ChangePlayer();
					}
				}
			}
		}
	}
	return false;
}

bool Scene::ValidMoveCheck(int32_t index)
{
	for (auto& block : m_Blocks)
	{
		if (index == block.GetIndex())
		{
			return false;
		}
	}
	return true;
}

void Scene::ChangePlayer()
{
	switch (m_CurrentPlayer)
	{
	case Player::PLAYER_1:
	{
		m_CurrentPlayer = Player::PLAYER_2;
		break;
	}
	case Player::PLAYER_2:
	{
		m_CurrentPlayer = Player::PLAYER_1;
		break;
	}
	}
}

void Scene::UpdateBoardRef()
{

	for (auto& block : m_Blocks)
	{
		switch (block.GetIndex())
		{
		case 0:
			BoardRef[0][0] = block.GetType();
			break;
		case 1:
			BoardRef[1][0] = block.GetType();
			break;
		case 2:
			BoardRef[2][0] = block.GetType();
			break;
		case 3:
			BoardRef[0][1] = block.GetType();
			break;
		case 4:
			BoardRef[1][1] = block.GetType();
			break;
		case 5:
			BoardRef[2][1] = block.GetType();
			break;
		case 6:
			BoardRef[0][2] = block.GetType();
			break;
		case 7:
			BoardRef[1][2] = block.GetType();
			break;
		case 8:
			BoardRef[2][2] = block.GetType();
			break;
		}
	}

	/*for (int i = 0; i < 3; i++)
		T_INFO("{0},{1},{2}", BoardRef[0][i], BoardRef[1][i], BoardRef[2][i]);*/

	//for (int i = 0; i < 24; i += 3)
	//{
	//	/*if (m_Blocks[states[i]].GetType() == BlockType::BLACK &&
	//		m_Blocks[states[i + 1]].GetType() == BlockType::BLACK &&
	//		m_Blocks[states[i + 2]].GetType() == BlockType::BLACK)
	//	{
	//		T_INFO("Black wins");
	//	}*/
	//	bool test_1 = false;
	//	bool test_2 = false;
	//	bool test_3 = false;



	//	for (auto& block : m_Blocks)
	//	{
	//		if (block.GetIndex() == states[i])
	//			if (block.GetType() == BlockType::WHITE)
	//				test_1 = true;

	//		if (block.GetIndex() == states[i + 1])
	//			if (block.GetType() == BlockType::WHITE)
	//				test_1 = true;
	//		if (block.GetIndex() == states[i + 2])
	//			if (block.GetType() == BlockType::WHITE)
	//				test_1 = true;
	//	}
	//	if ( test_1 && test_2 && test_2)
	//	{
	//		T_INFO("White wins");
	//	}
	//}
	
}

void Scene::CheckMove(int x, int y, BlockType s)
{
	int n = 3;

	if (BoardRef[x][y] == BlockType::NONE) {
		BoardRef[x][y] = s;
	}

	m_MoveCount++;

	//check end conditions
	//check col
	for (int i = 0; i < n; i++) {
		if (BoardRef[x][i] != s)
			break;
		if (i == n - 1) {
			//report win for s
			GameOver(s);
		}
	}

	//check row
	for (int i = 0; i < n; i++) {
		if (BoardRef[i][y] != s)
			break;
		if (i == n - 1) {
			//report win for s
			GameOver(s);
		}
	}

	//check diag
	if (x == y) {
		//we're on a diagonal
		for (int i = 0; i < n; i++) {
			if (BoardRef[i][i] != s)
				break;
			if (i == n - 1) {
				//report win for s
				GameOver(s);
			}
		}
	}

	//check anti diag (thanks rampion)
	if (x + y == n - 1) {
		for (int i = 0; i < n; i++) {
			if (BoardRef[i][(n - 1) - i] != s)
				break;
			if (i == n - 1) {
				//report win for s
				GameOver(s);
			}
		}
	}
	//check draw
	if (m_MoveCount == (pow(n, 2) - 1)) {
		//report draw
		GameOver();
	}
}

void Scene::GameOver(BlockType winner)
{
	switch (winner)
	{
	case BlockType::BLACK:
	{
		T_INFO("BLACK WON");
		break;
	}
	case BlockType::WHITE:
	{
		T_INFO("WHITE WON");
		break;
	}
	}
	ResetScene();
}

void Scene::GameOver()
{
	ResetScene();
	T_INFO("DRAW");
}

void Scene::ResetScene()
{
	m_Blocks.clear();
	m_MoveCount = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			BoardRef[i][j] = BlockType::NONE;
}

bool Scene::CheckCursorClickOnObject(Block& block)
{
	Tiny::Application& app = Tiny::Application::Get();
	glm::vec2 ScreenResolution = { app.GetWindow().GetWidth(), app.GetWindow().GetHeight() };
	glm::vec2 MousePos = Tiny::Input::GetMousePosition();

	glm::mat4 ProjecInverse = glm::inverse(main_cam.GetCamera().GetProjectionViewMatrix());
	glm::vec4 in;

	float winZ = 1.0;
	in[0] = (2.0f * ((float)(MousePos.x - 0.0f) / (ScreenResolution.x - 0.0f))) - 1.0f,
		in[1] = 1.0f - (2.0f * ((float)(MousePos.y - 0) / (ScreenResolution.y - 0)));
	in[2] = 2.0 * winZ - 1.0;
	in[3] = 1.0;


	glm::vec4 CursorWorldSpacePos = in * (ProjecInverse);

	CursorWorldSpacePos.w = 1.0 / CursorWorldSpacePos.w;

	CursorWorldSpacePos.x *= CursorWorldSpacePos.w;
	CursorWorldSpacePos.y *= CursorWorldSpacePos.w;
	CursorWorldSpacePos.z *= CursorWorldSpacePos.w;

	//A typical Quad Vertices
	glm::vec4 QuadVertices[] = {
		{-0.5,-0.5,0.0f,1.0f},
		{ 0.5,-0.5,0.0f,1.0f},
		{ 0.5, 0.5,0.0f,1.0f},
		{-0.5, 0.5,0.0f,1.0f},
	};

	//The Block vertices
	glm::vec4 playerQuadTransVerticePos[4];

	for (int i = 0; i < 4; i++)
	{
		glm::mat4 T = glm::translate(glm::mat4(1.0f), block.GetPosition());
		glm::mat4 R = glm::rotate(glm::mat4(1.0f), glm::radians(block.GetRotation()), glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 S = glm::scale(glm::mat4(1.0f), block.GetScale());
		playerQuadTransVerticePos[i] = T * R * S * QuadVertices[i];
		//T_INFO("{0} : ({1},{2},{3},{4})", i, playerQuadTransVerticePos[i].x, playerQuadTransVerticePos[i].y, playerQuadTransVerticePos[i].z, playerQuadTransVerticePos[i].w);
	}

	// Check 1 half of block rectangle 
	if (Tiny::DebugPhysics::PointInTri({ CursorWorldSpacePos.x,CursorWorldSpacePos.y },
		glm::vec2(playerQuadTransVerticePos[0].x, playerQuadTransVerticePos[0].y),
		glm::vec2(playerQuadTransVerticePos[1].x, playerQuadTransVerticePos[1].y),
		glm::vec2(playerQuadTransVerticePos[2].x, playerQuadTransVerticePos[2].y))
		||
		Tiny::DebugPhysics::PointInTri({ CursorWorldSpacePos.x,CursorWorldSpacePos.y },
			glm::vec2(playerQuadTransVerticePos[2].x, playerQuadTransVerticePos[2].y),
			glm::vec2(playerQuadTransVerticePos[3].x, playerQuadTransVerticePos[3].y),
			glm::vec2(playerQuadTransVerticePos[0].x, playerQuadTransVerticePos[0].y))
		)
	{
		return true;
	}

	return false;
}

