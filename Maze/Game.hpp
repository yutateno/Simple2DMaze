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



public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

