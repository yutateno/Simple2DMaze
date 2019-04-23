#include "End.hpp"



End::End()
{
	backGroundDraw = LoadGraph("media\\end.png");
}


End::~End()
{
	GRAPHIC_RELEASE(backGroundDraw);
}



void End::Draw()
{
	DrawGraph(0, 0, backGroundDraw, false);


	DrawFormatString(900, 500, 255, "����������肽����Z�{�^�������ȁI����I\n���Ȃ݂ɃV�[�h�l�Ȃ�ĈӖ��Ȃ���I���肳�I");
}



void End::Process()
{
	// �V�[���ړ�
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::TITLE);
	}
}
