#include "stdafx.h"
#include "Game.h"

#include "LeverRender.h"


bool Game::Start()
{
	m_leverRender = NewGO<LeverRender>(0);

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