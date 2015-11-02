#ifndef __NITRO_AUDIO__
#define __NITRO_AUDIO__

#include "driver.h"

#ifdef __cplusplus
extern "C" {
#endif

void nitroaudio_init(running_machine *machine);
void nitroaudio_write(INT16 *samples,int count);

#ifdef __cplusplus
}
#endif

#endif
