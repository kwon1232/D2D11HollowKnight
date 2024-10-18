#pragma once


class BlurImage : public GameObject
{
    friend class ObTileMap;
private:
    static ID3D11Buffer* vertexBuffer;
    static ID3D11Buffer* uvBuffer;
    ID3D11DeviceContext* deviceContext;
    ID3D11Texture2D* canvasTexture = nullptr;

public:
    static void CreateStaticMember();
    static void DeleteStaticMember();

protected:
    ID3D11ShaderResourceView* SRV;
    ID3D11SamplerState* sampler;

    D3D11_SAMPLER_DESC	        samplerDesc;
    ID3D11Device* device;
    D3D11_TEXTURE2D_DESC textureDesc;

    ANIMSTATE                   animState;
    float                       animTime; //�����ų �� �ʿ��� ����
    float                       animInterval; //�������
    bool                        animXAxis; //�������

public:
    vector<Vector4>             pixels;
    Vector4                     uv;
    Int2                        maxFrame;
    Int2                        frame;
    bool                        reverseLR;
    wstring                     file;
    Int2		                imageSize;
    int channels;

protected:
    void PlayAnim();

    Vector4& GetPixel(int i, int j);
public:
    BlurImage(std::wstring file);
    virtual ~BlurImage();

    virtual void Render()override;
    void ChangeAnim(ANIMSTATE anim, float interval, bool xAxis = true); //set�Լ� ���
    void ChangeSampler(D3D11_FILTER filter = D3D11_FILTER_MIN_MAG_MIP_POINT,
        D3D11_TEXTURE_ADDRESS_MODE addressU = D3D11_TEXTURE_ADDRESS_WRAP,
        D3D11_TEXTURE_ADDRESS_MODE addressV = D3D11_TEXTURE_ADDRESS_WRAP);
    void BoxBlur5();
};

