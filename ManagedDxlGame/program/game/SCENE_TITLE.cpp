#include "../dxlib_ext/dxlib_ext.h"
#include "SCENE_TITLE.h"

void SCENE_TITLE::graph() {
	g_gpc_title = LoadGraph("graphics/pipo-battlebg001a.jpg");
}

void SCENE_TITLE::graph_draw() {
	DrawRotaGraph(g_gpc_title_pos.x, g_gpc_title_pos.y, 1.2, 0, g_gpc_title, true);
}

void SCENE_TITLE::string() {
	SetFontSize(100);
	DrawStringEx(TITLE_LOGO_POS.x, TITLE_LOGO_POS.y, -1, TITLE_LOGO_STR.c_str());
}

void SCENE_TITLE::menu(float delta_time) {
	// ì_ñ≈èàóù
	g_title_menu_flashing_time_cont += delta_time;

	if (g_title_menu_flashing_time_cont > TITLE_MENU_FLASHINTIME) {
		g_is_title_menu_on_draw = !g_is_title_menu_on_draw;
		g_title_menu_flashing_time_cont = 0;
	}
	if (g_is_title_menu_on_draw) {
		SetFontSize(30);
		DrawStringEx(TITLE_MENU_POS.x, TITLE_MENU_POS.y, -1, TITLE_MENU_STR.c_str());
	}
}

void SCENE_TITLE::sound_load() {

	snd_bgm_hdl = LoadSoundMem("sound/title_bgm.mp3");
	snd_se_hdl = LoadSoundMem("sound/title_se.mp3");
}

void SCENE_TITLE::sound_bgm_play() {

	ChangeVolumeSoundMem(80, snd_bgm_hdl);
	PlaySoundMem(snd_bgm_hdl, DX_PLAYTYPE_LOOP, true);  //BGMÉãÅ[Évçƒê∂
}
void SCENE_TITLE::sound_se_play() {

	ChangeVolumeSoundMem(80, snd_se_hdl);
	PlaySoundMem(snd_se_hdl, DX_PLAYTYPE_BACK);
}
void SCENE_TITLE::sound_bgm_stop() {

	StopSoundMem(snd_bgm_hdl);
}