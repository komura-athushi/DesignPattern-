#pragma once

#include "Text.h"

//�C�x���g�̎�ށB
enum EnEvent
{
	enEvent_PressAKey,
	enEvent_PressBKey,
	enEvent_PressEnter
};

//Observer(�Ď���)�B
class Observer
{
public:
	virtual ~Observer() {}
	//Subject(�Ď��Ώێ�)����̒ʒm���󂯎��B
	virtual void OnNotify(EnEvent eventType) = 0;
};

//���щ����N���X�B
class Achievement : public Observer 
{
public:
	Achievement();
	~Achievement() override{}
	void OnNotify(EnEvent eventType) override;
private:
	Text* m_text = nullptr;
};