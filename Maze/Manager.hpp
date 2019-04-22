#pragma once
#include "BaseScene.hpp"

#include "Title.hpp"
#include "Game.hpp"



/*
ゲームの大本
*/
class Manager
{
private:
	/// 各シーンに関する-----------------------------------------------------
	// シーンの基底クラス
	BaseScene* p_baseMove;

	// シーンを切り替える
	void SceneChange();


	/// ゲームに関する-----------------------------------------------------------

	// ゲームを終了する
	bool gameEnd;


public:
	// コンストラクタ
	Manager();

	// デストラクタ
	~Manager();


	// メインプロセス
	void Update();

	// ゲームを終了するかどうか
	const bool GetEnd() const { return gameEnd; }
};
