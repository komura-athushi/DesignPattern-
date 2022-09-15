#include "stdafx.h"
#include "Observer.h"

MakeSoundEngine::MakeSoundEngine()
{
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/push1.wav");
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/push2.wav");
}

Achievement::Achievement()
{
	m_text = NewGO<Text>(0);
}

void Achievement::OnNotify(EnEvent eventType)
{
	switch (eventType)
	{
	case enEvent_PressEnter:
		m_text->SetText(std::wstring(L"EnterƒL[‚ğ‰Ÿ‚·ÀÑ‚ª‰ğœ‚³‚ê‚Ü‚µ‚½I"));
	default:
		break;
	}
}