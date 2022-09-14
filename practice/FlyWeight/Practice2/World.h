#pragma once

#include "Lever.h"

class World : public IGameObject
{
public:
	World(){}
	~World(){}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	/// <summary>
	/// 指定の位置に配置されているレバーの種類を返す。
	/// </summary>
	/// <param name="x"></param>
	/// <param name="z"></param>
	/// <returns>レバーの種類。</returns>
	const EnLever GetEnLever(int x, int z) const
	{
		return m_leverList[x][z].GetEnLever();
	}
	static const int HEIGHTNUMBER = 20;
	static const int WIDTHNUMBER = 20;
private:
	Lever m_leverList[HEIGHTNUMBER][WIDTHNUMBER];

};

