#pragma once
#include "BaseScene.hpp"



/*
�Q�[������
*/
class Title : public BaseScene
{
private:
	// �w�i�摜
	int backGroundDraw;


	// �}�b�v
	int* map[32];


	// �}�b�v��������
	bool mapCreateEnd;



public:
	// �R�s�[�R���X�g���N�^
	Title(int** map);

	// �f�X�g���N�^
	~Title();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};

