#include "stdafx.h"
#include "LeverRender.h"

LeverRender::LeverRender()
{

}

LeverRender::~LeverRender()
{

}

bool LeverRender::Start()
{
	for (int i = 0; i < HEIGHTNUMBER * WIDTHNUMBER; i++)
	{
		m_modelRender[i].Init("Assets/modelData/lever/lever.tkm");
	}
	return true;
}

void LeverRender::Update()
{
	Vector3 pos = m_position;
	for (int i = 0; i < HEIGHTNUMBER; i++)
	{
		pos.x += 50.f;
		for (int j = 0; j < WIDTHNUMBER; j++)
		{
			pos.z += 50.f;
			m_modelRender[i + j * HEIGHTNUMBER].SetPosition(pos);
			m_modelRender[i + j * HEIGHTNUMBER].Update();
		}
		pos.z = m_position.z;
	}
	
}

void LeverRender::Render(RenderContext& rc)
{
	for (int i = 0; i < HEIGHTNUMBER * WIDTHNUMBER; i++)
	{
		m_modelRender[i].Draw(rc);
	}
}