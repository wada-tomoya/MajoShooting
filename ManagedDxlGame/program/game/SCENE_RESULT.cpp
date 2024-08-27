#include "../dxlib_ext/dxlib_ext.h"
#include "SCENE_RESULT.h"
#include "SCENE_PLAY.h"

void SCENE_RESULT::gameover_draw() {

	SetFontSize(100);
	DrawStringEx(GameOver_Logo_pos.x, GameOver_Logo_pos.y, -1, GameOver_Logo_str.c_str());
}

void SCENE_RESULT::score_draw() {

	SetFontSize(50);
	DrawStringEx(Score_Logo_pos.x, Score_Logo_pos.y, -1, Score_Logo_str.c_str());
	SetFontSize(100);
	DrawStringEx(Score_pos.x, Score_pos.y, -1, "%d", score);
}

void SCENE_RESULT::menu_draw(float delta_time) {

	flashing_timecount += delta_time;

	if (flashing_timecount > Menu_Logo_flashintime) {
		Menu_Logo_flash_flag = !Menu_Logo_flash_flag;
		flashing_timecount = 0;
	}
	if (Menu_Logo_flash_flag) {
		SetFontSize(20);
		DrawStringEx(Menu_Logo_pos.x, Menu_Logo_pos.y, -1, Menu_Logo_str.c_str());
	}
}

void SCENE_RESULT::sound_load() {

	snd_bgm_hdl = LoadSoundMem("sound/result_bgm.mp3");
}
void SCENE_RESULT::sound_bgm_play() {
	
	ChangeVolumeSoundMem(80, snd_bgm_hdl);
	PlaySoundMem(snd_bgm_hdl, DX_PLAYTYPE_LOOP, true);
}
void SCENE_RESULT::sound_bgm_stop() {

	StopSoundMem(snd_bgm_hdl);
}