#include "stdafx.h"
#include "World.h"

#include <time.h>
#include <stdlib.h>

bool World::Start()
{
	for (int i = 0; i < enLever_Number; i++)
	{
		m_leverOriginList[i].Init(EnLever(i), HEIGHTNUMBER * WIDTHNUMBER);
	}

	//—”‚ð‰Šú‰»B
	srand(time(NULL));
	for (int i = 0; i < HEIGHTNUMBER; i++)
	{
		for (int j = 0; j < WIDTHNUMBER; j++)
		{
			EnLever enLever = EnLever(rand() % 3);
			m_leverList[i][j] = &m_leverOriginList[enLever];

			Vector3 pos = Vector3::Zero;
			pos.x += i * 50.0f;
			pos.z += j * 50.0f;
			m_leverList[i][j]->AddPosition(pos);
		}
	}
	return true;
}

void World::Update()
{
	for (auto& lever : m_leverOriginList)
	{
		lever.UpdateInstancingData();
	}
}

void World::Render(RenderContext& rc)
{
	for (auto& lever : m_leverOriginList)
	{
		lever.Draw(rc);
	}
}
