#pragma once
#include "BaseScene.hpp"



/*
�Q�[������
*/
class Game : public BaseScene
{
private:
	// �w�i�摜
	int backGroundDraw;


	// �}�b�v
	int* map[32];



public:
	// �R�s�[�R���X�g���N�^
	Game(int** map);

	// �f�X�g���N�^
	~Game();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};

