#pragma once
#include "HUD.h"

class Button;
class ObImage;
class Sliderbutton;

enum class EAudioCollisionState
{
	DefaultValBnt,
	BackBnt,
	SliderAll,
	SliderMusic,
	SliderEffect,
	None
};

enum class EAudioMenuState
{
	DefaultValBnt,
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

	virtual void CollideWithMouse() override;

	virtual void InOutHUDMenu(string HUDname) override;
	virtual void BlurAlphaValue(float forceValue) override;


private:

	EAudioMenuState menuState;
	EAudioCollisionState collisionState;

	Sliderbutton* sliderbutton[3];

	ObImage* audioTxtIm;
	ObImage* menuTopIm;

	ObImage* totalVolumeTxtIm;
	ObImage* MusicVolumeTxtIm;
	ObImage* SoundEffectsVolumeTxtIm;

	Button* defaultValBnt;
	Button* backBnt;
};

