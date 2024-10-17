#pragma once
#include "HUD.h"

class Button;
class ObImage;

enum class EMainMenuCollisionState
{
	GameStartBnt,
	GameSettingBnt,
	AchievementBnt,
	GameExitBnt,
	None
};


enum class EMainMenuState
{
	GameStartBnt,
	GameSettingBnt,
	AchievementBnt,
	GameExitBnt,
	None
};

class MainMenu : public HUD
{
public:
	MainMenu();
	virtual ~MainMenu() override;
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void LateUpdate() override;

	// Bnt와 마우스가 충돌한다면 커서 스프라이트 재생
	virtual void CollideWithMouse()override;

	void InOutHUDMenu(string HUDname) override;
	virtual void BlurAlphaValue(float forceValue) override;

	void ClickGameStart();

	EMainMenuCollisionState collisionState;
	EMainMenuState menuState;

private:
	ObImage* titleTop;
	ObImage* titleText;
	Button* gameStartBnt;
	Button* gameSettingBnt;
	Button* achievementBnt;
	Button* gameExitBnt;
};

