#include "Title.hpp"
#include <random>



/// --------------------------------------------------------------------------------------------------------------
Title::Title(int** map)
{
	backGroundDraw = LoadGraph("media\\title_back.png");
	for (int i = 0; i != std::extent<decltype(this->map), 0>::value; ++i)
	{
		this->map[i] = map[i];
	}

	mapCreateEnd = false;

	mapX = 0;
	mapY = 0;

	line= MakeKeyInput(1000, TRUE, TRUE, TRUE);
	lineMath = 0;

	mapCreateCount = 0;
}



/// --------------------------------------------------------------------------------------------------------------
Title::~Title()
{
	GRAPHIC_RELEASE(backGroundDraw);
	DeleteKeyInput(line);
}



/// --------------------------------------------------------------------------------------------------------------
void Title::Draw()
{
	DrawGraph(0, 0, backGroundDraw, false);


	if (!mapCreateEnd)
	{
		if (CheckKeyInput(line) == 0)
		{
			DrawFormatString(900, 500, 255, "スペースを押しながらシード値を決め、エンターキーを押してください。");
		}
		else
		{
			DrawFormatString(900, 550, 255, "%dが入力されました。マップを生成します。", lineMath);
		}
	}
	else
	{
		DrawFormatString(900, 600, 255, "マップが生成されました。Zボタンでゲームを始めてください。");
	}
}



/// --------------------------------------------------------------------------------------------------------------
void Title::Process()
{
	// 数値入力
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && CheckKeyInput(line) == 0)
	{
		// 作成したキー入力ハンドルをアクティブにする
		SetActiveKeyInput(line);

		DrawBox(890, 540, 1060, 580, GetColor(0, 0, 0), true);

		// 入力途中の文字列を描画
		DrawKeyInputString(900, 550, line);
	}
	if (CheckKeyInput(line) != 0)
	{
		lineMath = GetKeyInputNumber(line);
		mapCreateCount++;
	}


	// マップ生成
	if (mapCreateCount >= 60)
	{
		std::random_device rnd;     // 非決定的な乱数生成器を生成
		std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
		for (int i = 0; i != 10000; ++i)
		{
			std::uniform_int_distribution<> rand03(1, 2);        // [0, 99] 範囲の一様乱数
			switch (rand03(mt))
			{
			case 1:
				if (mapX != 31)
				{
					if (map[mapY][mapX + 1] == -1)
					{
						map[mapY][++mapX] = 0;
					}
				}
				break;

			case 2:
				if (mapY != 17)
				{
					if (map[mapY + 1][mapX] == -1)
					{
						map[++mapY][mapX] = 0;
					}
				}
				break;

			default:
				break;
			}


			for (int i = 0; i != 26; ++i)
			{
				if (map[17][i] == 0)
				{
					mapX = 0;
					mapY = 0;

					for (int i = 0; i != 18; ++i)
					{
						for (int j = 0; j != 32; ++j)
						{
							map[i][j] = -1;
						}
					}
					break;
				}
			}

			for (int i = 5; i != 10; ++i)
			{
				if (map[i][0] == 0)
				{
					mapX = 0;
					mapY = 0;

					for (int i = 0; i != 18; ++i)
					{
						for (int j = 0; j != 32; ++j)
						{
							map[i][j] = -1;
						}
					}
					break;
				}
			}
		}

		std::uniform_int_distribution<> rand01(0, 1);        // [0, 99] 範囲の一様乱数
		for (int i = 0; i != 18; ++i)
		{
			for (int j = 0; j != 32; ++j)
			{
				if (map[i][j] != -1) continue;
				map[i][j] = rand01(mt);
			}
		}

		map[0][0] = 2;
		map[17][31] = 3; 
		mapCreateEnd = true;
	}


	// シーン移動
	if (mapCreateEnd && CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::GAME);
	}
}
