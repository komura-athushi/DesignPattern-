#pragma once
#include <Windows.h>

#include <random>
#include "GameObject.h"
#include "Actor.h"

class Enemy : public GameObject
{
public:
	Enemy() {}
	~Enemy() override {}
	void Start() override
	{
		SetX(GraphicsEngine::WIDTH);
		SetY(GraphicsEngine::HEIGHT);
		SetSymbol('E');
	}
	void Update() override
	{
		Move();
	}
	void Draw() override
	{
		GetGraphicsEngine().Draw(GetX(), GetY(), GetSymbol());
	}
	void SetActor(Actor* actor)
	{
		m_actor = actor;
	}
private:
	void Move()
	{
		int actorX = m_actor->GetX();
		int actorY = m_actor->GetY();

		int x = GetX();
		int y = GetY();

		std::random_device rnd;     // ”ñŒˆ’è“I‚È—”¶¬Ší
		if (rnd() % 4 == 0)
		{
			if (x > actorX)
			{
				SetX(x - 1);
			}
			else if (x < actorX)
			{
				SetX(x + 1);
			}
		}

		if (rnd() % 4 == 0)
		{
			if (y > actorY)
			{
				SetY(y - 1);
			}
			else if (y < actorY)
			{
				SetY(y + 1);
			}
		}

	}
private:
	Actor*		m_actor = nullptr;
};
