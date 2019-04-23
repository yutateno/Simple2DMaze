#pragma once
#include "Basic.hpp"
#include <vector>


enum class MAPStep { None, Block, Start, Goal };


/*
ムーブの大本
*/
class BaseScene
{
protected:
	// シーンの終了フラッグ
	static bool endFlag;

	// 現在のシーン
	static ESceneNumber scene;


public:
	// コンストラクタ
	BaseScene();

	// デストラクタ
	virtual ~BaseScene();

	// 描画
	virtual void Draw() = 0;

	// プロセス
	virtual void Process() = 0;


	/// ゲッターセッター-------------------------------------------------

	// 終了かどうかを渡す
	static const bool GetEndFlag() { return endFlag; }

	// 今のシーンを渡す
	static const ESceneNumber GetScene() { return scene; }

	// 今のシーンを得る
	void SetScene(const ESceneNumber scene) { this->scene = scene; }
};

