#include "nitroaudio.h"
#include "mame.h"
#include "nitro.h"

static void sound_exit(running_machine *machine)
{
	sound_private *global = machine->sound_data;

	/* close any open WAV file */
//	if (global->wavfile != NULL)wav_close(global->wavfile);
//	global->wavfile = NULL;

	/* reset variables */
//	global->totalsnd = 0;
}


void nitroaudio_init(running_machine *machine){	
/*
	// if no sound, don't create anything
	if (!options_get_bool(mame_options(), OPTION_SOUND))
		return;

	// ensure we get called on the way out
	add_exit_callback(machine, sound_exit);
*/
}


void nitroaudio_write(INT16 *samples,int count){
	nitroSound
}
