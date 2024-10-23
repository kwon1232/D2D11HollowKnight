#pragma once
class Button;

class ProfileButton
{
public:
	ProfileButton(std::wstring butImL);
	virtual ~ProfileButton();
	void Init();
	void Release();
	void Update();
	void LateUpdate();
	void Render();

	void SetColWorldPosY(float);

private:
	ObRect* col;
	Button* profileBnt;

	Button* deleteProfileBnt;

	ObImage* mainHPIm;
	ObImage* HPim[10];

	//ObImage* levelTxt;
};

