#include "osdcore.h"

struct _osd_directory{
	int dirHandle;
	struct _osd_directory_entry ent;
};

#include <nitro.h>

/*
ENTTYPE_NONE,
ENTTYPE_FILE,
ENTTYPE_DIR,
ENTTYPE_OTHER
*/

osd_directory *osd_opendir(const char *path){
	int h = nitroOpenDir(path);
	osd_directory *osd_dir = (osd_directory *)malloc(sizeof(struct _osd_directory));
	osd_dir->dirHandle=h;
	return osd_dir;
}

const osd_directory_entry *osd_readdir(osd_directory *dir){
	osd_directory_entry *entry=&dir->ent;
	const char *name = nitroDirEntry(dir->dirHandle);
	int type = nitroDirEntryType(dir->dirHandle);
	entry->name=name;
	entry->type=type;
	entry->size=0;
	return entry;
}

void osd_closedir(osd_directory *dir){
	nitroDirClose(dir->dirHandle);
}

int osd_is_absolute_path(const char *path){
	return path[0]=='/';
}
