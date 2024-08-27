#pragma once

const float SHOT_SPEED = 8;

//弾の変数
struct BULLET {

	bool flag = false;
	float x = 0;
	float y = 0;
	int gh;
	int width, height = 36;
	int shot_sound = 0;
};

class PLAYER {
public:

	int life_stock = 5;
	bool life = true;  //生きてるかどうか

	int bullet_count;  // 弾の発射間隔

	int player_hit_sound = 0;

	BULLET bullet_z[20];
	BULLET bullet_x[20];
	BULLET bullet_c[20];

	int gpc_hdl = 0;
	int width = 32;	 // 幅
	int height = 32;  // 高さ
	tnl::Vector3 pos = { 645, 685, 0 };	 //プレイヤー座標

	void init();  //変数の初期化
	void graph();	//プレイヤー　弾　画像読み込み
	void move();	//プレイヤーを動かす関数
	void draw();	//プレイヤーを表示する関数

	void hit_precess();  //敵に当たった時の動作
	void lifeflag();  //プレイヤーが死んだかどうか

	void shot_z();  //弾_z
	void shot_x();  //弾_x
	void shot_c();  //弾_c
};