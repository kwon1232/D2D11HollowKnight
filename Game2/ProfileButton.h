#pragma once
class Button;

class ProfileButton
{
public:
	ProfileButton(std::wstring butImL, int fileN);
	virtual ~ProfileButton();
	void Init();
	void Release();
	void Update();
	void LateUpdate();
	void Render();

	void SetColWorldPosY(float);

private:
	ObRect* col;
	Button* profileBnt;

	Button* deleteProfileBnt;

	ObImage* mainHPIm;
	ObImage* HPim[10];

	// ToDo : ��� ��ġ�Ŀ� ���� �̹����� �޶�����.
	ObImage* profileTxt;
	ObImage* profileNum;
	// ToDo : �ð� ����ؼ� �� �÷��� Ÿ�� ������ִ� Ŭ���� ���� �����
	ObImage* profilePlayTime;

	int fileNum;
	wstring profileBntPath;
	wstring profileTxtPath;
	wstring profilePlayTimePath;

	// ���������(����c++ �� c++ ���� ���� ���� �ڵ� �����ؼ� 
	// �÷��̾� ������ �޾ƿ��� �ڵ� �ۼ��ϱ�
	ofstream file;

private:
	void ReadFile(std::wstring &profileBntPath, std::wstring &profileTxtPath, std::wstring profilePlayTimePath);
};

