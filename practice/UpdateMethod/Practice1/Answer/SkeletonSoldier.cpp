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

	printf("Š[œ•ºm‚ªƒ”ƒ@ƒ‹ƒLƒŠ[‚ÉUŒ‚!\n");
	m_valkyrie->Damaged(m_attack);
}

void SkeletonSoldier::Damaged(int damage)
{
	m_hp -= damage;
	printf("Š[œ•ºm‚Í%d‚Ìƒ_ƒ[ƒW‚ğó‚¯‚½I\n", damage);

	if (m_hp <= 0)
	{
		Dead();
	}
}

void SkeletonSoldier::Dead()
{
	m_isDead = true;
	printf("Š[œ•ºm‚Í€‚ñ‚¾I\n");
}