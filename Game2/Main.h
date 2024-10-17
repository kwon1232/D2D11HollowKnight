#pragma once
class Cursur;

class Main : public Scene
{
private:
	MainMenuLevel* mainMenuLevel;
	//ToDo : 마을 및 던전 맵 관리자 만들어주기 	
	// Sound* effectSound; 
public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
