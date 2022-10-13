#include "stdafx.h"
#include "Game.h"

#include "Actor.h"
#include "Background.h"


bool Game::Start()
{
	m_actor = NewGO<Actor>(0);
	m_background = NewGO<Background>(0);
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	
}