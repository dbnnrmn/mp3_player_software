#include "stdio.h"
#include "mocp/audio.h"
#include "mocp/decoder.h"
#include "mocp/options.h"

int a=6;

int main()
{

io_init();
options_init();
decoder_init(a);
audio_initialize();
audio_plist_add("/media/roman/SharedDisk/my/projects/mp3_player/software/pc/1.flac");
audio_play("");
while(1);
  printf("hello world");
  return 0;
}

