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

	// Bnt�� ���콺�� �浹�Ѵٸ� Ŀ�� ��������Ʈ ���
	virtual void CollideWithMouse();

	// ExitBntMenu �� �� ���� �� ���� �Լ�
	void InOutHUDMenu(string HUDname);

	void BlurAlphaValue(float forceValue);

	void ClickGameStart();

	EMainMenuCollisionState collisionState;
	EMainMenuState menuState;

private:
	string HUDname;

	float colorAlpha;

	ObImage* titleTop;
	ObImage* titleText;
	Button* gameStartBnt;
	Button* gameSettingBnt;
	Button* achievementBnt;
	Button* gameExitBnt;
};

