#pragma once

#include "Level.h"

class ObImage;
class UIManager;
class LevelManager;

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
	ObImage* bg;
	UIManager* uiManager;
	LevelManager* levelManager;

	MainMenu* mainMenu;
	GameExitMenu* gameExitMenu;
	class SettingMenu* settingMenu;
	class AudioMenu* audioMenu;
};

