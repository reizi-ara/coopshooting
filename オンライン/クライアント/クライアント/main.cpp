//マルチスレッドTCP通信　クライアント側
#pragma once
#include "main.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR IpCmdLine, _In_ int nShowCmd)
{
	//windowモードの切り替え
	ChangeWindowMode(TRUE);
	//windowサイズ
	SetGraphMode(WIDTH, HEIGHT, 32);
	//バックグラウンド処理の許可
	SetAlwaysRunFlag(TRUE);
	//多重起動の許可
	SetDoubleStartValidFlag(TRUE);
	//Dxライブラリの初期化
	if (DxLib_Init() == -1) return-1;//失敗したらプログラム終了

	//バックバッファを使う設定
	SetDrawScreen(DX_SCREEN_BACK);
	//windowの名前
	SetWindowText("クライアント");

	//画像の読み込み
	int img = LoadGraph("image\\sigure(64).jpg");

	//送受信のデータ処理用
	char StrBuf[256] = { "null" };//256バイトまで

	//全てのプレイヤーデータ
	SendData* Player_ALL = new SendData();

	//通信関係
	IPDATA IP;
	//通信用のハンドル
	int NetHandel;
	//ポート
	int Port = 26;
	//通信先のIPアドレスの設定
	IP = IP_set();

	//プレイヤーデータ作成
	//名前の入力
	char name[8] = "null";
	ClearDrawScreen();//画面のクリア
	DrawString(0, 0, "名前を入力　小文字8文字/全角４文字まで", GetColor(255, 255, 255));
	KeyInputString(0, 16, 8, name, FALSE);

	//初回送信データの作成
	Data* my_Data = new Data(0.0f, 0.0f, name);

	//初回接続処理
	NetHandel = ConnectNetWork(IP, Port);//入力したIPと設定したポートを使用

	//接続するまで待機
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//画面のクリア

		if (NetHandel != -1) {
			//接続完了
			//サーバーにデータを送信（名前だけ送信）
			NetWorkSend(NetHandel, &my_Data->name, sizeof(my_Data->name));
			//サーバーからの応答待機
			while (!ProcessMessage()) {
				//送受信データを調べる
				if (GetNetWorkDataLength(NetHandel) != 0)
					break;
			}

			//受信データを変換
			//受信データをメモリからStrBufにコピーして、SendDataに変換
			NetWorkRecv(NetHandel, StrBuf, sizeof(SendData));
			memcpy_s(Player_ALL, sizeof(SendData), StrBuf, sizeof(SendData));//変換

			DrawString(0, 16, "接続完了。何かキーを押してください。",GetColor(255, 255, 255));

			ScreenFlip();
			WaitKey();
			break;
		}
		else {
			//接続中
			DrawString(0, 0, "接続確立中・・・", GetColor(255, 255, 255));
		}

		ScreenFlip();
	}

	//メインループ(Escキーで終了)
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//画面クリア

		if (GetNetWorkDataLength(NetHandel) != 0)
		{
			//データを受信した場合
			NetWorkRecv(NetHandel, StrBuf, sizeof(SendData));
			//プレイヤー全体データの更新
			memcpy_s(Player_ALL, sizeof(SendData), StrBuf, sizeof(SendData));
		}
		else
		{
			//データを受信していない場合
			//移動処理
			Vec v{ 0.0f,0.0f };
			if (CheckHitKey(KEY_INPUT_UP))v.y = -4.0f;
			if (CheckHitKey(KEY_INPUT_DOWN))v.y = 4.0f;
			if (CheckHitKey(KEY_INPUT_LEFT))v.x = -4.0f;
			if (CheckHitKey(KEY_INPUT_RIGHT))v.x = 4.0f;

			//入力があった場合にデータを送信
			if (v.x != 0.0f || v.y != 0.0f)
			{
				//データ送信
				NetWorkSend(NetHandel, &v, sizeof(Vec));
			}
		}
		//描画
		//Player_Allを使って画面の更新
		for (int i = 0; i < MAX; i++) {
			if (Player_ALL->data[i].ID != -1) {
				//キャラ
				DrawGraph(Player_ALL->data[i].pos.x, Player_ALL->data[i].pos.y, img, TRUE);
				//名前
				DrawStringF(Player_ALL->data[i].pos.x, Player_ALL->data[i].pos.y, Player_ALL->data[i].name, GetColor(255, 255, 255));
			}
		}
		//DrawGraphF(0.0f, 0.0f, img, TRUE);

		ScreenFlip();//画面更新

		//例外処理発生でループを抜ける
		if (ProcessMessage() == -1)
			break;
	}

	WaitKey();//キー入力があるまで待機

	DxLib_End();//Dxライブラリの解放
	return 0;
}