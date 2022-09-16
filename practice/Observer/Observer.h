#pragma once

#include "Text.h"

class Subject;

enum EnEvent
{
	enEvent_PressAKey,
	enEvent_PressBKey,
	enEvent_PressEnter
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void OnNotify(EnEvent eventType) = 0;
private:
	//Subjectからm_nextにアクセスしたいので、フレンドクラスにする。
	friend class Subject;
	//連結リストの次の要素であるObserverのポインタ。
	Observer* m_next = nullptr;
};

class MakeSoundEngine : public Observer 
{
public:
	MakeSoundEngine();
	~MakeSoundEngine() override{}
	void OnNotify(EnEvent eventType) override;

};

class Achievement : public Observer 
{
public:
	Achievement();
	~Achievement() override{}
	void OnNotify(EnEvent eventType) override;
private:
	Text* m_text = nullptr;
};