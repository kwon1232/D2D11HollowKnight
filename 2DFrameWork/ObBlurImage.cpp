#include "framework.h"

#include <omp.h>
#include <stb_image.h>
#include <stb_image_write.h>

ID3D11Buffer* BlurImage::vertexBuffer = nullptr;
ID3D11Buffer* BlurImage::uvBuffer = nullptr;

void BlurImage::CreateStaticMember()
{
    VertexPT* Vertex;

    Vertex = new VertexPT[4];
    //VertexCount = 4;
    //시계방향으로 정점찍기
    Vertex[0].position.x = -0.5f;
    Vertex[0].position.y = -0.5f;
    Vertex[0].uv = Vector2(0.0f, 1.0f);

    Vertex[1].position.x = -0.5f;
    Vertex[1].position.y = 0.5f;
    Vertex[1].uv = Vector2(0.0f, 0.0f);

    Vertex[2].position.x = 0.5f;
    Vertex[2].position.y = -0.5f;
    Vertex[2].uv = Vector2(1.0f, 1.0f);

    Vertex[3].position.x = 0.5f;
    Vertex[3].position.y = 0.5f;
    Vertex[3].uv = Vector2(1.0f, 0.0f);

    //CreateVertexBuffer
    {
        D3D11_BUFFER_DESC desc;
        desc = { 0 };
        desc.Usage = D3D11_USAGE_DEFAULT;//버퍼를 읽고 쓰는 방법
        desc.ByteWidth = sizeof(VertexPT) * 4; //버퍼 크기 (바이트)입니다.
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//버퍼가 파이프 라인에 바인딩되는 방법을 식별하십시오

        D3D11_SUBRESOURCE_DATA data = { 0 };
        //하위 리소스를 초기화하기위한 데이터를 지정합니다.
        data.pSysMem = Vertex;
        //초기화 데이터의 포인터.

        //버퍼 만들기
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, &data, &vertexBuffer);
        assert(SUCCEEDED(hr));
    }

    delete[] Vertex;
    //CreateConstantBuffer
    {
        D3D11_BUFFER_DESC desc = { 0 };
        desc.ByteWidth = sizeof(Vector4);
        desc.Usage = D3D11_USAGE_DYNAMIC;
        desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;//상수버퍼
        desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        desc.MiscFlags = 0;
        desc.StructureByteStride = 0;
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, NULL, &uvBuffer);
        assert(SUCCEEDED(hr));
    }
    D3D->GetDC()->VSSetConstantBuffers(2, 1, &uvBuffer);
}

void BlurImage::DeleteStaticMember()
{
    vertexBuffer->Release();
    uvBuffer->Release();
}

void BlurImage::PlayAnim()
{
    if (maxFrame.x == 1 && maxFrame.y == 1)
        return;

    if (animState != ANIMSTATE::STOP)
    {
        if (TIMER->GetTick(animTime, animInterval))
        {
            //재생간격이 지났을 때
            if (animXAxis) //가로재생
            {
                if (animState == ANIMSTATE::LOOP)
                {
                    frame.x++;
                    if (frame.x == maxFrame.x)
                    {
                        frame.x = 0;
                    }
                }
                else if (animState == ANIMSTATE::ONCE)
                {
                    frame.x++;
                    if (frame.x == maxFrame.x)
                    {
                        frame.x = maxFrame.x - 1;
                        animState = ANIMSTATE::STOP;
                    }
                }
                else if (animState == ANIMSTATE::REVERSE_LOOP)
                {
                    frame.x--;
                    if (frame.x == -1)
                    {
                        frame.x = maxFrame.x - 1;
                    }
                }
                else //REVERSE_ONCE
                {
                    frame.x--;
                    if (frame.x == -1)
                    {
                        frame.x = 0;
                        animState = ANIMSTATE::STOP;
                    }
                }
            }
            else //세로재생
            {
                if (animState == ANIMSTATE::LOOP)
                {
                    frame.y++;
                    if (frame.y == maxFrame.y)
                    {
                        frame.y = 0;
                    }
                }
                else if (animState == ANIMSTATE::ONCE)
                {
                    frame.y++;
                    if (frame.y == maxFrame.y)
                    {
                        frame.y = maxFrame.y - 1;
                        animState = ANIMSTATE::STOP;
                    }
                }
                else if (animState == ANIMSTATE::REVERSE_LOOP)
                {
                    frame.y--;
                    if (frame.y == -1)
                    {
                        frame.y = maxFrame.y - 1;
                    }
                }
                else //REVERSE_ONCE
                {
                    frame.y--;
                    if (frame.y == -1)
                    {
                        frame.y = 0;
                        animState = ANIMSTATE::STOP;
                    }
                }
            }
        }
    }

    if (maxFrame.x != 1)
    {
        uv.x = frame.x / (float)maxFrame.x;
        uv.z = (frame.x + 1.0f) / (float)maxFrame.x;
    }
    if (maxFrame.y != 1)
    {
        uv.y = frame.y / (float)maxFrame.y;
        uv.w = (frame.y + 1.0f) / (float)maxFrame.y;
    }
}

