#include "Input.hpp"



//////////////////////////////////////////////�L�[�{�[�h////////////////////////////////////////////////////
KeyData::KeyData()
{

}



KeyData::~KeyData()
{

}



int KeyData::key[256];
char KeyData::tmpKey[256];



void KeyData::UpDate()
{
	KeyData::tmpKey[256];			// ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(KeyData::tmpKey);	// �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++)
	{
		// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (KeyData::tmpKey[i] != 0)
		{
			KeyData::key[i]++;   // ���Z
		}
		// �L�[�������ꂽ�u��
		else if (KeyData::key[i] > 0)
		{
			KeyData::key[i] = -1; // -1�ɂ���
		}
		// ����ȊO
		else
		{
			KeyData::key[i] = 0; // 0�ɂ���
		}
	}
}



bool KeyData::CheckEnd()
{
	return KeyData::key[KEY_INPUT_ESCAPE] <= 0;
}



int KeyData::Get(int KeyCode)
{
	return KeyData::key[KeyCode];
}




//////////////////////////////////////////////�Q�[���p�b�h////////////////////////////////////////////////////



PadData::PadData()
{

}



PadData::~PadData()
{

}



int PadData::button[4][16];  // �Q�[���p�b�h�̓��͏�Ԋi�[�p�ϐ�
XINPUT_STATE PadData::input[4];	// �Q�[���p�b�h�̃i���o�[
__int8 PadData::padNum;



void PadData::SetPadNum()
{
	PadData::padNum = (__int8)GetJoypadNum();
}



void PadData::UpDate()
{
	for (int j = 0; j < PadData::padNum; j++)
	{
		// ���͏�Ԃ��擾
		GetJoypadXInputState(DX_INPUT_PAD1, &PadData::input[j]);
		for (int i = 0; i < 16; i++)
		{
			// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			if (PadData::input[j].Buttons[i] != 0)
			{
				PadData::button[j][i]++;   // ���Z
			}
			// �L�[�������ꂽ�u��
			else if (button[i] > 0)
			{
				PadData::button[j][i] = -1; // -1�ɂ���
			}
			// ����ȊO
			else
			{
				PadData::button[j][i] = 0; // 0�ɂ���
			}
		}
	}
}



// �Q�[���p�b�h�̓��͏�Ԏ擾
int PadData::Get(int code, int padNum)
{
	return PadData::button[padNum][code];
}



bool PadData::CheckEnd()
{
	return
	{
		(PadData::button[0][XINPUT_BUTTON_START] < 1 || PadData::button[0][XINPUT_BUTTON_BACK] < 1) &&
		(PadData::button[1][XINPUT_BUTTON_START] < 1 || PadData::button[1][XINPUT_BUTTON_BACK] < 1) &&
		(PadData::button[2][XINPUT_BUTTON_START] < 1 || PadData::button[2][XINPUT_BUTTON_BACK] < 1) &&
		(PadData::button[3][XINPUT_BUTTON_START] < 1 || PadData::button[3][XINPUT_BUTTON_BACK] < 1)
	};
}