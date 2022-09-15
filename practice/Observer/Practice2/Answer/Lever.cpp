#include "stdafx.h"
#include "Lever.h"

namespace
{
	const std::string LEVER_GENERAL = "Assets/modelData/lever/lever/lever.tkm";
	const std::string LEVER_RED = "Assets/modelData/lever/redlever/lever.tkm";
	const std::string LEVER_BLUE = "Assets/modelData/lever/bluelever/lever.tkm";
}

void Lever::Init(EnLever enLever,const int maxInstance)
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
	m_modelRender.Init(filePath.c_str(),nullptr,0,enModelUpAxisZ,true,maxInstance);
	m_leverState = enLever;
}
