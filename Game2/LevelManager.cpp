#include "stdafx.h"
#include "Fade.h"

#include "LevelManager.h"

LevelManager::LevelManager()
{
	fade = new Fade();
	levelState = ELevelState::None;
	nextLevelName = "";
	curLevelName = "";
}

LevelManager::~LevelManager()
{
	SafeDelete(fade);
}

void LevelManager::Init()
{
}

void LevelManager::Update()
{
	fade->Update();
}

void LevelManager::Render()
{
	fade->Render();
}

void LevelManager::LateUpdate()
{
}

void LevelManager::Release()
{
}

void LevelManager::PlayFade()
{
	if (fade->GetFadeState() == EFadeState::FadeIn)
		FadeIn();
	if (fade->GetFadeState() == EFadeState::FadeOut)
	{
		ChangeLevel(nextLevelName, curLevelName);
		FadeOut();
	}
}

void LevelManager::ChangeLevel(string nextLevelName, string curLevelName)
{
	this->nextLevelName = nextLevelName;
	this->curLevelName = curLevelName;

	if (fade->GetFadeState() == EFadeState::FadeOut && levelState == ELevelState::Change)
	{
		Level* nextLevel = levelArr[nextLevelName];
		Level* curLevel = levelArr[curLevelName];

		curLevel->isVisible = false;
		nextLevel->isVisible = true;

		levelState = ELevelState::None;
	}
	else if (levelState != ELevelState::Change && fade->GetFadeState() != EFadeState::FadeOut)
	{
		PlayFade();
	}
}

void LevelManager::AddLevel(string newLevelName, Level* newLevel)
{
	levelArr.insert({ newLevelName, newLevel });
}

void LevelManager::FadeIn()
{
	fade->SetFadestate(0);
	fade->GetFade();
}

void LevelManager::FadeOut()
{
	fade->SetFadestate(1);
	fade->GetFade();
}
