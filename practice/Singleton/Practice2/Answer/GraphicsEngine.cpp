#include "GraphicsEngine.h"

bool GraphicsEngine::m_isInstance = false;

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