BlurImage::BlurImage(wstring file)
{
    //기본 샘플러 값
    samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

    samplerDesc.MipLODBias = 0.0f;
    samplerDesc.MaxAnisotropy = 1;
    samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    samplerDesc.MinLOD = -FLT_MAX;
    samplerDesc.MaxLOD = FLT_MAX;

    //하나 이상의 샘플러 만들어 두기
    D3D->GetDevice()->CreateSamplerState(&samplerDesc, &sampler);

    //텍스쳐 로드
    SRV = TEXTURE->LoadTexture(file);
    imageSize = TEXTURE->GetTextureSize(file);

    //           (최소좌표)   (최대좌표)
    uv = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
    ScratchImage* image = TEXTURE->GetTexture(file).image;

    pixels.resize(imageSize.x * imageSize.y);

    unsigned char* img = image->GetPixels();

    for (long long i = 0; i < pixels.size(); i++) {
        pixels[i].x = img[i * 3] / 250.f;
        pixels[i].y = img[i * 3 + 1] / 255.0f;
        pixels[i].z = img[i * 3 + 2] / 255.0f;
        pixels[i].w = 0.5f;
    }

    animTime = 0.0f;
    animInterval = 0.0f;
    animXAxis = true;
    maxFrame = Int2(1, 1);
    frame = Int2(0, 0);
    reverseLR = false;
    this->file = file;
}

BlurImage::~BlurImage()
{
    sampler->Release();
}

Vector4& BlurImage::GetPixel(int i, int j)
{
    i = clamp(i, 0, imageSize.x - 1);
    j = clamp(j, 0, imageSize.y - 1);

    return this->pixels[i + imageSize.x * j];
}

