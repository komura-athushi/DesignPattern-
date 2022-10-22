#pragma once
#include <Windows.h>

#include "GameObject.h"


class Actor : public GameObject
{
public:
	Actor() {}
	~Actor() override {}
	void Start() override
	{
		SetX(0);
		SetY(0);
		SetSymbol('P');
	}
	void Update() override
	{
		Move();
	}
	void Draw() override
	{
		g_graphicsEngine.Draw(GetX(), GetY(), GetSymbol());
	}
private:
	void Move()
	{
		if (GetAsyncKeyState(VK_LEFT) != 0)
		{
			SetX(GetX() - 1);
		}
		if (GetAsyncKeyState(VK_RIGHT) != 0)
		{
			SetX(GetX() + 1);
		}

		if (GetAsyncKeyState(VK_UP) != 0)
		{
			SetY(GetY() - 1);
		}
		if (GetAsyncKeyState(VK_DOWN) != 0)
		{
			SetY(GetY() + 1);
		}
	}
};

