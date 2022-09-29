#pragma once

class Actor;
class Background;

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
	Background* m_background = nullptr;
};

