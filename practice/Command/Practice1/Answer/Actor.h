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
	void MoveUp();
	void MoveDown();
	void ResetPosition();
private:
	SpriteRender m_spriteRender;
	Vector3 m_startPosition;
	Vector3 m_position;
	Command* m_buttonUp;
	Command* m_buttonDown;
	Command* m_buttonEnter;
};

