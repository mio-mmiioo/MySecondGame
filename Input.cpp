#include "Input.h"

namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr; // デバイスオブジェクト
	BYTE keyState[256] = { 0 }; // 現在の各キーの状態
	BYTE prevKeyState[256];     //前フレームでの各キーの状態

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
	}

	void Update()
	{
		//memcpy(prevKeyState, keyState, sizeof(keyState)); // コピー先(ディスト) コピー元(ソース), サイズ

		for (int i = 0; i < 256; i++)
		{
			prevKeyState[i] = keyState[i];
		}

		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)
		{
			return true;
		}

		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//今は押してて、前回は押してない
		if ((keyState[keyCode] ^ prevKeyState[keyCode]) & keyState[keyCode])
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		//今は離してて、前回は押してる
		if ((keyState[keyCode] ^ prevKeyState[keyCode]) & prevKeyState[keyCode])
		{
			return true;
		}
		return false;
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
	}
}