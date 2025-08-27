#include "Fbx.h"
#include "Direct3D.h"

Fbx::Fbx()
	:vertexCount_(-1), 
	polygonCount_(-1)
{
}

HRESULT Fbx::Load(std::string fileName)
{
	return E_NOTIMPL;
}

void Fbx::Draw(Transform& transform)
{
}

void Fbx::Release()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}
