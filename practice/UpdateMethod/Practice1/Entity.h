#pragma once
class Entity
{
public:
	Entity() {}
	virtual ~Entity(){}
	virtual void Update() = 0;
private:
};