#pragma once
class GameLoop
{
public:
	GameLoop(){}
	void Loop();

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
	}
	/// <summary>
	/// 描画処理。
	/// </summary>
	void Render()
	{
		K2Engine::GetInstance()->Render();
		float time = g_gameTime->GetFrameDeltaTime();
		wchar_t text[256];
		swprintf(text, L"FPS = %0.2f", 1.0f / time);
		m_fontRender.SetText(text);
		m_fontRender.SetPosition(Vector3(-950.0f, 520.0f, 1.0f));
		m_fontRender.Draw(g_graphicsEngine->GetRenderContext());
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
	FontRender		m_fontRender;
};

