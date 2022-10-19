#include "stdafx.h"
#include "GameLoop.h"

namespace
{
	const float MS_PER_UPDATE = 0.0125f;
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