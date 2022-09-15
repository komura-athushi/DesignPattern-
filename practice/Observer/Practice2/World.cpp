#include "stdafx.h"
#include "World.h"

#include <time.h>
#include <stdlib.h>

bool World::Start()
{
	//—”‚ğ‰Šú‰»B
	srand(time(NULL));
	for (int i = 0; i < HEIGHTNUMBER; i++)
	{
		
		for (int j = 0; j < WIDTHNUMBER; j++)
		{
			Vector3 pos = Vector3::Zero;
			pos.x += i * 50.0f;
			pos.z += j * 50.0f;
			EnLever enLever = EnLever(rand() % 3);
			m_leverList[i][j].Init(enLever,pos);
		}
	}
	return true;
}

void World::Update()
{

}

void World::Render(RenderContext& rc)
{
	for (int i = 0; i < HEIGHTNUMBER; i++)
	{
		for (int j = 0; j < WIDTHNUMBER; j++)
		{
			m_leverList[i][j].Draw(rc);
		}
	}
}
