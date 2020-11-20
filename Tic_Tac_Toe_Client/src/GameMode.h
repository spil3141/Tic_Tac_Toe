#pragma once
#include "Tiny.h"

#include "Scene.h"
#include "PVPScene.h"

class GameMode : public Tiny::Layer
{
public:
	GameMode();
	~GameMode();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(Tiny::Timestep dt) override;
	virtual void OnEvent(Tiny::Event& e) override;
	virtual void OnImGuiRender() override;

private:
	Scene* p_Scene = nullptr;
	PVPScene* p_PVPScene = nullptr;

	enum class GameState {
		MENU = 0,
		PLAYING = 1,
		PVPING = 2
		
	};

	GameState e_CurrentGameState;
};

