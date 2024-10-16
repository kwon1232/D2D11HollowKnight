#include "stdafx.h"

#include "Button.h"
#include "Sliderbutton.h"

#include "UIManager.h"
#include "Cursur.h"

#include "AudioMenu.h"

AudioMenu::AudioMenu()
{
	for (int i = 0; i < 2; i++)
	{
		Slider[i] = new ObImage(L"Menu/Slider.png");
		Slider[i]->maxFrame.x = 11;
		Slider[i]->scale = Vector2(60.f, 60.f);
	}

	Slider[1]->rotation = 180 * ToRadian;

	for (int i = 0; i < 3; i++) {
		sliderbutton[i] = new Sliderbutton();
		sliderbutton[i]->sliderIm->scale = Vector2(550.f, 10.f);
		sliderbutton[i]->sliderBgIm->scale = Vector2(560.f, 15.f);
	}
	sliderbutton[0]->col->SetWorldPos(Vector2(100.f, 220.f));

	audioTxtIm = new ObImage(L"Menu/Text/Audio.png");
	audioTxtIm->scale = Vector2(600.f, 180.f);
	audioTxtIm->SetWorldPos(Vector2(-8.f, 390.f));

	menuTopIm = new ObImage(L"Menu/GameExit/creditsfleur.png");
	menuTopIm->scale = Vector2(920.f, 30.f);
	menuTopIm->SetWorldPos(Vector2(0.f, 350.f));

	totalVolumeTxtIm = new ObImage(L"Menu/Num/TotalVolume.png");
	totalVolumeTxtIm->scale = Vector2(250.f, 48.f);
	totalVolumeTxtIm->SetWorldPos(Vector2(-450.f, 220.f));

	SoundEffectsVolumeTxtIm = new ObImage(L"Menu/Num/SoundEffectsVolume.png");
	
	MusicVolumeTxtIm = new ObImage(L"Menu/Num/MusicVolume.png");

	defaultValBnt = new Button(L"Menu/Num/£ÄefaultValBnt.png");
	defaultValBnt->buttonIm->scale = Vector2(450.f, 120.f);
	defaultValBnt->buttonIm->SetWorldPos(Vector2(-5.f, 0.f));
	defaultValBnt->col->scale = Vector2(115.f, 40.f);
	defaultValBnt->col->SetWorldPos(Vector2(0.f, -50.f));

	backBnt = new Button(L"Menu/Text/Back.png");
	backBnt->buttonIm->scale = Vector2(450.f, 120.f);
	backBnt->buttonIm->SetWorldPos(Vector2(-5.f, 0.f));
	backBnt->col->scale = Vector2(115.f, 40.f);
	backBnt->col->SetWorldPos(Vector2(0.f, -50.f));

	colorAlpha = 0.0f;

	menuState = EAudioMenuState::None;

	isVisible = false;
}

AudioMenu::~AudioMenu()
{
	for (int i = 0; i < 2; i++)
		SafeDelete(Slider[i]);

	for (int i = 0; i < 3; i++)
		SafeDelete(sliderbutton[i]);

	SafeDelete(audioTxtIm);
	SafeDelete(menuTopIm);
	SafeDelete(totalVolumeTxtIm);
	SafeDelete(SoundEffectsVolumeTxtIm);
	SafeDelete(MusicVolumeTxtIm);
	SafeDelete(backBnt);
	SafeDelete(defaultValBnt);
}

void AudioMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;
	this->uiManager->hudMap.insert({ "AudioMenuHUD", this });
}

void AudioMenu::Update()
{
	if (!isVisible) return;

	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}
	for (int i = 0; i < 3; i++)
	{
		sliderbutton[i]->Update();
	}
	audioTxtIm->Update();
	menuTopIm->Update();
	totalVolumeTxtIm->Update();
	SoundEffectsVolumeTxtIm->Update();
	MusicVolumeTxtIm->Update();
	backBnt->Update();
	defaultValBnt->Update();
}

void AudioMenu::Render()
{
	if (!isVisible) return;

	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Render();
	}
	for (int i = 0; i < 3; i++)
	{
		sliderbutton[i]->Render();
	}
	audioTxtIm->Render();
	menuTopIm->Render();
	totalVolumeTxtIm->Render();
	SoundEffectsVolumeTxtIm->Render();
	MusicVolumeTxtIm->Render();
	backBnt->Render();
	defaultValBnt->Render();
}

void AudioMenu::LateUpdate()
{
}

void AudioMenu::CollideWithMouse()
{
}

void AudioMenu::InOutHUDMenu(string HUDname)
{
	if (menuState != EAudioMenuState::None)
	{
		//HUD* hud = uiManager->hudMap[HUDname];
		/*if (hud->gameState != EGameState::Back)
		{
			bWordFade = true;
			BlurAlphaValue(0.5f);

			if (colorAlpha <= 0.0f)
			{
				hud->isVisible = true;
				hud->gameState = EGameState::MainMenu;
			}
		}
		else if (hud->gameState == EGameState::Back)
		{
			BlurAlphaValue(0.5f);
			bWordFade = false;
			hud->isVisible = false;
			if (colorAlpha >= 0.5f)
			{
				hud->gameState = EGameState::None;
				menuState = EAudioMenuState::None;
			}
		}*/
	}
}

void AudioMenu::BlurAlphaValue(float forceValue)
{
}
