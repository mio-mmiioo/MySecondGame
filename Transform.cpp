#include "Transform.h"

Transform::Transform()
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

void Transform::Calculation()
{
	////ˆÚ“®
	//matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

	////‰ñ“]
	//XMMATRIX rotateX;
	//XMMATRIX rotateY;
	//XMMATRIX rotateZ;

	//rotateX = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
	//rotateY = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
	//rotateZ = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
	//matRotate_ = rotateZ * rotateX * rotateY;

	////k¬
	//matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);

	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);
	matRotate_ = XMMatrixRotationRollPitchYaw(rotate_.x, rotate_.y, rotate_.z);
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
	Calculation();
	//if (pParent_)
	//{
	//	return  matScale_ * matRotate_ * matTranslate_ * pParent_->GetWorldMatrix();
	//}
	return  matScale_ * matRotate_ * matTranslate_;
}