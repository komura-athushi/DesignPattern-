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
	m_modelRender.Init("Assets/modelData/lever/lever.tkm",nullptr,0,enModelUpAxisZ,true,HEIGHTNUMBER*WIDTHNUMBER);
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
			m_modelRender.UpdateInstancingData(i + j*HEIGHTNUMBER, pos, m_rotation, m_scale);
		}
		pos.z = m_position.z;
	}
	m_modelRender.Update();
}

void LeverRender::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
