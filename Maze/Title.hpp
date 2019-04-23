#pragma once
#include "BaseScene.hpp"



/*
ゲーム部分
*/
class Title : public BaseScene
{
private:
	// 背景画像
	int backGroundDraw;


	// マップ
	int* map[18];


	// マップ生成時の座標位置
	int mapX, mapY;


	// マップ生成までのカウント
	int mapCreateCount;


	// マップ生成完了
	bool mapCreateEnd;


	// 数値入力保持変数
	int line;
	int lineMath;



public:
	// コピーコンストラクタ
	Title(int** map);

	// デストラクタ
	~Title();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

