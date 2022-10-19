#pragma once
class TimeMeasured
{
public:
	void BeginMeasurement()
	{
		m_startTime = clock() / 1000.0f;
	}
	void CountUpdateProcess()
	{
		m_count += 1;
		m_frameDeltaTime = ((clock() / 1000.0f) - m_startTime) / static_cast<float>(m_count);
	}
	const float GetFrameDeltaTime() const
	{
		return m_frameDeltaTime;
	}
private:
	float				m_startTime = 0.0f;
	int					m_count = 0;
	float				m_frameDeltaTime = 1.f/60.f;
};

