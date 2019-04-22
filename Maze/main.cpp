#include "Manager.hpp"



/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�B���h�E�T�C�Y�����߂�
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ���O�e�L�X�g�o�͂���
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ���O�e�L�X�g�o�͂��Ȃ�
#endif


	SetWindowText("MazeMediumRiver");					// ���C���E�C���h�E�̃E�C���h�E�^�C�g����ύX����
	SetBackgroundColor(0, 0, 0);			// �w�i�F�𔒂ɕύX
	ChangeWindowMode(TRUE);						// �E�B���h�E�Y���[�h�ɂ�����
	SetWindowIconID(333);


	SetGraphMode(BASICPARAM::winWidth, BASICPARAM::winHeight, BASICPARAM::bitColor);			// ��ʃT�C�Y�ݒ�
	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// �f�t�H���g�E�B���h�E�l�𓾂�
	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);									// �f�t�H���g�E�B���h�E�T�C�Y�ɍ��킹�ăQ�[���T�C�Y��ύX


	// ��ʃT�C�Y�ɖ߂�
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}


	SetAlwaysRunFlag(TRUE);			// ���ł��A�N�e�B�u�ɂ���
	SetMouseDispFlag(FALSE);		// �}�E�X�J�[�\�����\���ɂ���


	Manager p_manager = Manager();


	SetDrawScreen(DX_SCREEN_BACK);	// �w�i�`��


	// �Q�[���̊j
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !p_manager.GetEnd())
	{
		ClearDrawScreen();

		p_manager.Update();

		ScreenFlip();
	} /// while


	p_manager.~Manager();


	InitGraph();					// �摜���


	DxLib_End();		// DX���C�u�����̌�n��


	return 0;
}