#pragma once

#include "Observer.h"

class Subject : public IGameObject
{
public:
	~Subject() override{}
	virtual bool Start()override { return true; }
	virtual void Update()override{}
	//オブザーバーを配列に追加する。
	void AddObserver(Observer* observer)
	{
		//同じオブザーバーが配列に含まれていなければ。
		if (std::find(m_observerList.begin(), m_observerList.end(), observer) == m_observerList.end())
		{
			//配列にオブザーバーを追加する。
			m_observerList.push_back(observer);
		}
	}
	//オブザーバーを配列から除去する。
	void RemoveObserver(Observer* observer)
	{
		for (auto it = m_observerList.begin(), e = m_observerList.end(); it != e; ++it) {
			//除去するオブザーバーが配列に含まれていたら。
			if (observer == *it)
			{
				//配列からオブザーバを除去する。
				m_observerList.erase(it);
				return;
			}
		}
	}
protected:
	//オブザーバーにイベントを通知。
	void Notify(EnEvent eventType)
	{
		for (auto observer : m_observerList)
		{
			observer->OnNotify(eventType);
		}
	}
private:
	std::vector<Observer*> m_observerList;
};