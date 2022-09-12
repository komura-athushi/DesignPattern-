#pragma once

#include "Actor.h"

class Command
{
public:
	virtual ~Command(){}
	virtual void Execute() = 0;
	virtual void Undo() = 0;
};

class MoveActorCommand : public Command
{
public:
	~MoveActorCommand() override {} 
	MoveActorCommand(const Vector3& position, Actor* actor)
	{
		m_position = position;
		m_actor = actor;
	}
	void Execute() override
	{
		m_beforePosition = m_actor->GetPosition();
		m_actor->SetPosition(m_position);
	}
	void Undo() override
	{
		m_actor->SetPosition(m_beforePosition);
	}
private:
	Vector3 m_position;
	Vector3 m_beforePosition;
	Actor* m_actor;
};