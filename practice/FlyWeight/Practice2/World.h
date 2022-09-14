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
	/// �w��̈ʒu�ɔz�u����Ă��郌�o�[�̎�ނ�Ԃ��B
	/// </summary>
	/// <param name="x"></param>
	/// <param name="z"></param>
	/// <returns>���o�[�̎�ށB</returns>
	const EnLever GetEnLever(int x, int z) const
	{
		return m_leverList[x][z].GetEnLever();
	}
	static const int HEIGHTNUMBER = 20;
	static const int WIDTHNUMBER = 20;
private:
	Lever m_leverList[HEIGHTNUMBER][WIDTHNUMBER];

};

