#include "stdafx.h"
#include "GameLoop.h"

namespace
{
	const float MS_PER_UPDATE = 0.0125f;
}

void GameLoop::Loop()
{
	float currentTime = CurrentTime();
	//�O�t���[���̏������ԁB
	float elapsedTime = currentTime - m_previous;
	m_previous = currentTime;

	m_lag += elapsedTime;

	//�t���[���J�n���̏����B
	Start();
	while (m_lag >= MS_PER_UPDATE)
	{
		//�X�V�����B
		Update();
		m_lag -= MS_PER_UPDATE;
	}

	//�`�揈���B
	Render();

	//FPS�m��B
	End();
}