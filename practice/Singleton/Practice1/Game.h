#pragma once

class Configuration;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	FontRender		m_fontRender;
	Configuration* m_configuration;
};

