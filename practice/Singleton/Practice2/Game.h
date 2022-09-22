#pragma once

#include "Actor.h"

class Actor;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	Actor* m_actor = nullptr;
};

