#pragma once
#include "BaseCharacter.h"

class Player : public BaseCharacter
{
public:
	Player();
	virtual ~Player();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:

};

