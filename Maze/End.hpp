#pragma once
#include "BaseScene.hpp"



/*
�G���f�B���O����
*/
class End : public BaseScene
{
private:
	// �w�i�摜
	int backGroundDraw;



public:
	// �R�s�[�R���X�g���N�^
	End();

	// �f�X�g���N�^
	~End();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};

