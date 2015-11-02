//============================================================
//
//  minidir.c - Minimal core directory access functions
//
//============================================================
//
//  Copyright Aaron Giles
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or
//  without modification, are permitted provided that the
//  following conditions are met:
//
//    * Redistributions of source code must retain the above
//      copyright notice, this list of conditions and the
//      following disclaimer.
//    * Redistributions in binary form must reproduce the
//      above copyright notice, this list of conditions and
//      the following disclaimer in the documentation and/or
//      other materials provided with the distribution.
//    * Neither the name 'MAME' nor the names of its
//      contributors may be used to endorse or promote
//      products derived from this software without specific
//      prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY AARON GILES ''AS IS'' AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
//  EVENT SHALL AARON GILES BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGE (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
//  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//============================================================


//#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "osdcore.h"

#define PATHSEPCH '/'
#define INVPATHSEPCH '\\'

static char *build_full_path(const char *path, const char *file)
{
	char *ret = (char *) osd_malloc_array(strlen(path)+strlen(file)+2);
	char *p = ret;

	strcpy(p, path);
	p += strlen(path);
	*p++ = PATHSEPCH;
	strcpy(p, file);
	return ret;
}

static osd_dir_entry_type get_attributes_enttype(int attributes, char *path)
{
	switch ( attributes )
	{
		case DT_DIR:
			return ENTTYPE_DIR;

		case DT_REG:
			return ENTTYPE_FILE;

		case DT_LNK:
		{
			struct stat s;

			if ( stat(path, &s) != 0 )
				return ENTTYPE_OTHER;
			else
				return S_ISDIR(s.st_mode) ? ENTTYPE_DIR : ENTTYPE_FILE;
		}

		default:
			return ENTTYPE_OTHER;
	}
}

// OSD directory interface

struct _osd_directory{
	DIR *dir; // dirent.h
	struct _osd_directory_entry ent;
};

//============================================================
//  osd_opendir
//============================================================

osd_directory *osd_opendir(const char *path)
{
	DIR *dir=opendir(path);
	osd_directory *osd_dir = (osd_directory *)malloc(sizeof(struct _osd_directory));
	osd_dir->dir=dir;
	return osd_dir;
}

//============================================================
//  osd_readdir
//============================================================

const osd_directory_entry *osd_readdir(osd_directory *dir)
{
	osd_directory_entry *entry=&dir->ent;
	entry->name="";
	entry->name=ENTTYPE_NONE;
	entry->size=0;
	return entry;
}
/*
ENTTYPE_NONE,
ENTTYPE_FILE,
ENTTYPE_DIR,
ENTTYPE_OTHER
*/


//============================================================
//  osd_closedir
//============================================================

void osd_closedir(osd_directory *dir)
{
	closedir(dir->dir);
}


//============================================================
//  osd_is_absolute_path
//============================================================

int osd_is_absolute_path(const char *path)
{
	return path[0]=='/';
}



#ifdef SHITE



#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif

#ifdef _XOPEN_SOURCE
#undef _XOPEN_SOURCE
#endif

#define _XOPEN_SOURCE 500

#ifndef __USE_BSD
#define __USE_BSD   // to get DT_xxx on Linux
#endif

#undef _POSIX_C_SOURCE  // to get DT_xxx on OS X

//============================================================
//  osd_readdir
//============================================================

const osd_directory_entry *osd_readdir(osd_directory *dir)
{
	char *temp;
	
	
//	dir->data = sdl_readdir(dir->fd);

	if (dir->data == NULL)
		return NULL;

	dir->ent.name = dir->data->d_name;
	temp = build_full_path(dir->path, dir->data->d_name);

	dir->ent.type = get_attributes_enttype(dir->data->d_type, temp);

	dir->ent.size = osd_get_file_size(temp);
	osd_free(temp);
	return &dir->ent;
}


//============================================================
//  osd_closedir
//============================================================

void osd_closedir(osd_directory *dir)
{
	if (dir->fd != NULL)
		closedir(dir->fd);
	osd_free(dir->path);
	osd_free(dir);
}



#endif
