#pragma once

#include "Command.h"

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
	std::unique_ptr<Command> HandleInput();
	void UndoAndCancel();
	void DeleteCommand();
private:
	SpriteRender m_spriteRender;
	Vector3 m_startPosition;
	Vector3 m_position;
	std::vector<std::unique_ptr<Command>> m_commandVector;
	int m_commandIndex = 0;
	FontRender m_fontRender;
};

