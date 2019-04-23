#include "Title.hpp"



/// --------------------------------------------------------------------------------------------------------------
Title::Title(int** map)
{
	backGroundDraw = LoadGraph("media\\title_back.png");
	for (int i = 0; i != std::extent<decltype(this->map), 0>::value; ++i)
	{
		this->map[i] = map[i];
	}

	mapCreateEnd = false;
}



/// --------------------------------------------------------------------------------------------------------------
Title::~Title()
{
	GRAPHIC_RELEASE(backGroundDraw);
}



/// --------------------------------------------------------------------------------------------------------------
void Title::Draw()
{
	DrawGraph(0, 0, backGroundDraw, false);

	for (int i = 0; i != std::extent<decltype(map), 0>::value; ++i)
	{
		for (int j = 0; j != 18; ++j)
		{
			DrawFormatString(1000 + i * 15, j * 15, 255, "%d", map[i][j]);
		}
	}
}



/// --------------------------------------------------------------------------------------------------------------
void Title::Process()
{
	/*while (!mapCreateEnd)
	{

	}*/


	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::GAME);
	}
}
