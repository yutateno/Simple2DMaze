#pragma once

/*
��{
*/

/// �C���N���[�h�t�@�C��--------------------------------------------------------
#include "DxLib.h"
#include <vector>


/// �F��ȏ��Ŏg�������Ȃ���----------------------------------------------------

// �V�[���̓���
enum class ESceneNumber
{
	TITLE, GAME
};


namespace BASICPARAM
{
	// ���O�̃V�[��
	extern ESceneNumber e_preScene;

	// ���̃V�[��
	extern ESceneNumber e_nowScene;


	// �E�B���h�E�T�C�Y
	extern int winWidth;
	extern int winHeight;
	extern int bitColor;
}


/// �}�N��-------------------------------------------------------------------------------------

// �|�C���^�p����}�N��
#define POINTER_RELEASE(p) { if(p!=nullptr) {delete p; (p)=nullptr; } }

// 2D�֘A�摜����}�N��
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); (p)=-1; } }

// ������}�N��
#define SOUND_RELEASE(p) { if(p!=-1) { StopSoundMem(p); DeleteSoundMem(p); (p)=-1; } }

