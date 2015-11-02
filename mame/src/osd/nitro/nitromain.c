#include "osdepend.h"
#include "render.h"
#include "clifront.h"
#include "mame.h"

#include "nitrovideo.h"
#include "nitroaudio.h"
#include "nitroinput.h"
#include "nitrooutput.h"

static render_target *our_target;

int main(int argc, char *argv[]){
	return cli_execute(argc, argv, NULL);
}

void osd_init(running_machine *machine){
	nitrovideo_init(machine);
	nitroaudio_init(machine);
	nitroinput_init(machine);
	nitrooutput_init(machine);	
// hook up the debugger log
//  add_logerror_callback(machine, output_oslog);
}

void osd_wait_for_debugger(const device_config *device, int firststop){
// we don't have a debugger, so we just return here
}

void osd_update(running_machine *machine, int skip_redraw){

	nitroinput_update();

	const render_primitive_list *primlist;
	int minwidth, minheight;

	// get the minimum width/height for the current layout
	render_target_get_minimum_size(our_target, &minwidth, &minheight);

	if(our_target){
	
	// make that the size of our target
		render_target_set_bounds(our_target, minwidth, minheight, 0);

	// get the list of primitives for the target at the current size
		primlist = render_target_get_primitives(our_target);

	// lock them, and then render them
		osd_lock_acquire(primlist->lock);
	// do the drawing here
		osd_lock_release(primlist->lock);
	}

	// after 5 seconds, exit
	if (attotime_compare(timer_get_time(machine), attotime_make(5, 0)) > 0)
		mame_schedule_exit(machine);
}

void osd_update_audio_stream(running_machine *machine, INT16 *buffer, int samples_this_frame)
{
	nitroaudio_write(buffer,samples_this_frame);
}


//============================================================
//  osd_set_mastervolume
//============================================================

void osd_set_mastervolume(int attenuation)
{
	// if we had actual sound output, we would adjust the global
	// volume in response to this function
}


//============================================================
//  osd_customize_input_type_list
//============================================================

void osd_customize_input_type_list(input_type_desc *typelist)
{
	// This function is called on startup, before reading the
	// configuration from disk. Scan the list, and change the
	// default control mappings you want. It is quite possible
	// you won't need to change a thing.
}


//============================================================
//  keyboard_get_state
//============================================================

static INT32 keyboard_get_state(void *device_internal, void *item_internal)
{
	// this function is called by the input system to get the current key
	// state; it is specified as a callback when adding items to input
	// devices
	UINT8 *keystate = (UINT8 *)item_internal;
	return *keystate;
}
