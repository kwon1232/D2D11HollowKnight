#include "stdafx.h"
#include "Button.h"
#include <string>

using namespace std;

#include "Sliderbutton.h"

Sliderbutton::Sliderbutton()
{
	col = new ObRect();
	col->isFilled = false;
	col->isVisible = false;
	col->scale = Vector2(30.f, 30.f);

	sliderBnt = new Button(L"Menu/MenuSliderHandle.png");
	sliderBnt->col->SetParentRT(*col);
	sliderBnt->col->scale = Vector2(37.f, 55.f);
	sliderBnt->col->isVisible = true;
	//sliderBnt->col->SetLocalPosY(14.f);
	//sliderBnt->col->SetLocalPosX(3.f);
	sliderBnt->buttonIm->scale = Vector2(55.f, 55.f);
	sliderBnt->buttonIm->rotation = 90 * ToRadian;

	sliderIm = new ObImage(L"Menu/Num/Slider.png");
	sliderIm->SetParentRT(*col);

	sliderBgIm = new ObImage(L"Menu/Num/SliderBackground.png");
	sliderBgIm->SetParentRT(*col);
	
	for (int i = 0; i < 11; i++)
	{
		wstring nName = L"Menu/Num/" + to_wstring(i) + L".png";
		numIm[i] = new ObImage(nName);
		numIm[i]->scale = Vector2(60.f, 50.f);
		numIm[i]->SetParentRT(*col);
		numIm[i]->SetLocalPosX(330.f);
	}

	isVisible = true;
}

Sliderbutton::~Sliderbutton()
{
	SafeDelete(sliderBnt);
	SafeDelete(sliderIm);
	SafeDelete(sliderBgIm);
	for (int i = 0; i < 11; i++)
	{
		SafeDelete(numIm[i]);
	}
}

void Sliderbutton::Init()
{
}

void Sliderbutton::Release()
{
}

void Sliderbutton::Update()
{
	if (!isVisible)return;
	col->Update();
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
	sliderBnt->Render();
	sliderBgIm->Render();
	sliderIm->Render();
	for (int i = 0; i < 11; i++)
	{
		numIm[i]->Render();
	}
}

void Sliderbutton::SetSliderPos()
{
	float sliderBgImLen = sliderBgIm->GetWorldPos().x;

	//Slider image placement location
}
