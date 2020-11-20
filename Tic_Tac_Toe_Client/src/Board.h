#pragma once

#include "Tiny.h"

class Board : public Tiny::DebugEntity
{
public:
	Board();
	~Board();
	void Start() override;
	void Update(float dt) override;
	void OnRender();

private:

	Tiny::Ref<Tiny::Texture2D> m_Texture;
};

