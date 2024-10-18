#include "stdafx.h"
#include "Button.h"
#include <string>

using namespace std;

#include "Sliderbutton.h"

Sliderbutton::Sliderbutton()
{
	this->soundKey = soundKey;
	col = new ObRect();
	col->isFilled = false;
	col->isVisible = false;
	col->scale = Vector2(30.f, 30.f);

	sliderCol = new ObRect();
	sliderCol->SetParentRT(*col);
	sliderCol->isFilled = false;
	sliderCol->isVisible = false;

	sliderBnt = new Button(L"Menu/MenuSliderHandle.png");
	sliderBnt->col->SetParentRT(*col);
	sliderBnt->col->scale = Vector2(37.f, 65.f);
	sliderBnt->col->isVisible = false;
	sliderBnt->col->SetLocalPosY(10.f);
	sliderBnt->buttonIm->scale = Vector2(55.f, 55.f);
	sliderBnt->buttonIm->rotation = 90 * ToRadian;
	sliderBnt->buttonIm->SetLocalPosY(23.f);

	sliderIm = new ObImage(L"Menu/Num/Slider.png");
	sliderIm->SetParentRT(*col);
	sliderIm->SetLocalPosY(-5.f);
	sliderIm->pivot = OFFSET_LB;

	sliderBgIm = new ObImage(L"Menu/Num/SliderBackground.png");
	sliderBgIm->SetParentRT(*col);
	sliderBgIm->SetLocalPosY(-6.5f);
	sliderBgIm->pivot = OFFSET_LB;
	
	for (int i = 0; i < 11; i++)
	{
		wstring nName = L"Menu/Num/" + to_wstring(i) + L".png";
		numIm[i] = new ObImage(nName);
		numIm[i]->scale = Vector2(60.f, 50.f);
		numIm[i]->SetParentRT(*col);
		numIm[i]->SetLocalPosX(330.f);
		numIm[i]->isVisible = false;
	}

	soundType = ESoundType::None;

	numIm[5]->isVisible = true;

	isVisible = true;
}

Sliderbutton::~Sliderbutton()
{
	SafeDelete(sliderBnt);
	SafeDelete(sliderCol);
	SafeDelete(sliderIm);
	SafeDelete(sliderBgIm);
	for (int i = 0; i < 11; i++)
	{
		SafeDelete(numIm[i]);
	}
}

void Sliderbutton::Init()
{
	InitSliderPos();
}

void Sliderbutton::Release()
{
}

void Sliderbutton::Update()
{
	if (!isVisible)return;

	SetSliderPos();

	col->Update();
	sliderCol->Update();
	sliderBnt->Update();
	sliderIm->Update();
	sliderBgIm->Update();
	for (int i = 0; i < 11; i++)
	{
		numIm[i]->Update();
	}
}

void Sliderbutton::LateUpdate()
{
}

void Sliderbutton::Render()
{
	if (!isVisible)return;
	col->Render();
	sliderCol->Render();
	sliderBnt->Render();
	sliderBgIm->Render();
	sliderIm->Render();
	for (int i = 0; i < 11; i++)
	{
		numIm[i]->Render();
	}
}

void Sliderbutton::InitSliderPos()
{
	sliderIm->scale.x = sliderX * 0.5f;
	sliderBnt->col->SetWorldPosX(sliderUp.x + siderColLenDivEleven * 5.5f);
	for (int i = 0; i < 11; i++) {
		numIm[i]->isVisible = false;
	}
	numIm[5]->isVisible = true;
	if (soundType == ESoundType::All)
	{
		SOUND->SetAllVolume(1.f);
	}
	else if (soundType == ESoundType::Music)
	{
		SOUND->SetMusicVolume(1.f);
	}
	else if (soundType == ESoundType::Effect)
	{
		SOUND->SetEffectVolume(1.f);
	}
}

void Sliderbutton::SetSliderPos()
{
	if (INPUT->KeyPress(VK_LBUTTON) &&
		sliderBnt->col->IntersectScreenMouse(INPUT->GetScreenMousePos())
		&& INPUT->GetWorldMousePos().x >= sliderUp.x 
		&& INPUT->GetWorldMousePos().x <= sliderRight.x)
	{
		sliderBnt->col->SetWorldPosX(INPUT->GetWorldMousePos().x);
		// 반복문을 쓰면 제곱수가 되서 잘 안보임 하드코딩으로 내버려둘 것
		if (INPUT->GetWorldMousePos().x >= sliderUp.x &&
			INPUT->GetWorldMousePos().x < sliderUp.x + 50.f)
		{
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[0]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(0.f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(0.f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(0.f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 2)
		{
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[1]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.1f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(0.2f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(0.2f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(0.2f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 2 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 3) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[2]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.2f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(0.4f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(0.4f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(0.4f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 3 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 4) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[3]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.3f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(0.6f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(0.6f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(0.6f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 4 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 5) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[4]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.4f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(0.8f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(0.8f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(0.8f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 5 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 6) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[5]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.5f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(1.f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(1.f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(1.f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 6 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 7) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[6]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.6f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(1.2f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(1.2f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(1.2f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 7 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 8) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[7]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.7f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(1.4f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(1.4f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(1.4f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 8 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 9) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[8]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.8f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(1.6f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(1.6f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(1.6f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 9 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 10) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[9]->isVisible = true;
			sliderIm->scale.x = sliderX * 0.9f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(1.8f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(1.8f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(1.8f);
			}
		}
		else if (INPUT->GetWorldMousePos().x >= sliderUp.x + siderColLenDivEleven * 10 &&
			INPUT->GetWorldMousePos().x < sliderUp.x + siderColLenDivEleven * 11) {
			for (int i = 0; i < 11; i++) {
				numIm[i]->isVisible = false;
			}
			numIm[10]->isVisible = true;
			sliderIm->scale.x = sliderX * 1.f;
			if (soundType == ESoundType::All)
			{
				SOUND->SetAllVolume(2.f);
			}
			else if (soundType == ESoundType::Music)
			{
				SOUND->SetMusicVolume(2.f);
			}
			else if (soundType == ESoundType::Effect)
			{
				SOUND->SetEffectVolume(2.f);
			}
		}
	}
}