void BlurImage::Render()
{
    if (!isVisible)return;
    GameObject::Render();
    imageShader->Set();
    PlayAnim();
    BoxBlur5();


    size_t bufferSize = pixels.size() * sizeof(Vector4);

    // D3D11 버퍼 설명 구조체 설정
    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DYNAMIC;                   // 동적 사용 설정
    bufferDesc.ByteWidth = static_cast<UINT>(bufferSize);     // 버퍼 크기 설정 (픽셀 데이터의 전체 크기)
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;          // Vertex 버퍼로 사용할 경우, 필요한 경우 다른 용도로 설정 가능
    bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;       // CPU에서 쓰기 가능 설정
    bufferDesc.MiscFlags = 0;                                 // 추가 플래그 없음

    // uvBuffer 생성
    HRESULT hr = D3D->GetDevice()->CreateBuffer(&bufferDesc, nullptr, &uvBuffer);
    if (FAILED(hr)) {
        std::cerr << "Failed to create uvBuffer. HRESULT: " << hr << std::endl;
        return;  // 실패 시 예외 처리 또는 함수 종료
    }

    // 데이터를 GPU에 쓰기 위해 uvBuffer 매핑
    D3D11_MAPPED_SUBRESOURCE mappedResource;
    hr = D3D->GetDC()->Map(uvBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
    if (FAILED(hr)) {
        std::cerr << "Failed to map uvBuffer. HRESULT: " << hr << std::endl;
        return;  // 실패 시 예외 처리 또는 함수 종료
    }

    // pixels의 데이터를 uvBuffer에 복사
    memcpy_s(mappedResource.pData, bufferSize, pixels.data(), bufferSize);

    // 매핑 해제
    D3D->GetDC()->Unmap(uvBuffer, 0);


    UINT stride = sizeof(VertexPT);
    UINT offset = 0;

    D3D->GetDC()->PSSetShaderResources(0, 1, &SRV);
    D3D->GetDC()->PSSetSamplers(0, 1, &sampler);
    D3D->GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    D3D->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
    D3D->GetDC()->Draw(4, 0);
}

void BlurImage::ChangeAnim(ANIMSTATE anim, float interval, bool xAxis)
{
    animState = anim;
    animInterval = interval;
    animXAxis = xAxis;

    if (animState == ANIMSTATE::ONCE)
    {
        if (xAxis)
            frame.x = 0;
        else
            frame.y = 0;
    }
    else if (animState == ANIMSTATE::REVERSE_ONCE)
    {
        if (xAxis)
            frame.x = maxFrame.x - 1;
        else
            frame.y = maxFrame.y - 1;
    }
}

void BlurImage::ChangeSampler(D3D11_FILTER filter, D3D11_TEXTURE_ADDRESS_MODE addressU, D3D11_TEXTURE_ADDRESS_MODE addressV)
{
    SafeRelease(sampler);
    samplerDesc.Filter = filter;
    samplerDesc.AddressU = addressU;
    samplerDesc.AddressV = addressV;
    D3D->GetDevice()->CreateSamplerState(&samplerDesc, &sampler);
}

void BlurImage::BoxBlur5()
{
    std::vector<Vector4> pixelsBuffer(this->pixels.size());

    for (int j = 0; j < imageSize.y; j++)
    {
        for (int i = 0; i < imageSize.x; i++)
        {
            // 주변 픽셀들의 색을 평균내어서 (i, j)에 있는 픽셀의 색을 변경
            // this->pixels로부터 읽어온 값들을 평균내어서 pixelsBuffer의 값들을 바꾸기

            Color neighborColorSum{ 0.0f,0.0f,0.0f,0.5f };
            for (int si = 0; si < 5; si++)
            {
                Color neighborColor = this->GetPixel(i + si - 2, j);
                neighborColorSum.x += neighborColor.x;
                neighborColorSum.y += neighborColor.y;
                neighborColorSum.z += neighborColor.z;
            }

            pixelsBuffer[i + imageSize.x * j].x = neighborColorSum.x * 0.2f;
            pixelsBuffer[i + imageSize.x * j].y = neighborColorSum.y * 0.2f;
            pixelsBuffer[i + imageSize.x * j].z = neighborColorSum.z * 0.2f;
        }
    }
    std::swap(this->pixels, pixelsBuffer);

    for (int j = 0; j < imageSize.y; j++)
    {
        for (int i = 0; i < imageSize.x; i++)
        {
            // 주변 픽셀들의 색을 평균내어서 (i, j)에 있는 픽셀의 색을 변경
            // this->pixels로부터 읽어온 값들을 평균내어서 pixelsBuffer의 값들을 바꾸기
            Color neighborColorSum{ 0.0f,0.0f,0.0f,0.5f };
            for (int si = 0; si < 5; si++)
            {
                Color neighborColor = this->GetPixel(i, j + si - 2);
                neighborColorSum.x += neighborColor.x;
                neighborColorSum.y += neighborColor.y;
                neighborColorSum.z += neighborColor.z;
            }

            pixelsBuffer[i + imageSize.x * j].x = neighborColorSum.x * 0.2f;
            pixelsBuffer[i + imageSize.x * j].y = neighborColorSum.y * 0.2f;
            pixelsBuffer[i + imageSize.x * j].z = neighborColorSum.z * 0.2f;
        }
    }

    // Swap
    std::swap(this->pixels, pixelsBuffer);
}

