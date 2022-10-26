#include "World.h"


void World::GameLoop()
{
    //各種パラメータを設定。
    m_valkyrie.SetHP(1000);
    m_skeletonSoldier.SetHP(500);
    m_valkyrie.SetAttack(80);
    m_skeletonSoldier.SetAttack(100);
    m_valkyrie.SetTarget(&m_skeletonSoldier);
    m_skeletonSoldier.SetTarget(&m_valkyrie);

    int count = 1;
    while (true)
    {
        printf("\n");

        Sleep(4000.0f);

        printf("%dターン目！\n", count);

        //ゲームオブジェクトの更新処理。
        Update();

        count++;
    }
}

void World::Update()
{
    //待ちを入れる。
    Sleep(2000.0f);
    m_valkyrie.Update();

    //待ちを入れる。
    Sleep(2000.0f);
    m_skeletonSoldier.Update();
}