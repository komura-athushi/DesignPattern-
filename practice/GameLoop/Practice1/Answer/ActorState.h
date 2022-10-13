#pragma once

class Actor;


class ActorState
{
public:
	virtual ~ActorState(){}
	//各ステートごとの、入力に対してのステート移行処理。
	virtual ActorState* HandleInput(Actor* actor) = 0;
	//各ステートごとの、毎フレーム呼ばれる処理。
	virtual void Update(Actor* actor) = 0;
	//各ステートに移行した際に、最初に呼ばれる処理。
	virtual void Enter(Actor* actor) = 0;
public:
};

//待機ステート。
class IdleState : public ActorState
{
public:
	~IdleState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};

//攻撃ステート。
class AttackState : public ActorState
{
	~AttackState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};

//ジャンプステート。
class JumpState : public ActorState
{
	~JumpState() override {}
	ActorState* HandleInput(Actor* actor) override;
	void Update(Actor* actor) override;
	void Enter(Actor* actor) override;
};