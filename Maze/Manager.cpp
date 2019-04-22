#include "Manager.hpp"



/// --------------------------------------------------------------------------------------------------
void Manager::SceneChange()
{
	// 今のシーン
	switch (BASICPARAM::e_nowScene)
	{
		// タイトル
	case ESceneNumber::TITLE:
		POINTER_RELEASE(p_baseMove);
		p_baseMove = new Title();
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


		// ゲーム
	case ESceneNumber::GAME:
		POINTER_RELEASE(p_baseMove);
		p_baseMove = new Game();
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


	default:
		break;
	}
}



/// --------------------------------------------------------------------------------------------------
Manager::Manager()
{
	// 初期化
	BASICPARAM::e_preScene = ESceneNumber::TITLE;
	BASICPARAM::e_nowScene = ESceneNumber::TITLE;


	// メモリの初期化
	p_baseMove = nullptr;
	p_baseMove = new Title();


	// ゲームに関する
	gameEnd = false;
}



/// --------------------------------------------------------------------------------------------------
Manager::~Manager()
{
	POINTER_RELEASE(p_baseMove);
}



/// --------------------------------------------------------------------------------------------------
void Manager::Update()
{
	// 今のシーンと直前のシーンが同じ
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
	{
		// ゲームに関する
		p_baseMove->Draw();


		// ゲームに関する
		p_baseMove->Process();


		// 直前のシーンと今のシーンを同じにする
		BASICPARAM::e_nowScene = p_baseMove->GetScene();
	}
	// シーンを移行するように指定されたら
	else
	{
		// シーンを変える
		SceneChange();


		// 直前のシーンと今のシーンを同じにする
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}