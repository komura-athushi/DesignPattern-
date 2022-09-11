#include "stdafx.h"
#include "Actor.h"


bool Actor::Start()
{
	m_spriteRender.Init("Assets/sprite/actor.dds",200,200);
	m_spriteRender.SetPosition(m_startPosition);
	m_position = m_startPosition;

	return true;
}

void Actor::Update()
{
	//��L�[�������ꂽ��B
	if (g_keyboard->IsKeyDown(Keyboard::Up))
	{
		//��Ɉړ�����B
		MoveUp();
	}
	//���L�[�������ꂽ��B
	if (g_keyboard->IsKeyDown(Keyboard::Down))
	{
		//���Ɉړ�����B
		MoveDown();
	}
	//Enter�L�[�������ꂽ��B
	if (g_keyboard->IsKeyDown(Keyboard::Enter))
	{
		//���W�����Z�b�g����B
		ResetPosition();
	}

	m_spriteRender.SetPosition(m_position);
	m_spriteRender.Update();
}

void Actor::MoveUp()
{
	m_position.y += 100.f;
}

void Actor::MoveDown()
{
	m_position.y -= 100.f;
}

void Actor::ResetPosition()
{
	m_position = m_startPosition;
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}