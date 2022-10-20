#pragma once

#include "TimeMeasured.h"

class GameLoop
{
public:
	GameLoop(){}
	void Loop();
	/// <summary>
	/// ���[�v�J�n����̌o�ߎ��Ԃ��v�����܂��B
	/// </summary>
	void SetPrevious()
	{
		m_previous = CurrentTime();
		m_gameTime.BeginMeasurement();
	}
private:
	/// <summary>
	/// �t���[���̍ŏ��ɍs�������B
	/// </summary>
	void Start()
	{
		m_startTime = CurrentTime();
		K2Engine::GetInstance()->Start();
	}
	/// <summary>
	/// �X�V�����B
	/// </summary>
	void Update()
	{
		K2Engine::GetInstance()->Update();
		m_gameTime.CountUpdateProcess();
		m_fpsRender.SetPosition(Vector3(-950.0f, 520.0f, 1.0f));
		m_fpsRender2.SetPosition(Vector3(-950.0f, 480.0f, 1.0f));
	}
	/// <summary>
	/// �`�揈���B
	/// </summary>
	void Render()
	{
		K2Engine::GetInstance()->Render();
		float time = g_gameTime->GetFrameDeltaTime();
		float time2 = m_gameTime.GetFrameDeltaTime();

		wchar_t text[256];
		swprintf(text, L"�`�揈��FPS = %0.2f", 1.0f / time);
		m_fpsRender.SetText(text);
		wchar_t text2[256];
		swprintf(text2, L"�X�V����FPS = %0.2f", 1.0f / time2);
		m_fpsRender2.SetText(text2);

		m_fpsRender.Draw(g_graphicsEngine->GetRenderContext());
		m_fpsRender2.Draw(g_graphicsEngine->GetRenderContext());
	}
	/// <summary>
	/// FPS�m��B
	/// </summary>
	void End()
	{
		K2Engine::GetInstance()->End();
	}
	/// <summary>
	/// �v���O�������s���牽�b�o�߂�������Ԃ��B
	/// </summary>
	/// <returns>�o�߂�������(�b)</returns>
	const float CurrentTime() const
	{
		return clock() / 1000.0f;
	}
	/// <summary>
	/// ��莞�ԃv���O�������~������B
	/// </summary>
	/// <param name="time">��~�����鎞��(�b)</param>
	void Stop(const float time)
	{
		float startTime = CurrentTime();
		while (true)
		{
			if (CurrentTime() >= startTime + time)
			{
				break;
			}
		}
	}
private:
	float			m_startTime = 0.0f;
	float			m_previous = 0.0f;
	float			m_lag = 0.0f;
	FontRender		m_fpsRender;
	FontRender		m_fpsRender2;
	TimeMeasured	m_gameTime;
};