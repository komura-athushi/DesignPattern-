#include "stdafx.h"
#include "Lever.h"

namespace
{
	const std::string LEVER_GENERAL = "Assets/modelData/lever/lever/lever.tkm";
	const std::string LEVER_RED = "Assets/modelData/lever/redlever/lever.tkm";
	const std::string LEVER_BLUE = "Assets/modelData/lever/bluelever/lever.tkm";
}

void Lever::Init(EnLever enLever, const Vector3& position)
{
	std::string filePath;
	if (enLever == enLever_General)
	{
		filePath = LEVER_GENERAL;
	}
	else if (enLever == enLever_Red)
	{
		filePath = LEVER_RED;
	}
	else if (enLever == enLever_Blue)
	{
		filePath = LEVER_BLUE;
	}
	m_modelRender.Init(filePath.c_str());
	m_leverState = enLever;
	m_modelRender.SetPosition(position);
	m_modelRender.Update();
}
