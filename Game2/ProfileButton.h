#pragma once
class Button;

class ProfileButton
{
public:
	ProfileButton(std::wstring butImL);
	virtual ~ProfileButton();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	ObImage* profileIm;
	Button* profileBnt;
};

