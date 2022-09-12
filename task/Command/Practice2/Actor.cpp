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
	//上キーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Up))
	{
		//上に移動する。
		
	}
	//下キーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Down))
	{
		//下に移動する。
		
	}
	//Enterキーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		//座標をリセットする。
		
	}
	return nullptr;
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}