#include "GraphicsEngine.h"

GraphicsEngine	g_graphicsEngine;

void GraphicsEngine::Begin()
{

	

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			m_modelList[i][j] = ' ';
		}
	}

}
