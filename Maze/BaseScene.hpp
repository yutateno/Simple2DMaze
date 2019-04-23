#pragma once
#include "Basic.hpp"
#include <vector>


enum class MAPStep { None, Block, Start, Goal };


/*
���[�u�̑�{
*/
class BaseScene
{
protected:
	// �V�[���̏I���t���b�O
	static bool endFlag;

	// ���݂̃V�[��
	static ESceneNumber scene;


public:
	// �R���X�g���N�^
	BaseScene();

	// �f�X�g���N�^
	virtual ~BaseScene();

	// �`��
	virtual void Draw() = 0;

	// �v���Z�X
	virtual void Process() = 0;


	/// �Q�b�^�[�Z�b�^�[-------------------------------------------------

	// �I�����ǂ�����n��
	static const bool GetEndFlag() { return endFlag; }

	// ���̃V�[����n��
	static const ESceneNumber GetScene() { return scene; }

	// ���̃V�[���𓾂�
	void SetScene(const ESceneNumber scene) { this->scene = scene; }
};

