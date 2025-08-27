#include "Transform.h"

Transform::Transform()
	: pParent_(nullptr)
{
	matTranslate_ = XMMatrixIdentity();
	matRotate_ = XMMatrixIdentity();
	matScale_ = XMMatrixIdentity();
	position_ = { 0, 0, 0 };
	rotate_ = { 0, 0, 0 };
	scale_ = { 1, 1, 1 };

}

Transform::~Transform()
{
}

void Transform::Calclation()
{
	//ˆÚ“®
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

	//‰ñ“]
	XMMATRIX rotateX;
	XMMATRIX rotateY;
	XMMATRIX rotateZ;

	rotateX = XMMatrixRotationX(rotate_.x);
	rotateY = XMMatrixRotationY(rotate_.y);
	rotateZ = XMMatrixRotationZ(rotate_.z);
	matRotate_ = rotateZ * rotateX * rotateY;

	//k¬
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
	Calclation();
	if (pParent_)
	{
		return  matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();
	}
	return  matScale_ * matRotate_ * matTranslate_;
}