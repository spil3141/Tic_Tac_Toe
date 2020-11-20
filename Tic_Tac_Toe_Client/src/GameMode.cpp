#include "GameMode.h"

#include "ImGui/imgui.h"
#include <memory.h>

GameMode::GameMode()
	: e_CurrentGameState(GameState::MENU)
{
}

GameMode::~GameMode()
{
	if (p_Scene != nullptr)
		delete p_Scene;

	if (p_PVPScene != nullptr)
		delete p_PVPScene;
}

void GameMode::OnAttach()
{
	switch (e_CurrentGameState)
	{
	case GameState::PLAYING:
	{
		p_Scene->OnAttach();
		break;
	}
	case GameState::PVPING:
	{
		p_PVPScene->OnAttach();
		break;
	}
	}
}

void GameMode::OnDetach()
{

}

void GameMode::OnUpdate(Tiny::Timestep dt)
{
	switch (e_CurrentGameState)
	{
	case GameState::MENU:
	{
		Tiny::RenderCommand::Clear();
		break;
	}
	case GameState::PLAYING:
	{
		p_Scene->OnUpdate(dt);
		break;
	}
	case GameState::PVPING:
	{
		p_PVPScene->OnUpdate(dt);
		break;
	}
	}
}

void GameMode::OnEvent(Tiny::Event& e)
{
	switch (e_CurrentGameState)
	{
	case GameState::PLAYING:
	{
		p_Scene->OnEvent(e);
		break;
	}
	case GameState::PVPING:
	{
		p_PVPScene->OnEvent(e);
		break;
	}
	}

}

void GameMode::OnImGuiRender()
{
	ImGui::Begin("Menu");
	bool BTN_Menu = ImGui::Button("Menu");
	if (BTN_Menu)
	{
		if (p_Scene != nullptr)
		{
			delete p_Scene;
			p_Scene = nullptr;
		}
		if (p_PVPScene != nullptr)
		{
			delete p_PVPScene;
			p_PVPScene = nullptr;
		}
		e_CurrentGameState = GameState::MENU;
	}
	bool BTN_Play = ImGui::Button("Play");
	if (BTN_Play)
	{
		if (p_Scene != nullptr)
			delete p_Scene;
		p_Scene = new Scene();
		
		//Game mode has just one attach
		p_Scene->OnAttach();
		e_CurrentGameState = GameState::PLAYING;
	}
	bool BTN_PVPING = ImGui::Button("PVP");
	if (BTN_PVPING && e_CurrentGameState != GameState::PLAYING)
	{
		// Set GameMode
		e_CurrentGameState = GameState::PVPING;
		
		if (p_PVPScene != nullptr)
		{
			delete p_PVPScene;
			
		}
		
		// Create new PVP Scene
		p_PVPScene = new PVPScene();

		// Initialize Scene
		p_PVPScene->OnAttach();
	}
	bool BTN_Exit = ImGui::Button("Exit");
	if (BTN_Exit)
	{
		Tiny::Application::Get().ExitApplication();
	}
	ImGui::End();


	switch (e_CurrentGameState)
	{
	case GameState::PLAYING:
	{
		p_Scene->OnImGuiRender();
		break;
	}
	case GameState::PVPING:
	{
		p_PVPScene->OnImGuiRender();
		break;
	}
	}
}
