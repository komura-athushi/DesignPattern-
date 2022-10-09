#include "Stage.h"

#include "Actor.h"

#include <windows.h>

void Stage::Start()
{
	for (auto& actor : m_actorList)
	{
		Sleep(600);
		std::cout << actor->GetName() << "が現れた!!!!\n";
	}
	std::cout << "\n";
	Sleep(1000);
}

void Stage::Update()
{
	std::cout << m_count << "フレーム目開始!!\n";

	for (auto& actor : m_actorList)
	{
		actor->Update();
		Sleep(600);
	}
	for (auto& actor : m_actorList)
	{
		actor->Swap();
	}

	m_count++;
	std::cout << "\n";
	Sleep(800);
}
