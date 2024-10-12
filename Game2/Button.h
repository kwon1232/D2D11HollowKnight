#pragma once
#include <string>

class ObRect;
class ObImage;

class Button
{
public:
	Button(std::wstring butImL);
	virtual ~Button();
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	ObRect* col;
	ObImage* buttonIm;
};

