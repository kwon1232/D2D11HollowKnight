#include "stdafx.h"
#include "Button.h"

#include "UIManager.h"
#include "Cursur.h"
#include "LevelManager.h"

#include "SettingMenu.h"

SettingMenu::SettingMenu()
{
	for (int i = 0; i < 2; i++)
	{
		Slider[i] = new ObImage(L"Menu/Slider.png");
		Slider[i]->maxFrame.x = 11;
		Slider[i]->scale = Vector2(60.f, 60.f);
	}
	Slider[1]->rotation = 180 * ToRadian;

	menuTopIm = new ObImage(L"Menu/GameExit/creditsfleur.png");
	menuTopIm->scale = Vector2(920.f, 30.f);
	menuTopIm->SetWorldPos(Vector2(0.f, 320.f));

	SettingIm = new ObImage(L"Menu/GameExit/Setting.png");
	SettingIm->scale = Vector2(580.f, 180.f);
	SettingIm->SetWorldPos(Vector2(-10.f, 370.f));

	gameSettingBnt = new Button(L"Menu/Text/GameSetting.png");
	gameSettingBnt->buttonIm->scale = Vector2(480.f, 140.f);
	gameSettingBnt->buttonIm->SetWorldPosX(-8.f);
	gameSettingBnt->col->scale = Vector2(208.f, 55.f);
	gameSettingBnt->col->SetWorldPos(Vector2(0.f, 220.f));
	gameSettingBnt->col->isVisible = false;

	audioBnt = new Button(L"Menu/Text/Audio.png");
	audioBnt->buttonIm->scale = Vector2(480.f, 140.f);
	audioBnt->buttonIm->SetWorldPosX(-8.f);
	audioBnt->col->scale = Vector2(128.f, 55.f);
	audioBnt->col->SetWorldPos(Vector2(0.f, 130.f));
	audioBnt->col->isVisible = false;

	videoBnt = new Button(L"Menu/Text/Video.png");
	videoBnt->buttonIm->scale = Vector2(480.f, 140.f);
	videoBnt->buttonIm->SetWorldPosX(-8.f);
	videoBnt->col->scale = Vector2(128.f, 55.f);
	videoBnt->col->SetWorldPos(Vector2(0.f, 40.f));
	videoBnt->col->isVisible = false;

	keyboardBnt = new Button(L"Menu/Text/Keyboard.png");
	keyboardBnt->buttonIm->scale = Vector2(480.f, 140.f);
	keyboardBnt->buttonIm->SetWorldPosX(-8.f);
	keyboardBnt->col->scale = Vector2(128.f, 55.f);
	keyboardBnt->col->SetWorldPos(Vector2(0.f, -50.f));
	keyboardBnt->col->isVisible = false;


	backBnt = new Button(L"Menu/Text/Back.png");
	backBnt->buttonIm->scale = Vector2(460.f, 140.f);
	backBnt->buttonIm->SetWorldPosX(-8.f);
	backBnt->col->scale = Vector2(120.f, 55.f);
	backBnt->col->SetWorldPos(Vector2(0.f, -200.f));
	backBnt->col->isVisible = false;

	gameState = EGameState::None;
	collisionState = EGameSettingCollisionState::None;
	menuState = ESettingMenuState::None;

	isVisible = false;

	bWordFade = false;
}

SettingMenu::~SettingMenu()
{
	for (int i = 0; i < 2; i++)
	{
		SafeDelete(Slider[i]);
	}
	SafeDelete(menuTopIm);
	SafeDelete(SettingIm);
	SafeDelete(gameSettingBnt);
	SafeDelete(audioBnt);
	SafeDelete(videoBnt);
	SafeDelete(keyboardBnt);
	SafeDelete(backBnt);
}

void SettingMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;
	this->uiManager->hudMap.insert({ "SettingMenuHUD", this });
}

void SettingMenu::Update()
{
	if (!isVisible) return;

	CollideWithMouse();

	InOutHUDMenu(HUDname);

	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}
	menuTopIm->Update();
	SettingIm->Update();
	gameSettingBnt->Update();
	audioBnt->Update();
	videoBnt->Update();
	keyboardBnt->Update();
	backBnt->Update();
}

void SettingMenu::Render()
{
	if (!isVisible) return;

	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Render();
	}
	menuTopIm->Render();
	SettingIm->Render();
	gameSettingBnt->Render();
	audioBnt->Render();
	videoBnt->Render();
	keyboardBnt->Render();
	backBnt->Render();
}

void SettingMenu::LateUpdate()
{
}


