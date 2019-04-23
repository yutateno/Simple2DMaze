#pragma once
#include "BaseScene.hpp"



/*
ゲーム部分
*/
class Game : public BaseScene
{
private:
	// 背景画像
	int backGroundDraw;


	// プレイヤー
	int player;


	// プレイヤー位置
	int playX, playY;


	// ブロック
	int block;


	// ゴール
	int goal;


	// スター
	int star;


	// スターの座標
	int starX[3];
	int starY[3];


	// 見えなくする
	bool blind;


	// マップ
	int* map[18];



public:
	// コピーコンストラクタ
	Game(int** map);

	// デストラクタ
	~Game();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

