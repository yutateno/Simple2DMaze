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
	int* map[18];


	// �}�b�v�������̍��W�ʒu
	int mapX, mapY;


	// �}�b�v�����܂ł̃J�E���g
	int mapCreateCount;


	// �}�b�v��������
	bool mapCreateEnd;


	// ���l���͕ێ��ϐ�
	int line;
	int lineMath;



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

