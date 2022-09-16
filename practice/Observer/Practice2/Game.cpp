#include "stdafx.h"
#include "Game.h"

#include "Observer.h"
#include "Actor.h"


bool Game::Start()
{
	m_makeSoundEngine = new MakeSoundEngine();
	m_achievement = new Achievement();
	m_actor = NewGO<Actor>(0);
	m_actor->AddObserver(m_makeSoundEngine);
	m_actor->AddObserver(m_achievement);


	g_camera3D->SetPosition(Vector3(-100.f, 100.f, -100.f));
	g_camera3D->SetTarget(Vector3(0.f, 50.f, 0.f));
	g_camera3D->Update();
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	
}