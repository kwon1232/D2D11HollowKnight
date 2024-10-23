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

	// ToDo : 어느 위치냐에 따라서 이미지가 달라진다.
	ObImage* profileTxt;
	ObImage* profileNum;
	// ToDo : 시간 계산해서 총 플레이 타임 계산해주는 클래스 따로 만들기
	ObImage* profilePlayTime;

	int fileNum;
	wstring profileBntPath;
	wstring profileTxtPath;
	wstring profilePlayTimePath;

	// 파일입출력(포프c++ 과 c++ 서적 보고 좋은 코드 참고해서 
	// 플레이어 정보값 받아오는 코드 작성하기
	ofstream file;

private:
	void ReadFile(std::wstring &profileBntPath, std::wstring &profileTxtPath, std::wstring profilePlayTimePath);
};

