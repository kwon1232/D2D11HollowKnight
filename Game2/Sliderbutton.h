#pragma once

class Button;
class ObImage;

using namespace std;

class Sliderbutton
{
public:
	Sliderbutton();
	virtual ~Sliderbutton();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	Button* sliderBnt;
	ObImage* sliderIm;
	ObImage* sliderBgIm;
	ObImage* numIm[11];
};

