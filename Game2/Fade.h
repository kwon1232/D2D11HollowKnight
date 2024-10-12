#pragma once
class ObRect;

enum class EFadeState
{
	FadeIn  = 0,
	FadeOut,
	VisibleOff,
	None
};

enum class EFadeColorState
{
	Black,
	Red,
	White
};

class Fade
{
public:
	Fade();
	virtual ~Fade();

	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Release();

	void GetFade();
	// 0 = Black, 1 = Red, 2 = White
	void SetFadeColor(int colorVal);
	// 0 = fadein 1 = fadeout 2 = nonfade
	void SetFadestate(int fadeNum);

	inline float GetAlphaValue() const { return AlphaValue; }
	inline EFadeState GetFadeState() const { return fadeState; }
private:
	EFadeState fadeState;
	EFadeColorState fadeColorState;
	float colorR, colorG, colorB;
	ObRect* fadeBox;

	bool isVisible;

	float AlphaValue;

private:
	void PlayFadeIn();
	void PlayFadeOut();
};

