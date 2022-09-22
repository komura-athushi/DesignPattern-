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
	
private:
	
};