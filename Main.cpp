//�C���N���[�h
//#include "framework.h"
//#include "main.h"
//#include <Windows.h>
#include "Direct3D.h"
#include "Input.h"
#include "Camera.h"
//#include "Dice.h"
//#include "Sprite.h"
#include "Transform.h"
#include "Fbx.h"

#define MAX_LOADSTRING 100

//�萔�錾
const char* WIN_CLASS_NAME = "SampleGame";  //�E�B���h�E�N���X��
const int WINDOW_WIDTH = 800;  //�E�B���h�E�̕�
const int WINDOW_HEIGHT = 600; //�E�B���h�E�̍���B

//�v���g�^�C�v�錾
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//�G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�N���X�i�݌v�}�j���쐬
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);             //���̍\���̂̃T�C�Y
	wc.hInstance = hInstance;                   //�C���X�^���X�n���h��
	wc.lpszClassName = WIN_CLASS_NAME;            //�E�B���h�E�N���X��
	wc.lpfnWndProc = WndProc;                   //�E�B���h�E�v���V�[�W��
	wc.style = CS_VREDRAW | CS_HREDRAW;         //�X�^�C���i�f�t�H���g�j
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //�A�C�R��
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //�������A�C�R��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //�}�E�X�J�[�\��
	wc.lpszMenuName = NULL;                     //���j���[�i�Ȃ��j
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //�w�i�i���j
	RegisterClassEx(&wc);  //�N���X��o�^
	
	//�E�B���h�E�T�C�Y�̌v�Z
	RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //�E�B���h�E��
	int winH = winRect.bottom - winRect.top;     //�E�B���h�E����

	//�E�B���h�E���쐬
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,         //�E�B���h�E�N���X��
		"�T���v���Q�[��",     //�^�C�g���o�[�ɕ\��������e
		WS_OVERLAPPEDWINDOW, //�X�^�C���i���ʂ̃E�B���h�E�j
		CW_USEDEFAULT,       //�\���ʒu���i���܂����j
		CW_USEDEFAULT,       //�\���ʒu��i���܂����j
		winW,                 //�E�B���h�E��
		winH,                 //�E�B���h�E����
		NULL,                //�e�E�C���h�E�i�Ȃ��j
		NULL,                //���j���[�i�Ȃ��j
		hInstance,           //�C���X�^���X
		NULL                 //�p�����[�^�i�Ȃ��j
	);
	//�E�B���h�E��\��
	ShowWindow(hWnd, nCmdShow);

	//Direct3D������
	if (FAILED(Direct3D::Initialize(winW, winH, hWnd)))
	{
		return 0;
	}

	//DiewctInput�̏�����
	Input::Initialize(hWnd);

	Camera::Initialize();

	//Dice* dice = new Dice();
	//Sprite* sprite = new Sprite();
	static Transform transform;
	Fbx* fbx = new Fbx();
	fbx->Load("oden.fbx");
	//if (FAILED(dice->Initialize()))
	//{
	//	return 0;
	//}
	//if (FAILED(sprite->Initialize()))
	//{
	//	return 0;
	//}

	float right = 0;
	float up = 0;
	//���b�Z�[�W���[�v�i�����N����̂�҂j
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//���b�Z�[�W����
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//���b�Z�[�W�Ȃ�
		else
		{
			//�Q�[���̏���
			Camera::Update();
			//���͏��̍X�V
			Input::Update();

			if (Input::IsKeyDown(DIK_ESCAPE))
			{
				static int cnt = 0;
				cnt++;
				if (cnt >= 3)
				{
					PostQuitMessage(0);
				}
			}

			if (GetAsyncKeyState('A') & 0x8000)
			{
				right += 0.01f;
				if (right >= 360)
				{
					right = 0;
				}
			}
			if (GetAsyncKeyState('W') & 0x8000)
			{
				up += 0.01f;
				if (up >= 360)
				{
					up = 0;
				}
			}

			Direct3D::BeginDraw();

			//������transform�ς���
			//transform.scale_.x = 0.5f;
			//transform.rotate_.y += 0.01f;
			//transform.rotate_.z += 0.01f;

			//XMMATRIX worldMatrix = transform.GetWorldMatrix();
			//sprite->Draw(worldMatrix);
			//dice->Draw(worldMatrix);

			//transform.position_.x = 1.0f;
			//transform.rotate_.y += 0.01f;
			//transform.Calculation();
			
			// XMMATRIX Mtrs = trans.GetWorldMatrix();
			//sprite->Draw(Mtrs);
			fbx->Draw(transform);

			//�`�揈��
			Direct3D::EndDraw();

		}
	}

	//SAFE_DELETE(dice);
	//SAFE_DELETE(sprite);
	SAFE_DELETE(fbx);
	Input::Release();
	Direct3D::Release();

	return 0;
}

//�E�B���h�E�v���V�[�W���i�������������ɂ�΂��֐��j
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);  //�v���O�����I��
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
