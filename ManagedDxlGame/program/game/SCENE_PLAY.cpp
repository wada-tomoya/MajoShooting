#include "../dxlib_ext/dxlib_ext.h"
#include "SCENE_PLAY.h"
#include "ENEMY.h"
#include "PLAYER.h"

PLAYER chpl;
ENEMY_1 chen1[ENEMY_MAX_NUM];
ENEMY_2 chen2[ENEMY2_MAX_NUM];
ENEMY_3 chen3[ENEMY3_MAX_NUM];

float time_count;
int min;
int sec;

//かぼちゃ
int enemy_num;  //敵 1 出現数
int enemy_spown_count;  //敵 1 出現カウント
int enemy_count;  //敵 1 出現間隔

//ほね
int enemy2_num;  //敵 2 出現数
int enemy2_spown_count;  //敵 2 出現カウント
int enemy2_count;  //敵 2 出現間隔

//おばけ
int enemy3_num;  //敵 3 出現数
int enemy3_spown_count;  //敵 3 出現カウント
int enemy3_count;  //敵 3 出現間隔

bool gameover_flag;  //ゲームオーバーフラグ

int score;  //スコア
//---------------------------------------------------------------------------------------------------------------------
//背景画像読み込み
void SCENE_PLAY::graph() {

	g_gpc_play_back = LoadGraph("graphics/unnamed.jpg");
}
//背景画像表示
void SCENE_PLAY::draw() {

	DrawRotaGraph(630, 350, 2, 0, g_gpc_play_back, false);
}
//プレイシーン　音　読み込み
void SCENE_PLAY::sound_load() {

	snd_bgm_hdl = LoadSoundMem("sound/play_bgm4.mp3");
}
//プレイシーン　BGM　再生
void SCENE_PLAY::sound_bgm_play() {

	ChangeVolumeSoundMem(50, snd_bgm_hdl);
	PlaySoundMem(snd_bgm_hdl, DX_PLAYTYPE_LOOP, true);
}
//プレイシーン　BGM　停止
void SCENE_PLAY::sound_bgm_stop() {

	StopSoundMem(snd_bgm_hdl);
}

//プレイヤー、弾変数初期化
void playscene_init() {

	//かぼちゃ
	enemy_num = 7;  //敵 1 出現数
	enemy_spown_count = 0;  //敵 1 出現カウント
	enemy_count = 120;  //敵 1 出現間隔

	//ほね
	enemy2_num = 7;  //敵 2 出現数
	enemy2_spown_count = 0;  //敵 2 出現カウント
	enemy2_count = 120;  //敵 2 出現間隔

	//おばけ
	enemy3_num = 7;  //敵 3 出現数
	enemy3_spown_count = 0;  //敵 3 出現カウント
	enemy3_count = 120;  //敵 3 出現間隔

	//ゲームタイマー
	time_count = 60 * 10;
	min = 0;
	sec = 0;

	//スコア
	score = 0;

	//ゲームオーバーフラグ
	gameover_flag = false;

	//プレイヤー変数初期化
	chpl.init();
	chpl.graph();

	//エネミー変数初期化
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].init1();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].init2();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen3[i].init3();
	}
	//エネミー　画像　音　読み込み
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].Graph();
		chen1[i].sound_load();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].Graph2();
		chen2[i].sound_load();
	}
	for (int i = 0; i < ENEMY3_MAX_NUM; ++i) {
		chen3[i].Graph3();
		chen3[i].sound_load();
	}
}

void title_reset() {

	//かぼちゃ
	enemy_num = 7;  //敵 1 出現数
	enemy_spown_count = 0;  //敵 1 出現カウント
	enemy_count = 120;  //敵 1 出現間隔

	//ほね
	enemy2_num = 7;  //敵 2 出現数
	enemy2_spown_count = 0;  //敵 2 出現カウント
	enemy2_count = 120;  //敵 2 出現間隔

	//おばけ
	enemy3_num = 7;  //敵 3 出現数
	enemy3_spown_count = 0;  //敵 3 出現カウント
	enemy3_count = 120;  //敵 3 出現間隔

	//ゲームタイマー
	time_count = 60 * 10;
	min = 0;
	sec = 0;

	//スコア
	score = 0;

	//ゲームオーバーフラグ
	gameover_flag = false;

	//プレイヤー変数初期化
	chpl.pos = { 645, 685, 0 };
	chpl.life_stock = 5;
	chpl.life = true;
	//弾変数初期化
	for (int i = 0; i < 20; ++i) {
		chpl.bullet_z[i].flag = false;
		chpl.bullet_x[i].flag = false;
		chpl.bullet_c[i].flag = false;
	}

	//エネミー変数初期化
	for (int i = 0; i < ENEMY_MAX_NUM; ++i) {
		chen1[i].init1();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen2[i].init2();
	}
	for (int i = 0; i < ENEMY2_MAX_NUM; ++i) {
		chen3[i].init3();
	}
}

