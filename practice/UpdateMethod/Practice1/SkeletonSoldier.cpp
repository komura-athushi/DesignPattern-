#include "SkeletonSoldier.h"

#include <iostream>

#include "Valkyrie.h"

void SkeletonSoldier::Update()
{
	if (m_isDead)
	{
		return;
	}
	Attack();
}

void SkeletonSoldier::Attack()
{
	if (m_valkyrie->GetIsDead())
	{
		return;
	}

	printf("�[�����m�����@���L���[�ɍU��!\n");
	m_valkyrie->Damaged(m_attack);
}

void SkeletonSoldier::Damaged(int damage)
{
	m_hp -= damage;
	printf("�[�����m��%d�̃_���[�W���󂯂��I\n", damage);

	if (m_hp <= 0)
	{
		Dead();
	}
}

void SkeletonSoldier::Dead()
{
	m_isDead = true;
	printf("�[�����m�͎��񂾁I\n");
}