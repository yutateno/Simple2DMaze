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


	DrawFormatString(900, 500, 255, "もっかいやりたきゃZボタン押しな！やるよ！\nちなみにシード値なんて意味ないよ！飾りさ！");
}



void End::Process()
{
	// シーン移動
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::TITLE);
	}
}
