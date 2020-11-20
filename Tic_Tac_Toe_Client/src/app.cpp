#include "Tiny.h"
#include "Tiny/Core/EntryPoint.h"

// Game Includes
#include "GameMode.h"

class GameApp : public Tiny::Application
{
public:
	GameApp()
	{
		PushLayer(new GameMode());
	};

	~GameApp()
	{
	};
};


Tiny::Application* Tiny::CreateApplication()
{
	return new GameApp();
}
