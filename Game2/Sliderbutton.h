#pragma once

class Button;
class ObImage;

using namespace std;

enum ESoundType {
	All,
	Effect,
	Music,
	None
};

class Sliderbutton
{
public:
	// effect sound는 앞에 e붙었는지 확인으로 소리 조절할 것
	Sliderbutton();
	virtual ~Sliderbutton();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	float siderColLenDivEleven;

	ESoundType soundType;

	string soundKey;

	Vector2 sliderColLen;
	Vector2 sliderRight;
	Vector2 sliderUp;
	float sliderX;

	ObRect* col;
	ObRect* sliderCol;
	Button* sliderBnt;
	ObImage* sliderIm;
	ObImage* sliderBgIm;
	ObImage* numIm[11];

	bool isVisible;

	void InitSliderPos();

private:
	void SetSliderPos();
};

