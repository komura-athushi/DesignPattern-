#pragma once

class Actor;

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
	void Execute() override;
	void Undo() override;
private:
	Vector3 m_position;
	Vector3 m_beforePosition;
	Actor* m_actor;
};