void Gane_play_main(float delta_time) {

	//経過時間　表示
	time_count -= delta_time;
	min = (int)time_count / 60;
	sec = (int)time_count % 60;
	SetFontSize(70);
	DrawStringEx(50, 20, -1, "%d : %d", min, sec);

	//プレイヤー残機　表示
	DrawStringEx(1050, 500, -1, "%d", chpl.life_stock);

	//スコア表示
	SetFontSize(50);
	DrawStringEx(1000, 10, -1, "スコア");

	DrawStringEx(1000, 60, -1, "%d", score);

	//敵キャラ 1 生成　かぼちゃ
	enemy_spown_count++;
	for (int i = 0; i < enemy_num; ++i) {
		if (enemy_spown_count % enemy_count == 0) {
			if (chen1[i].flag == false) {
				chen1[i].flag = true;
				chen1[i].Enemy();

				break;
			}
		}
	}
	
	//敵キャラ 1 画像表示
	for (int i = 0; i < enemy_num; ++i) {
		if (chen1[i].flag) {
			chen1[i].Draw();
		}
	}
	//敵キャラ 1 移動
	for (int i = 0; i < enemy_num; ++i) {
		if (chen1[i].flag && chen1[i].aiko_flag == false) {
			chen1[i].Move();
		}
		if (chen1[i].flag && chen1[i].aiko_flag == true) {
			chen1[i].aiko_stop_time();
		}
	}

	//敵キャラ 2 生成　ほね
	enemy2_spown_count++;
	for (int i = 0; i < enemy2_num; ++i) {
		if (enemy2_spown_count % enemy2_count == 0 && enemy2_spown_count >= 0) {
			if (chen2[i].flag2 == false) {
				chen2[i].flag2 = true;
				chen2[i].Enemy2();
				break;
			}
		}
	}
	//敵キャラ 2 画像表示
	for (int i = 0; i < enemy2_num; ++i) {
		if (chen2[i].flag2) {
			chen2[i].Draw2();
		}
	}
	//敵キャラ 2 移動
	for (int i = 0; i < enemy2_num; ++i) {
		if (chen2[i].flag2 && chen2[i].aiko_flag == false) {
			chen2[i].Move2();
		}
		if (chen2[i].flag2 && chen2[i].aiko_flag == true) {
			chen2[i].aiko_stop_time();
		}
	}

	//敵キャラ 3 生成　おばけ
	enemy3_spown_count++;
	for (int i = 0; i < enemy3_num; ++i) {
		if (enemy3_spown_count % enemy3_count == 0 && enemy3_spown_count >= 0) {
			if (chen3[i].flag3 == false) {
				chen3[i].flag3 = true;
				chen3[i].Enemy3();
				break;
			}	
		}
	}
	//敵キャラ 3 画像表示
	for (int i = 0; i < enemy3_num; ++i) {
		if (chen3[i].flag3) {
			chen3[i].Draw3();
		}
	}
	//敵キャラ 3 移動
	for (int i = 0; i < enemy3_num; ++i) {
		if (chen3[i].flag3 && chen3[i].aiko_flag == false) {
			chen3[i].Move3();
		}
		if (chen3[i].flag3 && chen3[i].aiko_flag == true) {
			chen3[i].aiko_stop_time();
		}
	}

	//プレイヤー、弾
	chpl.shot_z();  //弾ｚの発射処理を実行
	chpl.shot_x();  //弾ｘの発射処理を実行
	chpl.shot_c();  //弾ｃの発射処理を実行
	chpl.move();  //プレイヤー移動
	chpl.draw();  //プレイヤー画像表示
}

