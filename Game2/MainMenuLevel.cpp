#include "stdafx.h"
#include "UIManager.h"
#include "LevelManager.h"
#include "IntroLevel.h"
#include "VillageLevel.h"
#include "MainMenuLevel.h"

MainMenuLevel::MainMenuLevel()
{
	uiManager = new UIManager();
	levelManager = new LevelManager();
	introLevel = new IntroLevel();
	villageLevel = new VillageLevel();
}

MainMenuLevel::~MainMenuLevel()
{
	SafeDelete(uiManager);
	SafeDelete(levelManager);
	SafeDelete(introLevel);
	SafeDelete(villageLevel);
	SafeDelete(profileLevel);
}

void MainMenuLevel::Init(Player* player)
{
	this->player = player;
	introLevel->Init(this->player, this->uiManager, this->levelManager);
	villageLevel->Init(this->player, uiManager, levelManager);

	levelManager->AddLevel("IntroLevel", introLevel);
	levelManager->AddLevel("VillageLevel", villageLevel);
}

void MainMenuLevel::Release()
{
}

void MainMenuLevel::Update()
{
	levelManager->PlayFade();

	introLevel->Update();
	villageLevel->Update();

	uiManager->Update();
	levelManager->Update();
}

void MainMenuLevel::LateUpdate()
{
	introLevel->LateUpdate();
	villageLevel->LateUpdate();
	uiManager->LateUpdate();
	levelManager->LateUpdate();
}

void MainMenuLevel::Render()
{
	introLevel->Render();
	villageLevel->Render();

	uiManager->Render();
	levelManager->Render();
}

void MainMenuLevel::ResizeScreen()
{
}



