#include "stdafx.h"
#include "Button.h"

Button::Button(wstring butImL)
{
	col = new ObRect();

	col->isFilled = false;
	buttonIm = new ObImage(butImL);
	buttonIm->SetParentRT(*col);
}

Button::~Button()
{
	SafeDelete(col);
	SafeDelete(buttonIm);
}

void Button::Init()
{
}

void Button::Release()
{
}

void Button::Update()
{
	col->Update();
	buttonIm->Update();
}

void Button::LateUpdate()
{
}

void Button::Render()
{
	col->Render();
	buttonIm->Render();
}
