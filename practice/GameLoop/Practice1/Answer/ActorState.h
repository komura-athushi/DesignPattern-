#pragma once

class Actor;


class ActorState
{
public:
	virtual ~ActorState(){}
	//�e�X�e�[�g���Ƃ́A���͂ɑ΂��ẴX�e�[�g�ڍs�����B
	virtual ActorState* HandleInput(Actor* actor) = 0;
	//�e�X�e�[�g���Ƃ́A���t���[���Ă΂�鏈���B
	virtual void Update(Actor* actor) = 0;
	//�e�X�e�[�g�Ɉڍs�����ۂɁA�ŏ��ɌĂ΂�鏈���B
	virtual void Enter(Actor* actor) = 0;
public:
};

//�ҋ@�X�e�[�g�B
class IdleState : public ActorState
{
public:
	~IdleState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};

//�U���X�e�[�g�B
class AttackState : public ActorState
{
	~AttackState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};

//�W�����v�X�e�[�g�B
class JumpState : public ActorState
{
	~JumpState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};