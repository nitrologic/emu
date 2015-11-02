#include <rendlay.h>

#ifdef SIMONSUCKS

typedef void* layout_view;
typedef void* machine_config;
typedef void* layout_file;

extern void layout_view_recompute(layout_view *view, int layerconfig){
}


/* ----- layout file parsing ----- */
extern layout_file *layout_file_load(const machine_config *config, const char *dirname, const char *filename){
	return 0;
}

extern void layout_file_free(layout_file *file){
}

/***************************************************************************
    GLOBAL VARIABLES
***************************************************************************/

/* single screen layouts */
const char layout_horizont[1024];	/* horizontal 4:3 screens */
const char layout_vertical[1024];	/* vertical 4:3 screens */

#ifdef wtf

/* dual screen layouts */
extern const char layout_dualhsxs[];	/* dual 4:3 screens side-by-side */
extern const char layout_dualhovu[];	/* dual 4:3 screens above and below */
extern const char layout_dualhuov[];	/* dual 4:3 screens below and above */

/* triple screen layouts */
extern const char layout_triphsxs[];	/* triple 4:3 screens side-by-side */

/* generic color overlay layouts */
extern const char layout_ho20ffff[];	/* horizontal 4:3 with 20,FF,FF color overlay */
extern const char layout_ho2eff2e[];	/* horizontal 4:3 with 2E,FF,2E color overlay */
extern const char layout_ho4f893d[];	/* horizontal 4:3 with 4F,89,3D color overlay */
extern const char layout_ho88ffff[];	/* horizontal 4:3 with 88,FF,FF color overlay */
extern const char layout_hoa0a0ff[];	/* horizontal 4:3 with A0,A0,FF color overlay */
extern const char layout_hoffe457[];	/* horizontal 4:3 with FF,E4,57 color overlay */
extern const char layout_hoffff20[];	/* horizontal 4:3 with FF,FF,20 color overlay */
extern const char layout_voffff20[];	/* vertical 4:3 with FF,FF,20 color overlay */

#endif


#endif