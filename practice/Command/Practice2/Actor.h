#pragma once

class Command;

class Actor: public IGameObject
{
public:
	Actor(){}
	~Actor(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
public:
	const Vector3 GetPosition() const
	{
		return m_position;
	}
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
private:
	Command* HandleInput();
private:
	SpriteRender m_spriteRender;
	Vector3 m_startPosition;
	Vector3 m_position;
	FontRender m_fontRender;
};

