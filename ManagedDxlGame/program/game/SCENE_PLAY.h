#pragma once
#include "ENEMY.h"
#include "PLAYER.h"

const int ENEMY_MAX_NUM = 10;  //敵 1 出現数上限
const int ENEMY2_MAX_NUM = 10;  //敵 2 出現数上限
const int ENEMY3_MAX_NUM = 10;  //敵 3 出現数上限

//ゲームタイマー
extern float time_count;
extern int min;
extern int sec;

//かぼちゃ
extern int enemy_num;  //敵 1 出現数
extern int enemy_spown_count;  //敵 1 出現カウント
extern int enemy_count;  //敵 1 出現間隔

//ほね
extern int enemy2_num;  //敵 2 出現数
extern int enemy2_spown_count;  //敵 2 出現カウント
extern int enemy2_count;  //敵 2 出現間隔

//おばけ
extern int enemy3_num;  //敵 3 出現数
extern int enemy3_spown_count;  //敵 3 出現カウント
extern int enemy3_count;  //敵 3 出現間隔

extern bool gameover_flag;  //ゲームオーバーフラグ

extern int score;  //スコア

class SCENE_PLAY {
public:
	int g_gpc_play_back; //プレイ画面背景
	int snd_bgm_hdl;  //音　BGM

	void graph();
	void draw();

	void sound_load();  //音　読み込み
	void sound_bgm_play();  //BGM再生
	void sound_bgm_stop();  //BGM停止
};

void playscene_init();
void title_reset();

void Hitcheck_enemy_bullet();
void Hitcheck_enemy_player();

void Gane_play_main(float delta_taime);  ////敵キャラ、プレイヤー、弾 生成・表示・移動
void Gameover();