#pragma once
class GameLoop
{
public:
	GameLoop(){}
	void Loop();

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
	}
	/// <summary>
	/// �`�揈���B
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
	FontRender		m_fontRender;
};

