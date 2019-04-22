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



public:
	// コンストラクタ
	Title();

	// デストラクタ
	~Title();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

