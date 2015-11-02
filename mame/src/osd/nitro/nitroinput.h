#ifndef __NITRO_INPUT__
#define __NITRO_INPUT__

#include "driver.h"

#ifdef __cplusplus
extern "C" {
#endif

enum{
	KEY_ESCAPE,
	KEY_P1_START,
	KEY_BUTTON_1,
	KEY_BUTTON_2,
	KEY_BUTTON_3,
	KEY_JOYSTICK_U,
	KEY_JOYSTICK_D,
	KEY_JOYSTICK_L,
	KEY_JOYSTICK_R,
	KEY_RESET,
	KEY_TOTAL
};

UINT8 KBState[KEY_TOTAL];

void nitroinput_init(running_machine *machine);
void nitroinput_update();

#ifdef __cplusplus
}
#endif

#endif
