#pragma once

#include "GameObject.h"

#include "Actor.h"
#include "Enemy.h"

class Game : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void Draw() override;
private:
	bool		m_isGameOver = false;
	bool		m_isGameClear = false;
	Actor*		m_actor = nullptr;
	Enemy*		m_enemy = nullptr;
	int			m_count = 0;
};