//当たり判定　弾と敵
void Hitcheck_enemy_bullet() {

	//弾zとかぼちゃ
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_z[u].flag && chen1[i].flag) {

				chpl.bullet_z[u].flag = false;
				chen1[i].aiko_flag = true;
			}
		}
	}
	//弾xとかぼちゃ
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_x[u].flag && chen1[i].flag) {

				chpl.bullet_x[u].flag = false;
			}
		}
	}
	//弾cとかぼちゃ
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
				&& chpl.bullet_c[u].flag && chen1[i].flag) {

				chen1[i].flag = false;
				chpl.bullet_c[u].flag = false;
				chen1[i].sound_play(); 
				score += 10;
			}
		}
	}

	//弾zとほね
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_z[u].flag && chen2[i].flag2) {

				chen2[i].flag2 = false;
				chpl.bullet_z[u].flag = false;
				chen2[i].sound_play();
				score += 10;
			}
		}
	}
	//弾xとほね
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_x[u].flag && chen2[i].flag2) {
				
				chpl.bullet_x[u].flag = false;
				chen2[i].aiko_flag = true;
			}
		}
	}
	//弾cとほね
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
				&& chpl.bullet_c[u].flag && chen2[i].flag2) {
				
				chpl.bullet_c[u].flag = false;
			}
		}
	}

	//弾zとおばけ
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_z_pos = { chpl.bullet_z[u].x + 17, chpl.bullet_z[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_z_pos, chpl.bullet_x[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_z[u].flag && chen3[i].flag3) {
				
				chpl.bullet_z[u].flag = false;
			}
		}
	}
	//弾xとおばけ
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_x_pos = { chpl.bullet_x[u].x + 17, chpl.bullet_x[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_x_pos, chpl.bullet_x[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_x[u].flag && chen3[i].flag3) {

				chpl.bullet_x[u].flag = false;
				chen3[i].flag3 = false;
				chen3[i].sound_play();
				score += 10;
			}
		}
	}
	//弾cとおばけ
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos = { chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		for (int u = 0; u < 20; u++) {
			tnl::Vector3 bullet_c_pos = { chpl.bullet_c[u].x + 17, chpl.bullet_c[u].y, 0 };

			if (tnl::IsIntersectSphere(bullet_c_pos, chpl.bullet_c[u].width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
				&& chpl.bullet_c[u].flag && chen3[i].flag3) {
				
				chpl.bullet_c[u].flag = false;
				chen3[i].aiko_flag = true;
			}
		}
	}
}

//当たり判定 プレイヤーと敵
void Hitcheck_enemy_player() {
	//プレイヤーとかぼちゃ
	for (int i = 0; i < enemy_num; i++) {
		tnl::Vector3 enemy_kabocha_pos = { chen1[i].enemy_x, chen1[i].enemy_y, 0 };  //かぼちゃ座標
		
		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_kabocha_pos, chen1[i].enemy_w / 2)
			&& chpl.life && chen1[i].flag) {

			chen1[i].flag = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
	//プレイヤーとほね
	for (int i = 0; i < enemy2_num; i++) {
		tnl::Vector3 enemy_hone_pos = { chen2[i].enemy2_x, chen2[i].enemy2_y, 0 };

		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_hone_pos, chen2[i].enemy2_w / 2)
			&& chpl.life && chen2[i].flag2) {

			chen2[i].flag2 = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
	//プレイヤーとおばけ
	for (int i = 0; i < enemy3_num; i++) {
		tnl::Vector3 enemy_obake_pos{ chen3[i].enemy3_x, chen3[i].enemy3_y, 0 };

		if (tnl::IsIntersectSphere(chpl.pos, chpl.width / 2, enemy_obake_pos, chen3[i].enemy3_w / 2)
			&& chpl.life && chen3[i].flag3) {

			chen3[i].flag3 = false;
			ChangeVolumeSoundMem(100, chpl.player_hit_sound);
			PlaySoundMem(chpl.player_hit_sound, DX_PLAYTYPE_BACK);
			chpl.life_stock -= 1;
		}
	}
}

void Gameover() {

	chpl.lifeflag();
	if (time_count <= 0.0f || !chpl.life) {
		gameover_flag = true;
	}
}