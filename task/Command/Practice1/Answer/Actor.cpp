#include "stdafx.h"
#include "Actor.h"

#include "Command.h"


bool Actor::Start()
{
	m_spriteRender.Init("Assets/sprite/actor.dds",200,200);
	m_spriteRender.SetPosition(m_startPosition);
	m_position = m_startPosition;

	m_buttonUp = new UpCommand();
	m_buttonDown = new DownCommand();
	m_buttonEnter = new ResetCommand();
	return true;
}

void Actor::Update()
{
	if (g_keyboard->IsKeyDown(Keyboard::Up))
	{
		//MoveUp();
		m_buttonUp->Execute(this);
	}
	if (g_keyboard->IsKeyDown(Keyboard::Down))
	{
		//MoveDown();
		m_buttonDown->Execute(this);
	}
	
	if (g_keyboard->IsKeyDown(Keyboard::Enter))
	{
		//ResetPosition();
		m_buttonEnter->Execute(this);
	}

	m_spriteRender.SetPosition(m_position);
	m_spriteRender.Update();
}

void Actor::MoveUp()
{
	m_position.y += 30.f;
}

void Actor::MoveDown()
{
	m_position.y -= 30.f;
}

void Actor::ResetPosition()
{
	m_position = m_startPosition;
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
