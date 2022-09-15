#include "stdafx.h"
#include "Game.h"

#include "World.h"


bool Game::Start()
{
	m_world = NewGO<World>(0);

	g_camera3D->SetPosition(Vector3(-100.f, 200.f, -100.f));
	g_camera3D->SetTarget(Vector3(0.f, 130.f, 0.f));
	g_camera3D->Update();
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	
}