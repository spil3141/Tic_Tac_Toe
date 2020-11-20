#include "Block.h"

#include "glm/glm.hpp"


static glm::vec3 s_Valid_Block_Pos[9] =
{
	{-0.344f,  0.344f,0.1f},    {0.0f,0.344f,0.1f},   {0.344f,0.344f,0.1f},// First Row
	{-0.344f,    0.0f,0.1f},    {0.0f,0.0f,0.1f},   {0.344f,0.0f,0.1f},// First Row
	{-0.344f,-0.344f,0.1f},  {0.0f,-0.344f,0.1f},   {0.344f,-0.344f,0.1f},// First Row
};

//glm::vec3* Block::GetValidBlockPOs()
//{
//	return s_Valid_Block_Pos;
//}


Block::Block(BlockType type, int32_t index)
	: m_Type(type),m_Index(index)
{
	//Set Transform
	if (m_Index != -111 && m_Index <= 8 && m_Index >= 0)
		SetPosition(s_Valid_Block_Pos[m_Index]);
	m_Scale = { 0.3f,0.3f,0.3f };


	switch (type)
	{
	case BlockType::BLACK:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_B.png");
		break;
	}
	case BlockType::WHITE:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_W.png");
		break;
	}
	default:
		T_ERROR("Block Type was not assigned.");
		T_ASSERT(!m_CanBeRender, "Block Type was not assigned.");
		break;
	}
}

Block::Block()
	: m_Index(-111)
{
	m_Type = BlockType::NONE;
	//Set Transform
	m_Position = { 0.0f,0.0f,0.1f };
	m_Scale = { 0.3f,0.3f,0.3f };
}

Block::Block(BlockType type, int32_t index, float zvalue)
	: m_Type(type), m_Index(index)
{
	//Set Transform
	if (m_Index != -111 && m_Index <= 8 && m_Index >= 0)
		SetPosition(s_Valid_Block_Pos[m_Index]);
	m_Position.z = zvalue;
	m_Scale = { 0.3f,0.3f,0.3f };


	switch (type)
	{
	case BlockType::NONE:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Block_BG.png");
		break;
	}
	case BlockType::BLACK:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_B.png");
		break;
	}
	case BlockType::WHITE:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_W.png");
		break;
	}
	default:
		T_ERROR("Block Type was not assigned.");
		T_ASSERT(!m_CanBeRender, "Block Type was not assigned.");
		break;
	}
}

Block::~Block()
{

}

void Block::Start()
{
}

void Block::Update(float dt)
{
	/*if(Tiny::Input::IsKeyPressed(Tiny::KeyCode::Space))
	{
		SetPosition(GetPosition() + glm::vec3(1.0f, 1.0f, 0.0f) * dt);
	}*/

	/*if (m_Index != -111 && m_Index <= 8 && m_Index >= 0)
		SetPosition(s_Valid_Block_Pos[m_Index]);

	if (m_Type != BlockType::NONE && m_CanBeRender == false)
	{
		m_CanBeRender = true;
	}*/
}

void Block::OnRender()
{
	//if(m_CanBeRender && m_Texture != nullptr)
	Tiny::Renderer2D::DrawQuad(GetPosition(), GetRotation(), GetScale(), m_Texture);
}

void Block::SetType(BlockType type)
{
	m_Type = type;

	/*m_Type = type;
	switch (type)
	{
	case BlockType::BLACK:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_B.png");
		break;
	}
	case BlockType::WHITE:
	{
		m_Texture = Tiny::Texture2D::Create("res/Textures/Tac_Tic_Toe_Block_W.png");
		break;
	}
	default:
		T_ERROR("Block Type was not assigned.");
		T_ASSERT(!m_CanBeRender, "Block Type was not assigned.");
		break;
	}*/
}