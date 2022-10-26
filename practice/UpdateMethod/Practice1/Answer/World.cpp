#include "World.h"

#include "Valkyrie.h"
#include "SkeletonSoldier.h"

void World::GameLoop()
{
    Valkyrie* valkyrie = new Valkyrie();
    SkeletonSoldier* skeletonSoldier = new SkeletonSoldier();
    valkyrie->SetHP(1000);
    skeletonSoldier->SetHP(500);
    valkyrie->SetAttack(80);
    skeletonSoldier->SetAttack(100);
    valkyrie->SetTarget(skeletonSoldier);
    skeletonSoldier->SetTarget(valkyrie);

    m_entityList.push_back(valkyrie);
    m_entityList.push_back(skeletonSoldier);


    int count = 1;
    while (true)
    {
        printf("\n");

        Sleep(4000.0f);

        printf("%d�^�[���ځI\n", count);

        Update();

        count++;
    }
}

void World::Update()
{
    for (auto& entity : m_entityList)
    {
        Sleep(2000.0f);
        entity->Update();
    }
}
