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

	sliderbutton = new Sliderbutton();
	
	totalVolumeTxtIm = new ObImage(L"Menu/Num/TotalVolume.png");
	
	SoundEffectsVolumeTxtIm = new ObImage(L"Menu/Num/SoundEffectsVolume.png");
	
	MusicVolumeTxtIm = new ObImage(L"Menu/Num/MusicVolume.png");
}

AudioMenu::~AudioMenu()
{
	for (int i = 0; i < 2; i++)
	{
		SafeDelete(Slider[i]);
		SafeDelete(sliderbutton);
	}
}

void AudioMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;
	this->uiManager->hudMap.insert({ "ExitMenuHUD", this });
}

void AudioMenu::Update()
{
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}
	sliderbutton->Update();
}

void AudioMenu::Render()
{
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Render();
	}
	sliderbutton->Render();
}

void AudioMenu::LateUpdate()
{
}

void AudioMenu::CollideWithMouse()
{
}
