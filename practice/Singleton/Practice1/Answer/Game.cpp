#include "stdafx.h"
#include "Game.h"

#include "Configuration.h"


bool Game::Start()
{
	m_fontRender.SetText(Configuration::GetInstance()->GetSolutionConfiguration().c_str());
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}