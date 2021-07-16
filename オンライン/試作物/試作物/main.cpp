//リスト例
//Dxライブラリ使用
#pragma once
#include "main.h"
#include "char.h"

//リスト
list<unique_ptr<Bace>> bace;

int spawn_time = 0;



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

	//リストオブジェクトを生成
	auto a = (unique_ptr<Bace>)new Player();
	bace.emplace_back(move(a));

<<<<<<< Updated upstream
	int time = 0;
	int ID =0;
	
	auto b = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f,1,5.0f,3.0f);
	bace.emplace_back(move(b));
=======
	//直線で進む敵
	/*auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f,1,0.0f,1.5f,0.0f);
	bace.emplace_back(move(e1));
>>>>>>> Stashed changes

	auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f,0.0f);
	bace.emplace_back(move(e2));*/

	//右斜め前に進む敵
	/*auto e3 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 3, 2.5f, 1.0f, 0.0f);
	bace.emplace_back(move(e3));

	//左斜め前に進む敵
	auto e4 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 0.0f);
	bace.emplace_back(move(e4));
	

	auto z = (unique_ptr<Bace>)new boss(0.0f, 0.0f, 80);
	bace.push_back(move(z));*/

	//メインループ
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//画面クリア

		//第一ウェーブ
		if (spawn_time == 10)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 1, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));
		}

		//第二ウェーブ
		if (spawn_time == 500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 3, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 600)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 5, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 6, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 700)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 7, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 8, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}

		//第三ウェーブ
		if (spawn_time == 1500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 9, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 10, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 1800)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f, 11, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(450.0f, 5.0f, 12, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));

			auto e3 = (unique_ptr<Bace>)new Enemy(800.0f, 5.0f, 13, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e3));
		}

		//第四ウェーブ
		if (spawn_time == 2300)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 14, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2400)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 15, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 16, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2600)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 17, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

		}
		if (spawn_time == 2700)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 18, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}

		//第五ウェーブ
		if (spawn_time == 3200)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 3300)
		{
			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 3400)
		{
			auto e3 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e3));
		}
		if (spawn_time == 3500)
		{
			auto e4 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e4));
		}
		if (spawn_time == 3600)
		{
			auto e5 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e5));
		}

		//第六ウェーブ
		if (spawn_time == 4300)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f, 1, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));

			auto e3 = (unique_ptr<Bace>)new Enemy(300.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e3));

			auto e4 = (unique_ptr<Bace>)new Enemy(400.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e4));

			auto e5 = (unique_ptr<Bace>)new Enemy(500.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e5));

			auto e6 = (unique_ptr<Bace>)new Enemy(600.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e6));

			auto e7 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e7));

			auto e8 = (unique_ptr<Bace>)new Enemy(800.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e8));

			auto e9 = (unique_ptr<Bace>)new Enemy(900.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e9));

			auto e10 = (unique_ptr<Bace>)new Enemy(0.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e10));

		}

		//ボス
		if (spawn_time == 5800)
		{
			auto z = (unique_ptr<Bace>)new boss(450.0f, 0.0f, 80);
			bace.push_back(move(z));
		}


		//リストのメソッドを実行
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(bace);//各オブジェクトの処理
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//各オブジェクトの処理
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if (((Enemy*)(*i).get())->ID == -999)
			{
				i = bace.erase(i);
				break;
			}
		}


		ScreenFlip();//画面更新
		//例外処理
		if ((ProcessMessage() == -1)) break;

		spawn_time++;
	}
	return 0;

}
