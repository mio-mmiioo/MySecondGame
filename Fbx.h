#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"


#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

class Fbx
{
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matNormal;
	};
	struct VERTEX
	{
		XMVECTOR position;
	};

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;

	int vertexCount_;
	int polygonCount_;

public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

	void InitVertex(FbxMesh* mesh);
	void InitIndex(FbxMesh* mesh);
	void InitConstantBuffer();
};

//#pragma once
//
//#include <d3d11.h>
//#include <fbxsdk.h>
//#include <string>
//#include "Transform.h"
//
//#pragma comment(lib, "LibFbxSDK-MT.lib")
//#pragma comment(lib, "LibXml2-MT.lib")
//#pragma comment(lib, "zlib-MT.lib")
//
//class Fbx
//{
//	struct CONSTANT_BUFFER
//	{
//		XMMATRIX	matWVP;
//		XMMATRIX	matNormal;
//	};
//
//	struct VERTEX
//	{
//		XMVECTOR position;
//	};
//
//	int vertexCount_;	//頂点数
//	int polygonCount_;	//ポリゴン数
//
//	ID3D11Buffer* pVertexBuffer_;//頂点バッファ
//	ID3D11Buffer* pIndexBuffer_;//インデックスバッファ
//	ID3D11Buffer* pConstantBuffer_;//コンスタントバッファ
//
//public:
//
//	Fbx();
//	HRESULT Load(std::string fileName);
//	void Draw(Transform& transform);
//	void Release();
//	void InitVertex(fbxsdk::FbxMesh* mesh);
//	void InitIndex(fbxsdk::FbxMesh* mesh);
//};