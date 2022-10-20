#pragma once

#include "TimeMeasured.h"

class GameLoop
{
public:
	GameLoop(){}
	void Loop();
	/// <summary>
	/// ループ開始直後の経過時間を計測します。
	/// </summary>
	void SetPrevious()
	{
		m_previous = CurrentTime();
		m_gameTime.BeginMeasurement();
	}
private:
	/// <summary>
	/// フレームの最初に行う処理。
	/// </summary>
	void Start()
	{
		m_startTime = CurrentTime();
		K2Engine::GetInstance()->Start();
	}
	/// <summary>
	/// 更新処理。
	/// </summary>
	void Update()
	{
		K2Engine::GetInstance()->Update();
		m_gameTime.CountUpdateProcess();
		m_fpsRender.SetPosition(Vector3(-950.0f, 520.0f, 1.0f));
		m_fpsRender2.SetPosition(Vector3(-950.0f, 480.0f, 1.0f));
	}
	/// <summary>
	/// 描画処理。
	/// </summary>
	void Render()
	{
		K2Engine::GetInstance()->Render();
		float time = g_gameTime->GetFrameDeltaTime();
		float time2 = m_gameTime.GetFrameDeltaTime();

		wchar_t text[256];
		swprintf(text, L"描画処理FPS = %0.2f", 1.0f / time);
		m_fpsRender.SetText(text);
		wchar_t text2[256];
		swprintf(text2, L"更新処理FPS = %0.2f", 1.0f / time2);
		m_fpsRender2.SetText(text2);

		m_fpsRender.Draw(g_graphicsEngine->GetRenderContext());
		m_fpsRender2.Draw(g_graphicsEngine->GetRenderContext());
	}
	/// <summary>
	/// FPS確定。
	/// </summary>
	void End()
	{
		K2Engine::GetInstance()->End();
	}
	/// <summary>
	/// プログラム実行から何秒経過したかを返す。
	/// </summary>
	/// <returns>経過した時間(秒)</returns>
	const float CurrentTime() const
	{
		return clock() / 1000.0f;
	}
	/// <summary>
	/// 一定時間プログラムを停止させる。
	/// </summary>
	/// <param name="time">停止させる時間(秒)</param>
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