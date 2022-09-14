#pragma once

class LeverRender;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	LeverRender* m_leverRender = nullptr;
};

