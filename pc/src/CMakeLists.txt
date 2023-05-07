cmake_minimum_required(VERSION 3.2)
project(main)

set(SOURCE_FILES

mocp/audio.h
mocp/audio.c
mocp/audio_conversion.h
mocp/audio_conversion.c
mocp/alsa.h
mocp/alsa.c
mocp/common.c
mocp/common.h
mocp/decoder.h
mocp/decoder.c
mocp/equalizer.h
mocp/equalizer.c
mocp/fifo_buf.h
mocp/fifo_buf.c
mocp/files.h
mocp/files.c
mocp/playlist.h
mocp/playlist.c
mocp/player.h
mocp/player.c
mocp/log.h
mocp/log.c
mocp/lists.h
mocp/lists.c
mocp/md5.h
mocp/md5.c
mocp/out_buf.h
mocp/out_buf.c
mocp/io.h
mocp/io.c
mocp/null_out.h
mocp/null_out.c
mocp/options.h
mocp/options.c
mocp/playlist_file.h
mocp/playlist_file.c
mocp/protocol.h
mocp/protocol.c
mocp/rbtree.h
mocp/rbtree.c
mocp/server.h
mocp/server.c
mocp/softmixer.h
mocp/softmixer.c
mocp/tags_cache.h
mocp/tags_cache.c
mocp/utf8.h
mocp/utf8.c

main.c)

#creating shares lib
ADD_LIBRARY(ffmpeg SHARED mocp/decoder_plugins/ffmpeg/ffmpeg.c)
target_include_directories(ffmpeg PRIVATE  mocp )
set_target_properties(ffmpeg PROPERTIES  LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../plugins)
CREATE_LIBTOOL_FILE(ffmpeg ${PROJECT_SOURCE_DIR}/../plugins)
target_link_libraries(ffmpeg PRIVATE asound avformat m ltdl avcodec avutil)
file(COPY ${PROJECT_SOURCE_DIR}/../build/src/libffmpeg.la DESTINATION ${PROJECT_SOURCE_DIR}/../plugins)


add_executable(mp3player ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../out)

SET (CMAKE_C_FLAGS "-g -Wall -Wpedantic")
target_include_directories(mp3player PRIVATE player mocp )
target_link_libraries(mp3player PRIVATE asound avformat m ltdl avcodec avutil)
target_compile_definitions(mp3player PUBLIC -DPLUGIN_DIR="${PROJECT_SOURCE_DIR}/../plugins" -DHAVE_ALSA)


message("${EXECUTABLE_OUTPUT_PATH}")
get_target_property(compile_defs mp3player COMPILE_DEFINITIONS)
message("${compile_defs}" )

