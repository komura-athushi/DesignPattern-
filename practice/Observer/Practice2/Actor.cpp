#include "stdafx.h"
#include "Actor.h"

bool Actor::Start()
{
	return true;
}

void Actor::Update()
{
	if (g_keyboard->IsKeyTrigger(Keyboard::A))
	{
		Notify(enEvent_PressAKey);
	}
	if (g_keyboard->IsKeyTrigger(Keyboard::B))
	{
		Notify(enEvent_PressBKey);
	}
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		Notify(enEvent_PressEnter);
	}
}
