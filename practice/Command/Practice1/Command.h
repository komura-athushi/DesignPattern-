#pragma once

#include "Actor.h"

class Command
{
public:
	virtual ~Command() {}
	
};

class UpCommand : public Command
{

};

class DownCommand : public Command
{

};

class ResetCommand : public Command
{

};

