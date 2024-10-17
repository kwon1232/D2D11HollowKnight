#pragma once
#include "HUD.h"

class Button;
class ObImage;

enum class EGameSettingCollisionState
{
	GameSettingBnt,
	AudioBnt,
	VideoBnt,
	KeyboardBnt,
	BackBnt,
	None
};

enum class ESettingMenuState
{
	GameSettingBnt,
	AudioBnt,
	VideoBnt,
	KeyboardBnt,
	BackBnt,
	None
};

class SettingMenu : public HUD
{
public:
	SettingMenu();
	virtual ~SettingMenu()override;
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void LateUpdate() override;

	virtual void CollideWithMouse() override;

	virtual void InOutHUDMenu(string HUDname) override;
	virtual void BlurAlphaValue(float forceValue)override;
private:
	EGameSettingCollisionState collisionState;
	ESettingMenuState menuState;

	string HUDname;

	ObImage* menuTopIm;
	ObImage* SettingIm;

	Button* gameSettingBnt;
	Button* audioBnt;
	Button* videoBnt;
	Button* keyboardBnt;
	Button* backBnt;

};

