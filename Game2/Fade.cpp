#include "stdafx.h"
#include "Fade.h"

Fade::Fade()
{
	fadeBox = new ObRect();
	fadeBox->scale = Vector2(2500.f, 2500.f);

	AlphaValue = 1.f;
	colorR = 0.f, colorG = 0.f; colorB = 0.f;

	isVisible = true;
	fadeState = EFadeState::FadeIn;
	fadeColorState = EFadeColorState::Black;
}

Fade::~Fade()
{
	SafeDelete(fadeBox);
}

void Fade::Update()
{
	if (!isVisible || fadeState == EFadeState::VisibleOff) return;
	fadeBox->Update();
}

void Fade::Render()
{
	if (!isVisible || fadeState == EFadeState::VisibleOff) return;
	fadeBox->Render();
}

void Fade::LateUpdate()
{
}

void Fade::Release()
{
	SafeDelete(fadeBox);
}

void Fade::PlayFadeIn()
{
	if (AlphaValue <= 1.1f) {
		AlphaValue += 0.6f * DELTA;
		fadeBox->color = Color(colorR, colorG, colorB, AlphaValue);
	} else
	{
		fadeState = EFadeState::FadeOut;

	}
}

void Fade::PlayFadeOut()
{
	if (AlphaValue >= -0.1f) {
		AlphaValue -= 0.6f * DELTA;
		fadeBox->color = Color(colorR, colorG, colorB, AlphaValue);
	} else
	{
		fadeState = EFadeState::None;
	}
}


void Fade::GetFade()
{
	if (fadeState == EFadeState::FadeIn) PlayFadeIn();
	else if (fadeState == EFadeState::FadeOut) PlayFadeOut();
}

void Fade::SetFadeColor(int colorVal)
{
	switch (colorVal)
	{
	case 0:
		fadeColorState = EFadeColorState::Black;
		colorR = 0.f, colorG = 0.0f, colorB = 0.f;
		break;
	case 1:
		fadeColorState = EFadeColorState::Red;
		colorR = 1.f, colorG = 0.f; colorB = 0.f;
		break;
	default:
		fadeColorState = EFadeColorState::White;
		colorR = 1.f, colorG = 1.f, colorB = 1.f;
		break;
	}
}

void Fade::SetFadestate(int fadeNum)
{
	switch (fadeNum)
	{
	case 0:
		fadeState = EFadeState::FadeIn;
		break;
	case 1:
		fadeState = EFadeState::FadeOut;
		break;
	case 2:
		fadeState = EFadeState::VisibleOff;
	default:
		fadeState = EFadeState::None;
		break;
	}
}
