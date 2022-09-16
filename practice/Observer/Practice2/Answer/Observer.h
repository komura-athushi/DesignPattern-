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
	//Subject����m_next�ɃA�N�Z�X�������̂ŁA�t�����h�N���X�ɂ���B
	friend class Subject;
	//�A�����X�g�̎��̗v�f�ł���Observer�̃|�C���^�B
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