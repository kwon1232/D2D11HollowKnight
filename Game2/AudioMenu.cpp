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
		sliderbutton[i]->sliderIm->SetLocalPosX(-275.f);
		sliderbutton[i]->sliderBgIm->scale = Vector2(560.f, 15.f);
		sliderbutton[i]->sliderBgIm->SetLocalPosX(-280.f);
		sliderbutton[i]->sliderCol->scale = Vector2(550.f, 10.f);
		sliderbutton[i]->col->scale = Vector2(550.f, 50.f);
		sliderbutton[i]->sliderX = sliderbutton[i]->col->scale.x;
	}
	sliderbutton[0]->col->SetWorldPos(Vector2(0.f, 220.f));
	sliderbutton[1]->col->SetWorldPos(Vector2(0.f, 70.f));
	sliderbutton[2]->col->SetWorldPos(Vector2(0.f, -80.f));
	sliderbutton[0]->soundType = ESoundType::All;
	sliderbutton[1]->soundType = ESoundType::Effect;
	sliderbutton[2]->soundType = ESoundType::Music;
	for (int i = 0; i < 3; i++) {
		sliderbutton[i]->sliderRight.x = sliderbutton[i]->col->GetWorldPos().x + sliderbutton[i]->sliderCol->scale.x / 2;
		sliderbutton[i]->sliderRight.y = sliderbutton[i]->col->GetWorldPos().y + sliderbutton[i]->sliderCol->scale.y / 2;
		sliderbutton[i]->sliderUp.x = sliderbutton[i]->col->GetWorldPos().x - sliderbutton[i]->sliderCol->scale.x / 2;
		sliderbutton[i]->sliderUp.y = sliderbutton[i]->col->GetWorldPos().y - sliderbutton[i]->sliderCol->scale.y / 2;
		sliderbutton[i]->sliderColLen.x = sliderbutton[i]->sliderRight.x - sliderbutton[i]->sliderUp.x;
		sliderbutton[i]->sliderColLen.y = sliderbutton[i]->sliderRight.y - sliderbutton[i]->sliderUp.y;
		sliderbutton[i]->siderColLenDivEleven = sliderbutton[i]->sliderColLen.x / 11;
	}

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
	SoundEffectsVolumeTxtIm->scale = Vector2(250.f, 48.f);
	SoundEffectsVolumeTxtIm->SetWorldPos(Vector2(-450.f, 70.f));
	
	MusicVolumeTxtIm = new ObImage(L"Menu/Num/MusicVolume.png");
	MusicVolumeTxtIm->scale = Vector2(250.f, 48.f);
	MusicVolumeTxtIm->SetWorldPos(Vector2(-450.f, -80.f));

	defaultValBnt = new Button(L"Menu/Num/£ÄefaultValBnt.png");
	defaultValBnt->buttonIm->scale = Vector2(450.f, 88.f);
	defaultValBnt->buttonIm->SetWorldPos(Vector2(-5.f, 0.f));
	defaultValBnt->col->scale = Vector2(345.f, 65.f);
	defaultValBnt->col->SetWorldPos(Vector2(0.f, -250.f));
	defaultValBnt->col->isVisible = false;

	backBnt = new Button(L"Menu/Text/Back.png");
	backBnt->buttonIm->scale = Vector2(450.f, 140.f);
	backBnt->buttonIm->SetWorldPos(Vector2(-5.f, 0.f));
	backBnt->col->scale = Vector2(115.f, 40.f);
	backBnt->col->SetWorldPos(Vector2(0.f, -355.f));
	backBnt->col->isVisible = false;

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
	for (int i = 0; i < 3; i++)
	{
		sliderbutton[i]->Init();
	}
}

void AudioMenu::Update()
{
	if (!isVisible) return;

	 //cout << "x :" << INPUT->GetWorldMousePos().x << "  y : " << INPUT->GetWorldMousePos().y << endl;

	CollideWithMouse();

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
	for (int i = 0; i < 3; i++) {
		sliderbutton[i]->LateUpdate();
	}
}

void AudioMenu::CollideWithMouse()
{
	if (menuState != EAudioMenuState::None) return;
	if (uiManager->cursur->col->Intersect(defaultValBnt->col) && collisionState != EAudioCollisionState::DefaultValBnt)
	{
		SOUND->Play("E_ui_change_selection");
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-290.f, -260.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(290.f, -253.f));

		collisionState = EAudioCollisionState::DefaultValBnt;
	}
	else if (!uiManager->cursur->col->Intersect(defaultValBnt->col) && collisionState == EAudioCollisionState::DefaultValBnt)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EAudioCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(defaultValBnt->col) && collisionState == EAudioCollisionState::DefaultValBnt)
	{
		if (INPUT->KeyPress(VK_LBUTTON))
		{
			sliderbutton[0]->InitSliderPos();
			sliderbutton[1]->InitSliderPos();
			sliderbutton[2]->InitSliderPos();
		}
	}
	else if (uiManager->cursur->col->Intersect(backBnt->col) && collisionState != EAudioCollisionState::BackBnt)
	{
		SOUND->Play("E_ui_change_selection");
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-290.f, -360.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(290.f, -353.f));

		collisionState = EAudioCollisionState::BackBnt;
	}
	else if (!uiManager->cursur->col->Intersect(backBnt->col) && collisionState == EAudioCollisionState::BackBnt)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EAudioCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(backBnt->col) && collisionState == EAudioCollisionState::BackBnt)
	{
		if (INPUT->KeyPress(VK_LBUTTON))
		{
			this->gameState = EGameState::Back;
		}
	}
	else if (uiManager->cursur->col->Intersect(sliderbutton[0]->col) && collisionState != EAudioCollisionState::SliderAll)
	{
		SOUND->Play("E_ui_change_selection");
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-613.f, 220.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(413.f, 223.f));

		collisionState = EAudioCollisionState::SliderAll;
	}
	else if (!uiManager->cursur->col->Intersect(sliderbutton[0]->col) && collisionState == EAudioCollisionState::SliderAll)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EAudioCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(sliderbutton[1]->col) && collisionState != EAudioCollisionState::SliderEffect)
	{
		SOUND->Play("E_ui_change_selection");
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-613.f, 70.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(413.f, 73.f));

		collisionState = EAudioCollisionState::SliderEffect;
	}
	else if (!uiManager->cursur->col->Intersect(sliderbutton[1]->col) && collisionState == EAudioCollisionState::SliderEffect)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EAudioCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(sliderbutton[2]->col) && collisionState != EAudioCollisionState::SliderMusic)
	{
		SOUND->Play("E_ui_change_selection");
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-613.f, -84.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(413.f, -80.f));

		collisionState = EAudioCollisionState::SliderMusic;
	}
	else if (!uiManager->cursur->col->Intersect(sliderbutton[2]->col) && collisionState == EAudioCollisionState::SliderMusic)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EAudioCollisionState::None;
	}
}

void AudioMenu::InOutHUDMenu(string HUDname)
{
	if (menuState == EAudioMenuState::None) return;

	if (hud->gameState != EGameState::Back)
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
	}

}

void AudioMenu::BlurAlphaValue(float forceValue)
{
}
