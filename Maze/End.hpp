#pragma once
#include "BaseScene.hpp"



/*
エンディング部分
*/
class End : public BaseScene
{
private:
	// 背景画像
	int backGroundDraw;



public:
	// コピーコンストラクタ
	End();

	// デストラクタ
	~End();


	// 描画
	void Draw() override;

	// プロセス
	void Process() override;
};

