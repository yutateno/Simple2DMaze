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



public:
	// �R���X�g���N�^
	Game();

	// �f�X�g���N�^
	~Game();


	// �`��
	void Draw() override;

	// �v���Z�X
	void Process() override;
};

