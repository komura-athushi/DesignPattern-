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
	/// Actorをステージに追加。
	/// </summary>
	/// <param name="actor">追加するActor。</param>
	void AddActor(Actor* actor)
	{
		m_actorList.push_back(actor);
	}
private:
	std::vector<Actor*> m_actorList;
	int m_count = 0;
};