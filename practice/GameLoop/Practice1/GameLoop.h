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
	}
	/// <summary>
	/// FPS�`��B
	/// </summary>
	void End()
	{
		float endTime = CurrentTime();
		printf("fps  %f\n", 1.0f / (endTime - m_startTime));
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
};

