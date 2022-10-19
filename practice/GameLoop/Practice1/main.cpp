#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

#include "Title.h"
#include "Fade.h"

#include "GameLoop.h"


void ReportLiveObjects()
{
	IDXGIDebug* pDxgiDebug;

	typedef HRESULT(__stdcall* fPtr)(const IID&, void**);
	HMODULE hDll = GetModuleHandleW(L"dxgidebug.dll");
	fPtr DXGIGetDebugInterface = (fPtr)GetProcAddress(hDll, "DXGIGetDebugInterface");

	DXGIGetDebugInterface(__uuidof(IDXGIDebug), (void**)&pDxgiDebug);

	// �o�́B
	pDxgiDebug->ReportLiveObjects(DXGI_DEBUG_D3D12, DXGI_DEBUG_RLO_DETAIL);
}

void InitStandardIOConsole()
{

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONIN$", "r", stdin);

}

void CloseStandardIOConsole()
{
	FreeConsole();
}

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	//////////////////////////////////////
	// �������珉�������s���R�[�h���L�q����B
	//////////////////////////////////////
	//InitStandardIOConsole();

	//Game�N���X�̃I�u�W�F�N�g���쐬�B
	NewGO<Title>(0, "title");
	NewGO<Fade>(0, "fade");

	GameLoop gameLoop;
	g_engine->SetIsLimittedFPS(false);
	g_engine->SetIsShowFPS(false);

	//////////////////////////////////////
	// ���������s���R�[�h�������̂͂����܂ŁI�I�I
	//////////////////////////////////////
	
	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		if (g_pad[0]->IsTrigger(enButtonA) ){
			g_pad[0]->SetVibration(/*durationSec=*/0.5f, /*normalizedPower=*/1.0f);
		}
		gameLoop.Loop();
		//K2Engine::GetInstance()->Execute();
	}

	//CloseStandardIOConsole();
	K2Engine::DeleteInstance();

#ifdef _DEBUG
	ReportLiveObjects();
#endif // _DEBUG
	return 0;
}

