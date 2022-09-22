#include "stdafx.h"
#include "Actor.h"

bool Actor::Start()
{
	m_spriteRender.Init("Assets/sprite/actor.dds",200,200);
	m_spriteRender.SetPosition(m_startPosition);
	m_position = m_startPosition;
	m_commandVector.push_back(std::make_unique<MoveActorCommand>(m_position, this));
	return true;
}

void Actor::Update()
{
	auto newCommand = std::move(HandleInput());
	if (newCommand)
	{
		
		DeleteCommand();
		newCommand->Execute();
		m_commandVector.push_back(std::move(newCommand));
		m_commandIndex += 1;
	}
	UndoAndCancel();

	m_fontRender.SetText(std::to_wstring(m_position.y).c_str());
	m_spriteRender.SetPosition(m_position);
	m_spriteRender.Update();
}

std::unique_ptr<Command> Actor::HandleInput()
{
	//上キーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Up))
	{
		//上に移動する。
		Vector3 destPosition = m_position + Vector3(0.f, 100.f, 0.f);
		return  std::make_unique<MoveActorCommand>(destPosition, this);
	}
	//下キーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Down))
	{
		//下に移動する。
		Vector3 destPosition = m_position + Vector3(0.f, -100.f, 0.f);
		return  std::make_unique<MoveActorCommand>(destPosition, this);
	}
	//Enterキーが押されたら。
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		//座標をリセットする。
		Vector3 destPosition = m_startPosition;
		return  std::make_unique<MoveActorCommand>(destPosition, this);
	}
	return nullptr;
}

void Actor::UndoAndCancel()
{
	if (g_keyboard->IsKeyDown(Keyboard::LeftControl) && g_keyboard->IsKeyTrigger(Keyboard::Z))
	{
		m_commandVector[m_commandIndex]->Undo();
		m_commandIndex -= 1;
		if (m_commandIndex < 0) m_commandIndex = 0;
	}
	if (g_keyboard->IsKeyDown(Keyboard::LeftControl) && g_keyboard->IsKeyTrigger(Keyboard::Y))
	{
		m_commandIndex += 1;
		if (m_commandIndex > m_commandVector.size() - 1) m_commandIndex = m_commandVector.size() - 1;
		m_commandVector[m_commandIndex]->Execute();
		
	}
}

void Actor::DeleteCommand()
{
	if (m_commandIndex == m_commandVector.size() - 1)
	{
		return;
	}
	m_commandVector.erase(m_commandVector.begin()+ m_commandIndex+1, m_commandVector.end());
}

void Actor::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}