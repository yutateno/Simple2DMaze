#include "Manager.hpp"



/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウィンドウサイズを決める
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ログテキスト出力する
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ログテキスト出力しない
#endif


	SetWindowText("MazeMediumRiver");					// メインウインドウのウインドウタイトルを変更する
	SetBackgroundColor(0, 0, 0);			// 背景色を白に変更
	ChangeWindowMode(TRUE);						// ウィンドウズモードにさせる
	SetWindowIconID(333);


	SetGraphMode(BASICPARAM::winWidth, BASICPARAM::winHeight, BASICPARAM::bitColor);			// 画面サイズ設定
	GetDefaultState(&BASICPARAM::winWidth, &BASICPARAM::winHeight, &BASICPARAM::bitColor);		// デフォルトウィンドウ値を得る
	SetWindowSize(BASICPARAM::winWidth, BASICPARAM::winHeight);									// デフォルトウィンドウサイズに合わせてゲームサイズを変更


	// 画面サイズに戻す
	BASICPARAM::winWidth = 1920;
	BASICPARAM::winHeight = 1080;
	BASICPARAM::bitColor = 32;


	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;			// エラーが起きたら直ちに終了
	}


	SetAlwaysRunFlag(TRUE);			// 裏でもアクティブにする
	SetMouseDispFlag(FALSE);		// マウスカーソルを非表示にする


	Manager p_manager = Manager();


	SetDrawScreen(DX_SCREEN_BACK);	// 背景描画


	// ゲームの核
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !p_manager.GetEnd())
	{
		ClearDrawScreen();

		p_manager.Update();

		ScreenFlip();
	} /// while


	p_manager.~Manager();


	InitGraph();					// 画像解放


	DxLib_End();		// DXライブラリの後始末


	return 0;
}