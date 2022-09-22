#include "stdafx.h"
#include "Game.h"

#include "Configuration.h"


bool Game::Start()
{
#ifdef _DEBUG
	m_configuration = new DebugConfiguration();
#endif
#ifdef _RELEASE
	m_configuration = new ReleaseConfiguration();
#endif

	m_fontRender.SetText(m_configuration->GetSolutionConfiguration().c_str());
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}