#pragma once
class Scene02 : public Scene
{
public:
	ObTileMap* map;
	//ObRect* rc;

	bool WhiteOut;
	float WhiteIn;

	Scene02();
	~Scene02();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

