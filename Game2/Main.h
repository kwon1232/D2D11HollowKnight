#pragma once
class Cursur;

class Main : public Scene
{
private:
	MainMenuLevel* mainMenuLevel;
	//ToDo : ���� �� ���� �� ������ ������ֱ� 	
	// Sound* effectSound; 
public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
