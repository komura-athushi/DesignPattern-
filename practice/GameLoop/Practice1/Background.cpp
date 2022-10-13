#include "stdafx.h"
#include "Background.h"

bool Background::Start()
{
	m_modelRender.Init("Assets/modelData/ground.tkm");
	m_modelRender.SetPosition(Vector3(0.0f, -0.0f, 0.f));
	m_modelRender.Update();
	m_physicsObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0), 0.0f);
	return true;
}

void Background::Update()
{
	m_modelRender.Update();
}

void Background::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}