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



public:
	// �R���X�g���N�^
	Title();

	// �f�X�g���N�^
	~Title();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};

