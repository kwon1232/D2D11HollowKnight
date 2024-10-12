#pragma once
class ObRect;
class ObImage;

class Cursur
{
public:
	Cursur();
	virtual ~Cursur();

	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Release();

	void SetCursulVisible(bool onOff);
	void GetCursulVisible();

public:
	Vector2 mousePos;

	ObRect* col;
	ObImage* cursurIm;

	bool isVisible;

	bool isCursurVisible;
};

