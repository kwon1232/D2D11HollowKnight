#include "stdafx.h"
#include "Button.h"
#include <string>

using namespace std;

#include "Sliderbutton.h"

Sliderbutton::Sliderbutton()
{
	sliderBnt = new Button(L"Menu/MenuSliderHandle.png");

	sliderIm = new ObImage(L"Menu/Num/Slider.png");
	
	sliderBgIm = new ObImage(L"Menu/Num/SliderBackground.png");
	
	for (int i = 0; i < 11; i++)
	{
		wstring nName = L"Menu/Num/" + to_wstring(i) + L".png";
		numIm[i] = new ObImage(nName);
		numIm[i]->scale = Vector2(60.f, 50.f);
	}
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
	sliderBnt->Render();
	sliderIm->Render();
	sliderBgIm->Render();
	for (int i = 0; i < 11; i++)
	{
		numIm[i]->Render();
	}
}
