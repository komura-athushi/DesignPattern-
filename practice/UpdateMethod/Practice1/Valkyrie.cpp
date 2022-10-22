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

	printf("ヴァルキリーが骸骨兵士に攻撃!\n");
	m_skeletonSoldier->Damaged(m_attack);
}

void Valkyrie::Damaged(int damage)
{
	m_hp -= damage;
	printf("ヴァルキリーは%dのダメージを受けた！\n", damage);

	if (m_hp <= damage)
	{
		Dead();
	}
}

void Valkyrie::Dead()
{
	m_isDead = true;
	printf("ヴァルキリーは死んだ！\n");
}
