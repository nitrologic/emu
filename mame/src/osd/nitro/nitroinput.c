#include "nitroinput.h"

#define MAX_KEYS 512

typedef struct _keyboard_state keyboard_state;
struct _keyboard_state{
	UINT8 state[MAX_KEYS];
	INT8 oldkey[MAX_KEYS];
	INT8 currkey[MAX_KEYS];
};

static INT32 keyboard_get_state(void *device_internal, void *item_internal){
	UINT8 *keystate = (UINT8 *)item_internal;
	return *keystate;
}

static input_device *keyboard_device;

UINT8 KBState[KEY_TOTAL];

//static INT32 keyboard_get_state(void *device_internal, void *item_internal);


static input_device *keyboard_device;

void nitroinput_init(running_machine *machine){

	// initialize the input system by adding devices
	// let's pretend like we have a keyboard device
	keyboard_device = input_device_add(machine, DEVICE_CLASS_KEYBOARD, "Keyboard", NULL);
	if (keyboard_device == NULL)
		fatalerror("Error creating keyboard device");


//	IPT_UI_SOFT_RESET
	// our faux keyboard only has a couple of keys (corresponding to the
	// common defaults)
	input_device_item_add(keyboard_device, "Esc", &KBState[KEY_ESCAPE], ITEM_ID_ESC, keyboard_get_state);
	input_device_item_add(keyboard_device, "P1", &KBState[KEY_P1_START], ITEM_ID_1, keyboard_get_state);
	input_device_item_add(keyboard_device, "B1", &KBState[KEY_BUTTON_1], ITEM_ID_LCONTROL, keyboard_get_state);
	input_device_item_add(keyboard_device, "B2", &KBState[KEY_BUTTON_2], ITEM_ID_LALT, keyboard_get_state);
	input_device_item_add(keyboard_device, "B3", &KBState[KEY_BUTTON_3], ITEM_ID_SPACE, keyboard_get_state);
	input_device_item_add(keyboard_device, "JoyU", &KBState[KEY_JOYSTICK_U], ITEM_ID_UP, keyboard_get_state);
	input_device_item_add(keyboard_device, "JoyD", &KBState[KEY_JOYSTICK_D], ITEM_ID_DOWN, keyboard_get_state);
	input_device_item_add(keyboard_device, "JoyL", &KBState[KEY_JOYSTICK_L], ITEM_ID_LEFT, keyboard_get_state);
	input_device_item_add(keyboard_device, "JoyR", &KBState[KEY_JOYSTICK_R], ITEM_ID_RIGHT, keyboard_get_state);

	input_device_item_add(keyboard_device, "Reset", &KBState[KEY_RESET], ITEM_ID_F3, keyboard_get_state);
}

#ifdef _WIN32

#include <conio.h>

void nitroinput_update()
{
	static int prevkey;
	int key = _kbhit();

	if (key != prevkey){
		KBState[prevkey] = 0;
		printf("keyup %d\n", key);
	}

	switch (key){
	case 1:
		if (KBState[KEY_RESET] == 0){
			KBState[KEY_RESET] = 1;
			printf("keydown %d\n", key);
			prevkey = KEY_RESET;
		}
		break;

	}

}

#else

int count=0;

void nitroinput_update()
{
	count++;
	if (count==100){
		KBState[KEY_RESET] = 1;
	}
	if (count==120){
		KBState[KEY_RESET] = 0;
	}
	
	
}

#endif
