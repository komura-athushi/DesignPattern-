#pragma once

#include "Observer.h"

class Subject : public IGameObject
{
public:
	~Subject() override{}
	virtual bool Start()override { return true; }
	virtual void Update()override{}
	//オブザーバーを連結リストに追加する。
	void AddObserver(Observer* observer)
	{
		//オブザーバーを連結リストの先頭に追加する。
		observer->m_next = m_head;
		m_head = observer;
	}
	//オブザーバーを連結リストから除去する。
	void RemoveObserver(Observer* observer)
	{
		//除去するオブザーバーが連結リストの先頭なら。
		if (m_head == observer)
		{
			m_head = observer->m_next;
			observer->m_next = nullptr;
			return;
		}

		Observer* currentObserver = m_head;
		while (currentObserver != nullptr)
		{
			if (currentObserver->m_next == observer)
			{
				currentObserver->m_next = observer->m_next;
				observer->m_next = nullptr;
				return;
			}
			currentObserver = currentObserver->m_next;
		}
	}
protected:
	//オブザーバーにイベントを通知。
	void Notify(EnEvent eventType)
	{
		//連結リストでそれぞれの要素にアクセスする際の基本の形。
		Observer* currentObserver = m_head;
		while (currentObserver != nullptr)
		{
			currentObserver->OnNotify(eventType);
			currentObserver = currentObserver->m_next;
		}
	}
private:
	//Observer連結リストの先頭のポインタ。
	Observer* m_head = nullptr;
};