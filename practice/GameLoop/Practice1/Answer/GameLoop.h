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
	}
	/// <summary>
	/// FPS描画。
	/// </summary>
	void End()
	{
		float endTime = CurrentTime();
		printf("fps  %f\n", 1.0f / (endTime - m_startTime));
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
};

