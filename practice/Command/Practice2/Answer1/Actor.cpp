#include "stdafx.h"
#include "Actor.h"

#include "Command.h"

bool Actor::Start()
{
	m_spriteRender.Init("Assets/sprite/actor.dds",200,200);
	m_spriteRender.SetPosition(m_startPosition);
	m_position = m_startPosition;
	m_command = new MoveActorCommand(m_position,this);
	return true;
}

void Actor::Update()
{
	auto newCommand = HandleInput();
	if (newCommand != nullptr)
	{
		delete m_command;
		m_command = newCommand;
		m_command->Execute();
	}
	if (g_keyboard->IsKeyDown(Keyboard::LeftControl) && g_keyboard->IsKeyTrigger(Keyboard::Z))
	{
		m_command->Undo();
	}
	if (g_keyboard->IsKeyDown(Keyboard::LeftControl) && g_keyboard->IsKeyTrigger(Keyboard::Y))
	{
		m_command->Execute();
	}

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
		Vector3 destPosition = m_position + Vector3(0.f, 100.f, 0.f);
		return  new MoveActorCommand(destPosition, this);
	}
	//下キーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Down))
	{
		//下に移動する。
		Vector3 destPosition = m_position + Vector3(0.f, -100.f, 0.f);
		return  new MoveActorCommand(destPosition, this);
	}
	//Enterキーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		//座標をリセットする。
		Vector3 destPosition = m_startPosition;
		return  new MoveActorCommand(destPosition, this);
	}
	return nullptr;
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}