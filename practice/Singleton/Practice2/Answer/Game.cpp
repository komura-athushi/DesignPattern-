#include "Game.h"

namespace
{
	std::string GAME_OVER = "GAME_OVER!!!!!!";
	std::string GAME_CLEAR = "GAME_CLEAR!!!!!!!";
}

void Game::Start()
{
	m_actor = GameObject::NewGO<Actor>();
	m_enemy = GameObject::NewGO<Enemy>();

	m_enemy->SetActor(m_actor);
}

void Game::Update()
{
	if (m_isGameOver || m_isGameClear)
	{
		return;
	}
	m_count++;

	if (m_count >= 70)
	{
		m_isGameClear = true;
		DeleteGO(m_actor);
		DeleteGO(m_enemy);
	}
	

	if (m_actor->GetX() == m_enemy->GetX() &&
		m_actor->GetY() == m_enemy->GetY())
	{
		m_isGameOver = true;
		DeleteGO(m_actor);
		DeleteGO(m_enemy);
		return;
	}
}

void Game::Draw()
{
	if (!m_isGameOver && !m_isGameClear)
	{
		return;
	}

	if (m_isGameOver)
	{
		for (int i = 0; i < GAME_OVER.size(); i++)
		{
			GetGraphicsEngine().Draw(i + 2, 2, GAME_OVER[i]);
		}
		return;
	}
	for (int i = 0; i < GAME_CLEAR.size(); i++)
	{
		GetGraphicsEngine().Draw(i + 2, 2, GAME_CLEAR[i]);
	}
}
