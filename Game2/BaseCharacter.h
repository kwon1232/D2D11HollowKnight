#pragma once
class ObRect;

class BaseCharacter
{
public:
	BaseCharacter();
	virtual ~BaseCharacter();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	ObRect* col;
};

