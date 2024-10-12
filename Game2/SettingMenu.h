#pragma once
#include "HUD.h"

class Button;
class ObImage;

enum class EGameSettingCollisionState
{
	GameSetting,
	Audio,
	Video,
	Keyboard,
	Back,
	None
};

enum class ESettingMenuState
{
	GameStartBnt,
	GameSettingBnt,
	AchievementBnt,
	GameExitBnt,
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

	void CollideWithMouse();
	void BlurAlphaValue(float forceValue);

	void InOutHUDMenu(string HUDname);

private:
	EGameSettingCollisionState collisionState;
	ESettingMenuState menuState;

	string HUDname;

	float colorAlpha;

	ObImage* menuTopIm;
	ObImage* SettingIm;

	Button* gameSettingBnt;
	Button* audioBnt;
	Button* videoBnt;
	Button* keyboardBnt;
	Button* backBnt;

};

