#pragma once

#include "Observer.h"

class Subject : public IGameObject
{
public:
	~Subject() override{}
	virtual bool Start()override { return true; }
	virtual void Update()override{}
	//�I�u�U�[�o�[��A�����X�g�ɒǉ�����B
	void AddObserver(Observer* observer)
	{
		//�I�u�U�[�o�[��A�����X�g�̐擪�ɒǉ�����B
		observer->m_next = m_head;
		m_head = observer;
	}
	//�I�u�U�[�o�[��A�����X�g���珜������B
	void RemoveObserver(Observer* observer)
	{
		//��������I�u�U�[�o�[���A�����X�g�̐擪�Ȃ�B
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
	//�I�u�U�[�o�[�ɃC�x���g��ʒm�B
	void Notify(EnEvent eventType)
	{
		//�A�����X�g�ł��ꂼ��̗v�f�ɃA�N�Z�X����ۂ̊�{�̌`�B
		Observer* currentObserver = m_head;
		while (currentObserver != nullptr)
		{
			currentObserver->OnNotify(eventType);
			currentObserver = currentObserver->m_next;
		}
	}
private:
	//Observer�A�����X�g�̐擪�̃|�C���^�B
	Observer* m_head = nullptr;
};