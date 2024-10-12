#pragma once
#include "HUD.h"

class Button;
class ObImage;
class Sliderbutton;

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

private:
	ObImage* totalVolumeTxtIm;
	ObImage* SoundEffectsVolumeTxtIm;
	ObImage* MusicVolumeTxtIm;
	Sliderbutton* sliderbutton;
};

