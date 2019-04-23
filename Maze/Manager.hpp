#pragma once
#include "BaseScene.hpp"

#include "Title.hpp"
#include "Game.hpp"



/*
�Q�[���̑�{
*/
class Manager
{
private:
	/// �e�V�[���Ɋւ���-----------------------------------------------------
	// �V�[���̊��N���X
	BaseScene* p_baseMove;

	// �V�[����؂�ւ���
	void SceneChange();


	/// �Q�[���Ɋւ���-----------------------------------------------------------

	// �Q�[�����I������
	bool gameEnd;

	// �}�b�v
	int map[32][18];
	int* tempMap[32];


public:
	// �R���X�g���N�^
	Manager();

	// �f�X�g���N�^
	~Manager();


	// ���C���v���Z�X
	void Update();

	// �Q�[�����I�����邩�ǂ���
	const bool GetEnd() const { return gameEnd; }
};
