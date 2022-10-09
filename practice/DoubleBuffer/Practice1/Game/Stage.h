#pragma once

#include <vector>
class Actor;

class Stage
{
public:
	Stage(){}
	void Start();
	void Update();
	/// <summary>
	/// Actor���X�e�[�W�ɒǉ��B
	/// </summary>
	/// <param name="actor">�ǉ�����Actor�B</param>
	void AddActor(Actor* actor)
	{
		m_actorList.push_back(actor);
	}
private:
	std::vector<Actor*> m_actorList;
	int m_count = 0;
};