#include "stdafx.h"
#include "Player.h"
#include "UIManager.h"
#include "LevelManager.h"

#include "MainMenu.h"
#include "GameExitMenu.h"
#include "SettingMenu.h"
#include "AudioMenu.h"

#include "IntroLevel.h"

IntroLevel::IntroLevel()
{
	bg = new ObImage(L"Background/wallpaperflare.com_wallpaper.jpg");
	bg->scale = Vector2(1900.f, 1000.f);
	bg->SetWorldPos(Vector2(0.f, 0.f));

	mainMenu = new MainMenu();
	gameExitMenu = new GameExitMenu();
	settingMenu = new SettingMenu();
	audioMenu = new AudioMenu();

	isVisible = true;
}

IntroLevel::~IntroLevel()
{
	SafeDelete(bg);
	SafeDelete(mainMenu);
	SafeDelete(gameExitMenu);
	SafeDelete(settingMenu);
	SafeDelete(audioMenu);
}

void IntroLevel::Init(Player* player, UIManager* uiManager, LevelManager* levelManager)
{
	this->player = player;
	this->uiManager = uiManager;
	this->levelManager = levelManager;

	mainMenu->Init(this->uiManager, this->levelManager);
	gameExitMenu->Init(this->uiManager, this->levelManager);
	settingMenu->Init(this->uiManager, this->levelManager);
	audioMenu->Init(this->uiManager, this->levelManager);
}

void IntroLevel::Release()
{
}

void IntroLevel::Update()
{
	if (!isVisible) return;

	bg->Update();
	mainMenu->Update();
	gameExitMenu->Update();
	settingMenu->Update();
	audioMenu->Update();
}

void IntroLevel::LateUpdate()
{
}

void IntroLevel::Render()
{
	if (!isVisible) return;

	bg->Render();
	mainMenu->Render();
	gameExitMenu->Render();
	settingMenu->Render();
	audioMenu->Render();
}

void IntroLevel::ResizeScreen()
{
}
