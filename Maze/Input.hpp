#pragma once
#include "DxLib.h"



// �L�[�{�[�h�̓��͏��
class KeyData
{
private:
	static int key[256];	// �L�[�̓��͏�Ԋi�[�p�ϐ�
	static char tmpKey[256];	// ���݂̃L�[�̓��͏�Ԃ��i�[����


public:
	KeyData();
	~KeyData();

	static void UpDate();	// �L�[���͂̏�ԍX�V
	static int Get(int KeyCode);	// �L�[���͏�Ԏ擾
	static bool CheckEnd();	// �����I��
};



// �Q�[���p�b�h�̓��͏��
class PadData {
private:
	static int button[4][16];  // �Q�[���p�b�h�̓��͏�Ԋi�[�p�ϐ�
	static XINPUT_STATE input[4];	// �Q�[���p�b�h�̃i���o�[
	static __int8 padNum;	// �q�����Ă�Q�[���p�b�h�̐�


public:
	PadData();
	~PadData();

	static void SetPadNum();
	static void UpDate();	// �Q�[���p�b�h�̓��͂̏�ԍX�V
	static int Get(int code, int padNum);	// �Q�[���p�b�h�̓��͏�Ԏ擾
	static bool CheckEnd();	// �����I��
};