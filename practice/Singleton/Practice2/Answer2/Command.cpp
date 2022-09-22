#include "stdafx.h"
#include "Command.h"

#include "Actor.h"

void MoveActorCommand::Execute() 
{
	m_beforePosition = m_actor->GetPosition();
	m_actor->SetPosition(m_position);
}
void MoveActorCommand::Undo() 
{
	m_actor->SetPosition(m_beforePosition);
}
