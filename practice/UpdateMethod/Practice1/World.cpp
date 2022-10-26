#include "World.h"


void World::GameLoop()
{
    //�e��p�����[�^��ݒ�B
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

        printf("%d�^�[���ځI\n", count);

        //�Q�[���I�u�W�F�N�g�̍X�V�����B
        Update();

        count++;
    }
}

void World::Update()
{
    //�҂�������B
    Sleep(2000.0f);
    m_valkyrie.Update();

    //�҂�������B
    Sleep(2000.0f);
    m_skeletonSoldier.Update();
}