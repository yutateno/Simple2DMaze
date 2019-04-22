#pragma once

/*
大本
*/

/// インクルードファイル--------------------------------------------------------
#include "DxLib.h"
#include <vector>


/// 色んな所で使いそうなもの----------------------------------------------------

// シーンの動き
enum class ESceneNumber
{
	TITLE, GAME
};


namespace BASICPARAM
{
	// 直前のシーン
	extern ESceneNumber e_preScene;

	// 今のシーン
	extern ESceneNumber e_nowScene;


	// ウィンドウサイズ
	extern int winWidth;
	extern int winHeight;
	extern int bitColor;
}


/// マクロ-------------------------------------------------------------------------------------

// ポインタ用解放マクロ
#define POINTER_RELEASE(p) { if(p!=nullptr) {delete p; (p)=nullptr; } }

// 2D関連画像解放マクロ
#define GRAPHIC_RELEASE(p) { if(p!=-1) { DeleteGraph(p); (p)=-1; } }

// 音解放マクロ
#define SOUND_RELEASE(p) { if(p!=-1) { StopSoundMem(p); DeleteSoundMem(p); (p)=-1; } }

