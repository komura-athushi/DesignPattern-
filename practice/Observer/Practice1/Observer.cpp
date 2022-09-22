#include "stdafx.h"
#include "Observer.h"

Achievement::Achievement()
{
	m_text = NewGO<Text>(0);
}

void Achievement::OnNotify(EnEvent eventType)
{
	switch (eventType)
	{
	case enEvent_PressEnter:
		m_text->SetText(std::wstring(L"Enter�L�[���������т���������܂����I"));
	default:
		break;
	}
}