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
			DrawFormatString(900, 500, 255, "�X�y�[�X�������Ȃ���V�[�h�l�����߁A�G���^�[�L�[�������Ă��������B");
		}
		else
		{
			DrawFormatString(900, 550, 255, "%d�����͂���܂����B�}�b�v�𐶐����܂��B", lineMath);
		}
	}
	else
	{
		DrawFormatString(900, 600, 255, "�}�b�v����������܂����BZ�{�^���ŃQ�[�����n�߂Ă��������B");
	}
}



/// --------------------------------------------------------------------------------------------------------------
void Title::Process()
{
	// ���l����
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && CheckKeyInput(line) == 0)
	{
		// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
		SetActiveKeyInput(line);

		DrawBox(890, 540, 1060, 580, GetColor(0, 0, 0), true);

		// ���͓r���̕������`��
		DrawKeyInputString(900, 550, line);
	}
	if (CheckKeyInput(line) != 0)
	{
		lineMath = GetKeyInputNumber(line);
		mapCreateCount++;
	}


	// �}�b�v����
	if (mapCreateCount >= 60)
	{
		std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
		std::mt19937 mt(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
		for (int i = 0; i != 10000; ++i)
		{
			std::uniform_int_distribution<> rand03(1, 2);        // [0, 99] �͈͂̈�l����
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

		std::uniform_int_distribution<> rand01(0, 1);        // [0, 99] �͈͂̈�l����
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


	// �V�[���ړ�
	if (mapCreateEnd && CheckHitKey(KEY_INPUT_Z) == 1)
	{
		BaseScene::SetScene(ESceneNumber::GAME);
	}
}
