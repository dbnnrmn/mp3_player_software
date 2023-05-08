#include "stdio.h"
#include "mocp/audio.h"
#include "mocp/decoder.h"
#include "mocp/options.h"
#include "lvgl/lvgl.h"
#include "lv_conf.h"
#include <SDL2/SDL.h>
#include "sdl/sdl.h"

#define HOR_RES 320
#define VER_RES 320

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[240 * 320 / 10];
static lv_disp_drv_t disp_drv;  




int a=6;

int main()
{



  lv_init();
  
sdl_init();





    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf1_1[HOR_RES * 100];
   // lv_disp_draw_buf_init(&draw_buf, buf1_1, NULL, HOR_RES * VER_RES);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &draw_buf;
   // disp_drv.flush_cb = dummy_flush_cb;
    disp_drv.hor_res = HOR_RES;
    disp_drv.ver_res = VER_RES;
    lv_disp_drv_register(&disp_drv);
    
  // lv_port_disp_init(640, 480);



io_init();
options_init();
decoder_init(a);
audio_initialize();
audio_plist_add("/media/roman/SharedDisk/my/projects/mp3_player/software/pc/1.mp3");
audio_play("");
while(1);
  printf("hello world");
  return 0;
}

