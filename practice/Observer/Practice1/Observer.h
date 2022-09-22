#pragma once

#include "Text.h"

//イベントの種類。
enum EnEvent
{
	enEvent_PressAKey,
	enEvent_PressBKey,
	enEvent_PressEnter
};

//Observer(監視者)。
class Observer
{
public:
	virtual ~Observer() {}
	//Subject(監視対象者)からの通知を受け取る。
	virtual void OnNotify(EnEvent eventType) = 0;
};

//実績解除クラス。
class Achievement : public Observer 
{
public:
	Achievement();
	~Achievement() override{}
	void OnNotify(EnEvent eventType) override;
private:
	Text* m_text = nullptr;
};