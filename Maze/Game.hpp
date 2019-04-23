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


	// �v���C���[
	int player;


	// �v���C���[�ʒu
	int playX, playY;


	// �u���b�N
	int block;


	// �S�[��
	int goal;


	// �X�^�[
	int star;


	// �X�^�[�̍��W
	int starX[3];
	int starY[3];


	// �����Ȃ�����
	bool blind;


	// �}�b�v
	int* map[18];



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

