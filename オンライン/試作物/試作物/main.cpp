//リスト例
//Dxライブラリ使用
#pragma once
#include "main.h"
#include "char.h"

//リスト
std::list<Bace*>bace;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//windowモード切替
	ChangeWindowMode(TRUE);
	//windowサイズ
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)return -1;

	//windowの名前
	SetWindowText("リストサンプル");

	//バックバッファを使用
	SetDrawScreen(DX_SCREEN_BACK);
	
	//リストオブジェクトを追加
	auto a = (Bace*)new Player();
	bace.push_back(a);

	for (int i = 0; i < 5; i++) {
		auto a = (Bace*)new Enemy(i * 3.0f, i * 5.0f);
		bace.push_back(a);
	}

	//メインループ
	while (CheckHitKey(KEY_INPUT_ESCAPE)==0){
		ClearDrawScreen();//画面クリア

		//リストのメソッドを実行
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(&bace);//各オブジェクトの処理
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//各オブジェクトの処理
		}


		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1)) break;
	}
	return 0;

}
