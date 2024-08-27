#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "PLAYER.h"
#include "SCENE_TITLE.h"
#include "SCENE_PLAY.h"
#include "ENEMY.h"
#include "SCENE_RESULT.h"

SCENE_TITLE scti;
SCENE_PLAY scpl;
SCENE_RESULT scre;

float scene_swith_time = 0;  //enterを押してシーンが切り替わる時間
bool scene_swith_flag = false;  //シーン切り替えフラグ

enum {
	SCENE_ID_TITLE,  //タイトルシーン
	SCENE_ID_PLAY,  //プレイシーン
	SCENE_ID_RESULT  //リザルトシーン
};
int g_scene_id = SCENE_ID_TITLE;

//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){

	scti.graph();  //タイトル背景画像読み込み
	scti.sound_load();  //タイトル音読み込み

	PLAYER graph();  //プレイヤー　弾　画像読み込み

	playscene_init();  //SCENE_PLAY（プレイ画面　エネミー プレイヤー）の初期化
	scpl.sound_load();  //プレイ画面 音 読み込み
	scpl.graph();  //プレイ背景画面呼び出し

	scre.sound_load();  //リザルト画面　音　呼び出し
}

//------------------------------------------------------------------------------------------------------------
// タイトルシーン毎フレーム実行されます
void sceneTitle(float delta_time) {

	if (CheckSoundMem(scti.snd_bgm_hdl) == 0) {
		scti.sound_bgm_play();  //音　BGM再生
	}

	title_reset();  //タイトルに戻った時初期値に戻す（）

	scti.graph_draw();  //タイトル背景描画
	scti.string();  //タイトル文字
	scti.menu(delta_time);  //タイトルメニュー

	//enter押すと
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		scti.sound_se_play();  //音　SE再生
		scti.TITLE_MENU_FLASHINTIME = 0.25f;  //ゲームスタートボタン点滅速度UP
		scene_swith_flag = true;  //シーン切り替えフラグ
	}
	if (scene_swith_flag) {
		scene_swith_time += delta_time;
	}
	//1秒経過すると
	if (scene_swith_time >= 1.0) {
		g_scene_id = SCENE_ID_PLAY;  //シーンが切り替わる
		scene_swith_time = 0;
		scene_swith_flag = false;
		scti.TITLE_MENU_FLASHINTIME = 0.5f;  //ゲームスタートボタン点滅速度を元に戻す
		scti.sound_bgm_stop();  //BGMを止める
	}
 }

// プレイシーン毎フレーム実行されます
void scenePlay(float delta_time) {

	scpl.draw();  //プレイ画面背景

	if (CheckSoundMem(scpl.snd_bgm_hdl) == 0) {
		scpl.sound_bgm_play();  //BGM再生
	}

	Hitcheck_enemy_bullet();
	Hitcheck_enemy_player();
	Gane_play_main(delta_time);

	Gameover();
	if (gameover_flag == true) {

		g_scene_id = SCENE_ID_RESULT;
		scpl.sound_bgm_stop();
	}
}

void sceneResult(float delta_time) {

	if (CheckSoundMem(scre.snd_bgm_hdl) == 0) {
		scre.sound_bgm_play();  //リザルト画面　BGM　再生
	}

	scre.gameover_draw();
	scre.score_draw();
	scre.menu_draw(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		g_scene_id = SCENE_ID_TITLE;
		scre.sound_bgm_stop();
	}
}

//毎フレーム実行されます
void gameMain(float delta_time) {

	//sceneの切り替え
	switch (g_scene_id) {
	case SCENE_ID_TITLE:
		sceneTitle(delta_time);
		break;
	case SCENE_ID_PLAY:
		scenePlay(delta_time);
		break;
	case SCENE_ID_RESULT:
		sceneResult(delta_time);
		break;
	}
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}