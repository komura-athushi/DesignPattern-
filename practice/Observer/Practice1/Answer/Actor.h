#pragma once

#include "Subject.h"

class Actor : public Subject
{
public:
	~Actor()override{}
	bool Start() override;
	void Update() override;
private:

};

