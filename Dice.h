#pragma once
//#include "Direct3D.h"
//#include <DirectXMath.h>
//#include "Texture.h"

#include "Quad.h"

using namespace DirectX;

////�R���X�^���g�o�b�t�@�[
//struct CONSTANT_BUFFER
//{
//	XMMATRIX	matWVP;
//};
//
////���_���
//struct VERTEX
//{
//	XMVECTOR position;
//	XMFLOAT2 uv;
//	XMVECTOR normal;
//};

class Dice : public Quad
{
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//�C���f�b�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;

public:
	Dice();
	~Dice();
	HRESULT Initialize();
	void Draw(XMMATRIX& worldMatrix);
	void Release();
};
