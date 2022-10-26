#pragma once
#include "Entity.h"

class Valkyrie;

class SkeletonSoldier : public Entity
{
public:
	SkeletonSoldier() {}
	~SkeletonSoldier() override{}
	void Update() override;
	void SetTarget(Valkyrie* valkyrie)
	{
		m_valkyrie = valkyrie;
	}
	void SetHP(int hp)
	{
		m_hp = hp;
	}
	int GetHP()
	{
		return m_hp;
	}
	void SetAttack(int attack)
	{
		m_attack = attack;
	}
	const bool GetIsDead() const
	{
		return m_isDead;
	}
	void Damaged(int damage);
private:
	void Attack();
	void Dead();
private:
	Valkyrie* m_valkyrie = nullptr;
	int			m_hp = 0;
	int			m_attack;
	bool		m_isDead = false;
};

