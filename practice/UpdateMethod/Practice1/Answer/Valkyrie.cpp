#include "Valkyrie.h"

#include <iostream>

#include "SkeletonSoldier.h"

void Valkyrie::Update()
{
	if (m_isDead)
	{
		return;
	}
	Attack();
}

void Valkyrie::Attack()
{
	if (m_skeletonSoldier->GetIsDead())
	{
		return;
	}

	printf("���@���L���[���[�����m�ɍU��!\n");
	m_skeletonSoldier->Damaged(m_attack);
}

void Valkyrie::Damaged(int damage)
{
	m_hp -= damage;
	printf("���@���L���[��%d�̃_���[�W���󂯂��I\n", damage);

	if (m_hp <= damage)
	{
		Dead();
	}
}

void Valkyrie::Dead()
{
	m_isDead = true;
	printf("���@���L���[�͎��񂾁I\n");
}
