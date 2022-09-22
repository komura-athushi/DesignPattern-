#pragma once

class Actor;
class Observer;

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
	Observer* m_makeSoundEngine = nullptr;
	Observer* m_achievement = nullptr;
};

