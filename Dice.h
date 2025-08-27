#pragma once
//#include "Direct3D.h"
//#include <DirectXMath.h>
//#include "Texture.h"

#include "Quad.h"

using namespace DirectX;

////コンスタントバッファー
//struct CONSTANT_BUFFER
//{
//	XMMATRIX	matWVP;
//};
//
////頂点情報
//struct VERTEX
//{
//	XMVECTOR position;
//	XMFLOAT2 uv;
//	XMVECTOR normal;
//};

class Dice : public Quad
{
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

	Texture* pTexture_;

public:
	Dice();
	~Dice();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};
