#include "stdafx.h"
#include "Actor.h"

bool Actor::Start()
{
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/push1.wav");
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/push2.wav");
	return true;
}

void Actor::Update()
{
	if (g_keyboard->IsKeyTrigger(Keyboard::A))
	{
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(0);
		se->Play(false);
	}
	if (g_keyboard->IsKeyTrigger(Keyboard::B))
	{
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(1);
		se->Play(false);
	}
	if (g_keyboard->IsKeyTrigger(Keyboard::Enter))
	{
		//ObserverÇ…í ímÅB
		Notify(enEvent_PressEnter);
	}
}
