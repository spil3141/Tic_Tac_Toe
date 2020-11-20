#include "Board.h"

Board::Board()
	: m_Texture(Tiny::Texture2D::Create("res/Textures/Board.png"))
{
	m_Position = { 0.0f,0.0f,0.0f };
}


Board::~Board()
{
}

void Board::Start()
{
	
}

void Board::Update(float dt)
{

}

void Board::OnRender()
{
	Tiny::Renderer2D::DrawQuad(GetPosition(), GetRotation(), GetScale(), m_Texture);
}
