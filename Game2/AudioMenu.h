#pragma once
#include "HUD.h"

class Button;
class ObImage;
class Sliderbutton;

enum class EAudioCollisionState
{
	BackBnt,
	None
};

enum class EAudioMenuState
{
	BackBnt,
	None
};

class AudioMenu : public HUD
{
public:
	AudioMenu();
	virtual ~AudioMenu()override;
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void LateUpdate() override;

	void CollideWithMouse();

	virtual void InOutHUDMenu(string HUDname) override;
	virtual void BlurAlphaValue(float forceValue) override;


private:

	EAudioMenuState menuState;

	Sliderbutton* sliderbutton[3];

	ObImage* audioTxtIm;
	ObImage* menuTopIm;

	ObImage* totalVolumeTxtIm;
	ObImage* SoundEffectsVolumeTxtIm;
	ObImage* MusicVolumeTxtIm;

	Button* backBnt;
	Button* defaultValBnt;
};

