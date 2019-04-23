#include "Game.hpp"
#include "Input.hpp"



/// --------------------------------------------------------------------------------------------------------------
Game::Game(int** map)
{
	backGroundDraw = LoadGraph("media\\game.png");
	for (int i = 0; i != std::extent<decltype(this->map), 0>::value; ++i)
	{
		this->map[i] = map[i];
	}

	player = LoadGraph("media\\player.png");
	playX = 0;
	playY = 0;

	block = LoadGraph("media\\block.png");

	goal = LoadGraph("media\\goal.png");

	star = LoadGraph("media\\star.png");

	for (int i = 0; i != 3; ++i)
	{
		starX[i] = -3;
		starY[i] = -3;
	}
}



/// --------------------------------------------------------------------------------------------------------------
Game::~Game()
{
	GRAPHIC_RELEASE(backGroundDraw);
	GRAPHIC_RELEASE(player);
	GRAPHIC_RELEASE(block);
	GRAPHIC_RELEASE(goal);
	GRAPHIC_RELEASE(star);
}



/// --------------------------------------------------------------------------------------------------------------
void Game::Draw()
{
	DrawGraph(0, 0, backGroundDraw, false);


	for (int i = 0; i != std::extent<decltype(map), 0>::value; ++i)
	{
		for (int j = 0; j != 32; ++j)
		{
			blind = false;
			if (playX - 2 > j || playX + 2 < j || playY - 2 > i || playY + 2 < i)
			{
				blind = true;
				if ((starX[0] - 2 <= j && starX[0] + 2 >= j) && (starY[0] - 2 <= i && starY[0] + 2 >= i))
				{
					blind = false;
				}
				if ((starX[1] - 2 <= j && starX[1] + 2 >= j) && (starY[1] - 2 <= i && starY[1] + 2 >= i))
				{
					blind = false;
				}
				if ((starX[2] - 2 <= j && starX[2] + 2 >= j) && (starY[2] - 2 <= i && starY[2] + 2 >= i))
				{
					blind = false;
				}
			}


			if (blind) continue;


			switch (map[i][j])
			{
			case static_cast<int>(MAPStep::Block) :
				DrawGraph(j * 60, i * 60, block, false);
				break;

			case static_cast<int>(MAPStep::Goal):
				DrawGraph(j * 60, i * 60, goal, false);
				break;

			case static_cast<int>(MAPStep::Start):
				break;

			case static_cast<int>(MAPStep::None):
				break;
			
			default:
				break;
			}
		}
	}


	for (int i = 0; i != 3; ++i)
	{
		DrawGraph(starX[i] * 60, starY[i] * 60, star, true);
	}


	DrawGraph(playX * 60, playY * 60, player, true);
}



/// --------------------------------------------------------------------------------------------------------------
void Game::Process()
{
	if (KeyData::Get(KEY_INPUT_W) == 1 || PadData::Get(XINPUT_BUTTON_DPAD_UP, 0) == 1)
	{
		if (playY != 0)
		{
			if (map[playY - 1][playX] != static_cast<int>(MAPStep::Block))
			{
				playY--;
			}
		}
	}
	if (KeyData::Get(KEY_INPUT_S) == 1 || PadData::Get(XINPUT_BUTTON_DPAD_DOWN, 0) == 1)
	{
		if (playY != 17)
		{
			if (map[playY + 1][playX] != static_cast<int>(MAPStep::Block))
			{
				playY++;
			}
		}
	}
	if (KeyData::Get(KEY_INPUT_A) == 1 || PadData::Get(XINPUT_BUTTON_DPAD_LEFT, 0) == 1)
	{
		if (playX != 0)
		{
			if (map[playY][playX - 1] != static_cast<int>(MAPStep::Block))
			{
				playX--;
			}
		}
	}
	if (KeyData::Get(KEY_INPUT_D) == 1 || PadData::Get(XINPUT_BUTTON_DPAD_RIGHT, 0) == 1)
	{
		if (playX != 31)
		{
			if (map[playY][playX + 1] != static_cast<int>(MAPStep::Block))
			{
				playX++;
			}
		}
	}


	if (playX == 31 && playY == 17)
	{
		BaseScene::SetScene(ESceneNumber::END);
	}


	if (KeyData::Get(KEY_INPUT_E) == 1 || PadData::Get(XINPUT_BUTTON_A, 0) == 1)
	{
		if (starX[0] == -3)
		{
			starX[0] = playX;
			starY[0] = playY;
		}
	}


	if (KeyData::Get(KEY_INPUT_R) == 1 || PadData::Get(XINPUT_BUTTON_B, 0) == 1)
	{
		if (starX[1] == -3)
		{
			starX[1] = playX;
			starY[1] = playY;
		}
	}


	if (KeyData::Get(KEY_INPUT_T) == 1 || PadData::Get(XINPUT_BUTTON_X, 0) == 1)
	{
		if (starX[2] == -3)
		{
			starX[2] = playX;
			starY[2] = playY;
		}
	}
}
