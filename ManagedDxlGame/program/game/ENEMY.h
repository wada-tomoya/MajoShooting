#pragma once

class ENEMY_1 {  //かぼちゃ
public:

	float speed = 1;  //敵キャラ移動スピード

	float life = 1;
	
	bool flag = false;  //敵キャラ生成フラグ

	float enemy_x = 645;
	float enemy_y = -20;

	int enemy_w = 60;  //敵キャラ幅
	int enemy_h = 60;  //敵キャラ高さ 

	int ene_gpc_hdl;  //敵キャラ画像ハンドル

	bool aiko_flag = false;  //あいこの場合
	float stop_time = 0;

	int death_sound = 0;
	
	void aiko_stop_time();  //あいこで静止する関数
	void init1();  //変数初期化
	void Graph();  //画像読み込み
	void Draw();  //敵表示
	void Move();  //敵キャラ移動
	void Enemy();  //敵キャラ生成
	void sound_load();  //音　読み込み
	void sound_play();  //音　再生
};

class ENEMY_2 {  //ほね
public:

	float speed2 = 2;  //敵キャラ移動スピード

	float life2 = 1;

	bool flag2 = false;  //敵キャラ生成フラグ

	float enemy2_x = 645;
	float enemy2_y = -20;

	int enemy2_w = 60;  //敵キャラ幅
	int enemy2_h = 60;  //敵キャラ高さ 

	int ene_gpc_hdl2 = 0;  //敵キャラ画像ハンドル

	bool aiko_flag = false;  //あいこの場合
	float stop_time = 0;

	int death_sound = 0;

	void aiko_stop_time();  //あいこで静止する関数

	void init2();  //変数初期化
	void Graph2();  //画像読み込み
	void Draw2();  //敵表示
	void Move2();  //敵キャラ移動
	void Enemy2();  //敵キャラ生成
	void sound_load();  //音　読み込み
	void sound_play();  //音　再生
};

class ENEMY_3 {  //おばけ
public:

	float speed3 = 2;  //敵キャラ移動スピード

	float life3 = 1;

	bool flag3 = false;  //敵キャラ生成フラグ

	float enemy3_x = 645;
	float enemy3_y = -20;

	int enemy3_w = 60;  //敵キャラ幅
	int enemy3_h = 60;  //敵キャラ高さ 

	int ene_gpc_hdl3 = 0;  //敵キャラ画像ハンドル

	bool aiko_flag = false;  //あいこの場合
	float stop_time = 0;

	int death_sound = 0;

	void aiko_stop_time();  //あいこで静止する関数

	void init3();  //変数初期化
	void Graph3();  //画像読み込み
	void Draw3();  //敵表示
	void Move3();  //敵キャラ移動
	void Enemy3();  //敵キャラ生成
	void sound_load();  //音　読み込み
	void sound_play();  //音　再生
};