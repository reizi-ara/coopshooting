//リスト例
//Dxライブラリ使用
#pragma once
#include "main.h"
#include "char.h"

//リスト
//std::list<Bace*>bace;

//ユニークポインタを使ったリスト
list<unique_ptr<Bace>> bace;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//windowモードの切り替え
	ChangeWindowMode(TRUE);

	//windowサイズ
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)return -1;

	//windowの名前
	SetWindowText("リストサンプル");

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);

	//リストへオブジェクトを追加

	auto a = (unique_ptr<Bace>)new Player();
	bace.push_back(move(a));

	
	/*auto a = (Bace*)new Player();
	bace.push_back(a);*/

	for (int i= 0; i < 5; i++)
	{
		auto b = (unique_ptr<Bace>)new Enemy(i*1.0f,i*1.0f);
		bace.push_back(move(b));

	}

	//メインループ
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();//画面クリア

		//リストのメソッドを実行
		for (auto j = bace.begin(); j != bace.end(); j++)
		{
			((Player*)(*j).get())->Action(bace);
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			((Enemy*)(*i).get())->Action(bace);
		}

		for (auto j = bace.begin(); j != bace.end(); j++)
		{
			((Player*)(*j).get())->Draw();
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			((Enemy*)(*i).get())->Draw();
		}
		//for (auto i = bace.begin(); i != bace.end(); i++)
		//	(*i)->Action(&bace);//各オブジェクトの処理

		//for (auto i = bace.begin(); i != bace.end(); i++)
		//	(*i)->Draw();//各オブジェクトの描画処理

		//リストから要素を削除（IDがー９９９の時に削除）
		//for (auto i = bace.begin(); i != bace.end(); i++)
		//{
		//	if ((*i)->ID==-999)
		//	{
		//		//リストから削除
		//		delete(*i);
		//		i = bace.erase(i);
		//		break;
		//	}
		//}

		/*for (auto i = bace.begin(); i !=bace.end(); i++)
		{
			i = bace.erase(i);
			break;
		}*/

		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1))break;
	}

	DxLib_End();

	return 0;
}