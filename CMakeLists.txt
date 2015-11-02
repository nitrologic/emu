cmake_minimum_required(VERSION 2.8.9)

project(devmame)

add_definitions( -DGLEW_STATIC )
add_definitions( -DNO_PLATFORM )
add_definitions( -DZLIB_CONST )
add_definitions( -DZ_SOLO )
add_definitions( -DFT2_BUILD_LIBRARY  )
# add_definitions( -DPNG_EXPORT )

add_definitions( -DHAS_Y8950)
add_definitions( -DHAS_Y8312)	

add_definitions( -DHAS_YM3526)
add_definitions( -DHAS_YM3812)
add_definitions( -DHAS_YM2610)
add_definitions( -DHAS_YM2612)

add_definitions( -DHAS_YM2203)
add_definitions( -DHAS_YM2608)
add_definitions( -DHAS_YM2610B)
add_definitions( -DHAS_YM3438) 


IF(MAC)
   add_definitions( -DTARGET_OS_MAC )
   add_definitions( -DCMAKE_OSX_DEPLOYMENT_TARGET=10.5 )
   INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
#   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")
   SET(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL -framework Carbon -framework ForceFeedback -framework Cocoa -framework IOKit -framework CoreMIDI -framework CoreAudio -framework AudioUnit -framework AudioToolbox -framework CoreGraphics -framework QuartzCore")
   add_definitions( -D__APPLE__ )
   add_definitions( -DGLEW_NO_GLU)

   add_definitions( -DLSB_FIRST)
   add_definitions( -DPTR64)	 
	#	SET(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
ENDIF (MAC)

if(WIN32)
   SET(MSVC_RUNTIME "static")
   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MTd /fp:fast")
#   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")   
   add_definitions( -D_WIN32_WINNT=0x0501 )
   add_definitions( -DWIN32 )
   add_definitions( -DPA_USE_DS )
#   add_definitions( -D_UNICODE )
   add_definitions( -DLSB_FIRST)
endif(WIN32)

IF(PI)
   SET(CMAKE_SYSTEM_NAME Linux)
   SET(CMAKE_SYSTEM_VERSION 1)
   SET(CMAKE_C_COMPILER gcc-4.9)
   SET(CMAKE_CXX_COMPILER g++-4.9)
   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")   
   add_definitions( -D__PI__)
ENDIF(PI)


INCLUDE_DIRECTORIES( 
  platform
  mame/src/emu
  mame/src/emu/layout
  mame/src/osd
  mame/src/osd/windows
  mame/src/osd/osdmini
	mame/src/lib/util
	mame/src/lib/zlib
	mame/src/lib/expat
  mame/src/mame/includes
  mame/src/mame
  include
)

SET(mame_platform
  platform/build.c
  platform/renderfont.c
  platform/renderlayer.c
)

FILE(GLOB mame_src 
  mame/src/emu/*.c
  mame/src/emu/cpu/*.c
  mame/src/emu/machine/*.c
  mame/src/emu/debug/*.c
  mame/src/emu/sound/*.c
  mame/src/emu/drivers/*.c
  mame/src/lib/util/*.c
#  mame/src/tools/*.c
)

SET(mame_sega
	mame/src/emu/cpu/z80/z80.c
	mame/src/emu/cpu/z80/z80dasm.c
	mame/src/emu/cpu/z80/z80daisy.c
	mame/src/emu/cpu/m68000/m68kcpu.c
	mame/src/emu/cpu/m68000/m68kdasm.c
#  mame/src/mame/video/genesis.c
#  mame/src/mame/drivers/megadriv.c
)

SET(mame_williams
  mame/src/mame/video/williams.c
  mame/src/mame/audio/williams.c
  mame/src/mame/defendermachine.c
	mame/src/mame/machine/williams.c
  mame/src/mame/machine/pckeybrd.c
  mame/src/mame/machine/ticket.c
	mame/src/mame/drivers/williams.c
  mame/src/emu/audio/generic.c	
  mame/src/emu/cpu/i386/i386dasm.c
	mame/src/emu/cpu/mcs48/mcs48dsm.c
	mame/src/emu/cpu/mcs48/mcs48.c
	mame/src/emu/cpu/m6502/6502dasm.c
	mame/src/emu/cpu/m6502/m6502.c
	mame/src/emu/cpu/m6800/6800dasm.c
	mame/src/emu/cpu/m6800/m6800.c
	mame/src/emu/cpu/m6805/6805dasm.c
	mame/src/emu/cpu/m6805/m6805.c
	mame/src/emu/cpu/m6809/6809dasm.c
	mame/src/emu/cpu/m6809/m6809.c
	mame/src/emu/cpu/h6280/6280dasm.c
	mame/src/emu/cpu/h6280/h6280.c
  mame/src/emu/sound/discrete.c
  mame/src/emu/video/generic.c
  mame/src/emu/video/rgbutil.c
  mame/src/emu/video/resnet.c
  mame/src/emu/video/vector.c
  mame/src/lib/expat/xmltok.c
  mame/src/lib/expat/xmlparse.c
  mame/src/lib/expat/xmlrole.c
	mame/src/lib/zlib/compress.c
	mame/src/lib/zlib/deflate.c
	mame/src/lib/zlib/inflate.c
	mame/src/lib/zlib/inffast.c
	mame/src/lib/zlib/inftrees.c
	mame/src/lib/zlib/zutil.c
	mame/src/lib/zlib/trees.c
	mame/src/lib/zlib/adler32.c
	mame/src/lib/zlib/crc32.c
)

FILE(GLOB mame_osd_windows
  mame/src/osd/windows/*.c
)

SET(mame_osd_nitro
  mame/src/osd/nitro/nitrostub.cpp
  mame/src/osd/nitro/nitrodir.c
  mame/src/osd/nitro/nitrofile.c
  mame/src/osd/nitro/nitromain.c
  mame/src/osd/nitro/nitromisc.c
  mame/src/osd/nitro/nitrosync.c
  mame/src/osd/nitro/nitrotime.c
  mame/src/osd/nitro/nitrowork.c
#  mame/src/osd/nitro/nitrowindow.c
  mame/src/osd/nitro/nitrovideo.c
  mame/src/osd/nitro/nitroaudio.c
  mame/src/osd/nitro/nitroinput.c
  mame/src/osd/nitro/nitrooutput.c
)

SET(mame_osd_mini
  mame/src/osd/osdmini/minidir.c
  mame/src/osd/osdmini/minifile.c
  mame/src/osd/osdmini/minimain.c
  mame/src/osd/osdmini/minimisc.c
  mame/src/osd/osdmini/minisync.c
  mame/src/osd/osdmini/minitime.c
  mame/src/osd/osdmini/miniwork.c
)

FILE(GLOB mame_h 
  mame/src/emu/*.h
)

SET(testmame_src
  test/testmame.cpp
)


IF(MAC)

ADD_EXECUTABLE(testmame
${mame_src}
${mame_williams}
${mame_osd_nitro}
${mame_h}
${mame_platform}
${testmame_src}
)

ENDIF(MAC)

IF(WIN32)

ADD_EXECUTABLE(testmame
${mame_src}
${mame_sega}
${mame_williams}
${mame_osd_windows}
${mame_h}
${mame_platform}
${testmame_src}
)

# ${mame_osd_nitro}

target_link_libraries(testmame winmm dxguid dinput8 dsound comctl32 shlwapi)

ADD_EXECUTABLE(file2str
  mame/src/build/file2str.c
)

ENDIF(WIN32)

IF(PI)

ADD_EXECUTABLE(testmame
${mame_src}
${mame_src2}
${mame_osd_mini}
${mame_h}
${mame_platform}
${testmame_src}
)

target_link_libraries(testmame winmm dxguid dinput8 dsound comctl32 shlwapi)

ENDIF(PI)
