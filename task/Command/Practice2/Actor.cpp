#include "stdafx.h"
#include "Actor.h"

#include "Command.h"

bool Actor::Start()
{
	m_spriteRender.Init("Assets/sprite/actor.dds",200,200);
	m_spriteRender.SetPosition(m_startPosition);
	m_position = m_startPosition;
	
	return true;
}

void Actor::Update()
{
	

	m_fontRender.SetText(std::to_wstring(m_position.y).c_str());
	m_spriteRender.SetPosition(m_position);
	m_spriteRender.Update();
}

Command* Actor::HandleInput()
{
	//��L�[�������ꂽ��B
	if (g_keyboard->IsKeyTrigger(Keyboard::Up))
	{
		//��Ɉړ�����B
		
	}
	//���L�[�������ꂽ��B
	if (g_keyboard->IsKeyTrigger(Keyboard::Down))
	{
		//���Ɉړ�����B
		
	}
	//Enter�L�[�������ꂽ��B
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		//���W�����Z�b�g����B
		
	}
	return nullptr;
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}