void SettingMenu::CollideWithMouse()
{
	if (uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState != EGameSettingCollisionState::GameSetting)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-133.f, 218.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(133.f, 224.f));

		collisionState = EGameSettingCollisionState::GameSetting;
	}
	else if (!uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState == EGameSettingCollisionState::GameSetting)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}
		collisionState = EGameSettingCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState == EGameSettingCollisionState::GameSetting)
	{
		if (INPUT->KeyPress(VK_LBUTTON)){}

	}
	else if (uiManager->cursur->col->Intersect(audioBnt->col) && collisionState != EGameSettingCollisionState::Audio)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-133.f, 128.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(133.f, 134.f));

		collisionState = EGameSettingCollisionState::Audio;
	}
	else if (!uiManager->cursur->col->Intersect(audioBnt->col) && collisionState == EGameSettingCollisionState::Audio)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EGameSettingCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(audioBnt->col) && collisionState == EGameSettingCollisionState::Audio)
	{
		if (INPUT->KeyPress(VK_LBUTTON)) {}
	}
	else if (uiManager->cursur->col->Intersect(videoBnt->col) && collisionState != EGameSettingCollisionState::Video)
	{
		cout << 1 << endl;
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-133.f, 38.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(133.f, 44.f));

		collisionState = EGameSettingCollisionState::Video;
	}
	else if (!uiManager->cursur->col->Intersect(videoBnt->col) && collisionState == EGameSettingCollisionState::Video)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EGameSettingCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(videoBnt->col) && collisionState == EGameSettingCollisionState::Video)
	{
		if (INPUT->KeyPress(VK_LBUTTON)) {}
	}
	else if (uiManager->cursur->col->Intersect(keyboardBnt->col) && collisionState != EGameSettingCollisionState::Keyboard)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-133.f, -50.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(133.f, -43.f));

		collisionState = EGameSettingCollisionState::Keyboard;
	}
	else if (!uiManager->cursur->col->Intersect(keyboardBnt->col) && collisionState == EGameSettingCollisionState::Keyboard)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EGameSettingCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(keyboardBnt->col) && collisionState == EGameSettingCollisionState::Keyboard)
	{
		if (INPUT->KeyPress(VK_LBUTTON)) {}
	}
	else if (uiManager->cursur->col->Intersect(backBnt->col) && collisionState != EGameSettingCollisionState::Back)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-133.f, -200.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(133.f, -193.f));

		collisionState = EGameSettingCollisionState::Back;
	}
	else if (!uiManager->cursur->col->Intersect(backBnt->col) && collisionState == EGameSettingCollisionState::Back)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EGameSettingCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(backBnt->col) && collisionState == EGameSettingCollisionState::Back)
	{
		if (INPUT->KeyPress(VK_LBUTTON)) {
			this->gameState = EGameState::Back;
		}
	}
}

void SettingMenu::InOutHUDMenu(string HUDname)
{
	if (menuState != ESettingMenuState::None)
	{
		HUD* hud = uiManager->hudMap[HUDname];
		if (hud->gameState != EGameState::Back)
		{
			bWordFade = true;
			BlurAlphaValue(0.5f);

			hud->isVisible = true;
			if (colorAlpha <= 0.0f)
			{
				hud->gameState = EGameState::MainMenu;
			}
		}
		else if (hud->gameState == EGameState::Back)
		{
			bWordFade = false;
			hud->isVisible = false;
			BlurAlphaValue(0.5f);
			if (colorAlpha >= 0.5f)
			{
				hud->gameState = EGameState::None;
				menuState = ESettingMenuState::None;
			}
		}
	}
}


void SettingMenu::BlurAlphaValue(float forceValue)
{
	if (bWordFade)
	{
		if (colorAlpha >= 0.0f)
		{
			menuTopIm->color.A(colorAlpha);
			SettingIm->color.A(colorAlpha);
			Slider[0]->color.A(colorAlpha);
			Slider[1]->color.A(colorAlpha);
			gameSettingBnt->buttonIm->color.A(colorAlpha);
			audioBnt->buttonIm->color.A(colorAlpha);
			videoBnt->buttonIm->color.A(colorAlpha);
			keyboardBnt->buttonIm->color.A(colorAlpha);
			backBnt->buttonIm->color.A(colorAlpha);
			colorAlpha -= forceValue * DELTA;
		}
	}
	else
	{
		if (colorAlpha <= 0.5f)
		{
			menuTopIm->color.A(colorAlpha);
			SettingIm->color.A(colorAlpha);
			Slider[0]->color.A(colorAlpha);
			Slider[1]->color.A(colorAlpha);
			gameSettingBnt->buttonIm->color.A(colorAlpha);
			audioBnt->buttonIm->color.A(colorAlpha);
			videoBnt->buttonIm->color.A(colorAlpha);
			keyboardBnt->buttonIm->color.A(colorAlpha);
			backBnt->buttonIm->color.A(colorAlpha);
			colorAlpha += forceValue * DELTA;
		}
	}
}
