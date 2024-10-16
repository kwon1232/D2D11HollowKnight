#include "stdafx.h"
#include "UIManager.h"
#include "HUD.h"

HUD::HUD()
{
	isVisible = false;
}

HUD::~HUD()
{
}

void HUD::Init(UIManager* uiManager, LevelManager* levelManager)
{
}

void HUD::Update()
{
}

void HUD::Render()
{
}

void HUD::LateUpdate()
{
}

void HUD::CollideWithMouse()
{
}

void HUD::InOutHUDMenu(string HUDname)
{
	//if (gameState != EGameState::None)
	//{
	//	if (gameState == EGameState::First)
	//	{
	//		if (colorAlpha <= 0.0f)
	//		{
	//			isVisible = false;
	//			BlurAlphaValue(0.5f);
	//		}
	//		if (colorAlpha >= 0.5f) {
	//			gameState = EGameState::None;
	//			return;
	//		}
	//	}
	//	HUD* hud = uiManager->hudMap[HUDname];
	//	if (gameState == EGameState::Change)
	//	{
	//		bWordFade = true;
	//		BlurAlphaValue(0.5f);

	//		if (colorAlpha <= 0.0f)
	//		{
	//			hud->isVisible = true;
	//			hud->bWordFade = false;
	//			hud->colorAlpha = 0.0f;
	//			hud->gameState = EGameState::First;
	//			isVisible = false;
	//		}
	//	}
	//} 
}

void HUD::BlurAlphaValue(float forceValue)
{
	/*if (bWordFade && colorAlpha >= 0.0f)
	{
		colorAlpha -= forceValue * DELTA;
		for (ObImage* im : imArr) {
			im->color.A(colorAlpha);
		}
	}
	else if (!bWordFade && colorAlpha <= 0.5f)
	{
		colorAlpha += forceValue * DELTA;
		for (ObImage* im : imArr) {
			im->color.A(colorAlpha);
		}
	}*/
}
