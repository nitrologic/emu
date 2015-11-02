#include "nitrovideo.h"
#include "render.h"

render_target *target;

void nitrovideo_init(running_machine *machine){
	target=render_target_alloc(machine,NULL,0);
	render_set_ui_target(target);
}
