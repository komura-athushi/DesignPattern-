#pragma once

#include "Observer.h"

class Subject : public IGameObject
{
public:
	~Subject() override{}
	virtual bool Start()override { return true; }
	virtual void Update()override{}
	//�I�u�U�[�o�[��z��ɒǉ�����B
	void AddObserver(Observer* observer)
	{
		//�����I�u�U�[�o�[���z��Ɋ܂܂�Ă��Ȃ���΁B
		if (std::find(m_observerList.begin(), m_observerList.end(), observer) == m_observerList.end())
		{
			//�z��ɃI�u�U�[�o�[��ǉ�����B
			m_observerList.push_back(observer);
		}
	}
	//�I�u�U�[�o�[��z�񂩂珜������B
	void RemoveObserver(Observer* observer)
	{
		for (auto it = m_observerList.begin(), e = m_observerList.end(); it != e; ++it) {
			//��������I�u�U�[�o�[���z��Ɋ܂܂�Ă�����B
			if (observer == *it)
			{
				//�z�񂩂�I�u�U�[�o����������B
				m_observerList.erase(it);
				return;
			}
		}
	}
protected:
	//�I�u�U�[�o�[�ɃC�x���g��ʒm�B
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