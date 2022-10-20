#include "stdafx.h"
#include "GameLoop.h"

namespace
{
	//120FPSの際の、1フレームあたりの処理時間。
	const float MS_PER_UPDATE = 0.00833f;
}

void GameLoop::Loop()
{
	float currentTime = CurrentTime();
	//前フレームの処理時間。
	float elapsedTime = currentTime - m_previous;
	m_previous = currentTime;

	m_lag += elapsedTime;

	//フレーム開始時の処理。
	Start();
	//実時間のズレ分だけ更新処理を行う。
	while (m_lag >= MS_PER_UPDATE)
	{
		//更新処理。
		Update();
		m_lag -= MS_PER_UPDATE;
	}

	//描画処理。
	Render();

	//FPS確定。
	End();
}