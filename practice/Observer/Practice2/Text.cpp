#include "stdafx.h"
#include "Text.h"

bool Text::Start()
{
	m_fontRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	return true;
}

void Text::Update()
{

}

void Text::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}
