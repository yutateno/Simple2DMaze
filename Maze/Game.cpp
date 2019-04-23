#include "Game.hpp"



/// --------------------------------------------------------------------------------------------------------------
Game::Game(int** map)
{
	backGroundDraw = LoadGraph("media\\game.png");
	for (int i = 0; i != std::extent<decltype(this->map), 0>::value; ++i)
	{
		this->map[i] = map[i];
	}
}



/// --------------------------------------------------------------------------------------------------------------
Game::~Game()
{
	GRAPHIC_RELEASE(backGroundDraw);
}



/// --------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
	DrawGraph(0, 0, backGroundDraw, false);

	for (int i = 0; i != std::extent<decltype(map), 0>::value; ++i)
	{
		for (int j = 0; j != 18; ++j)
		{
			DrawFormatString(1000 + i * 5, j * 5, 255, "%d", map[i][j]);
		}
	}
}



/// --------------------------------------------------------------------------------------------------------------
void Game::Process()
{
	if (CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::TITLE);
	}
}
