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
	matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z); //�ړ�
	matRotate_ = XMMatrixRotationRollPitchYaw(rotate_.x, rotate_.y, rotate_.z); //��]
	matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);					//�g�k
}

XMMATRIX Transform::GetWorldMatrix()
{
	Calculation();
	return  matScale_ * matRotate_ * matTranslate_;
}