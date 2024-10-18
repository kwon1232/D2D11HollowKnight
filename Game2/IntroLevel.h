#pragma once

#include "Level.h"

class ObImage;
class UIManager;
class LevelManager;
class Player;

class MainMenu;
class GameExitMenu;

class IntroLevel : public Level
{
public:
	IntroLevel();
	virtual ~IntroLevel();
	virtual void Init(Player* player, UIManager* uiManager, LevelManager* levelManager) override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
	virtual void ResizeScreen() override;

private:
	class BlurImage* bg;
	UIManager* uiManager;
	LevelManager* levelManager;
	Player* player;

	MainMenu* mainMenu;
	GameExitMenu* gameExitMenu;
	class SettingMenu* settingMenu;
	class AudioMenu* audioMenu;
};

