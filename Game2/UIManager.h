#pragma once
#include <map>
#include <string>
#include "HUD.h"

using namespace std;

class Cursur;
class Fade;

class UIManager
{
public:
	UIManager();
	virtual ~UIManager();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Release();

	map<string, HUD*> hudMap;
	Cursur* cursur;
private:
};

