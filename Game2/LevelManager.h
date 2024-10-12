#pragma once
#include "Level.h"
#include <map>
#include <string>

using namespace std;

class Fade;

// ������ �ٲ�� �ִٸ� fade ���� ���� üũ enum
enum class ELevelState
{
	Change,
	None
};

class LevelManager
{
public:

	LevelManager();
	virtual ~LevelManager();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();
	virtual void Release();

	void PlayFade();

	map<string, Level*> levelArr;
	Fade* fade;
	ELevelState levelState;

	void ChangeLevel(string nextLevelName, string curLevellName);
	void AddLevel(string newLevelName, Level *newLevel);

private:
	string nextLevelName;
	string curLevelName;

	void FadeIn();
	void FadeOut();

};

