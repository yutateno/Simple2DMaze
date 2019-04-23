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
	int* map[32];


	// マップ生成完了
	bool mapCreateEnd;



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

