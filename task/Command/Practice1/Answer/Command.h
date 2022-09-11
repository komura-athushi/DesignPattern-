#pragma once

#include "Actor.h"

class Command
{
public:
	~Command(){}
	virtual void Execute(Actor* actor) = 0;
};

class UpCommand : public Command
{
public:
	~UpCommand(){}
	void Execute(Actor* actor)
	{
		actor->MoveUp();
	}
};

class DownCommand : public Command
{
public:
	~DownCommand(){}
	void Execute(Actor* actor)
	{
		actor->MoveDown();
	}
};

class ResetCommand : public Command
{
public:
	~ResetCommand(){}
	void Execute(Actor* actor)
	{
		actor->ResetPosition();
	}
};

