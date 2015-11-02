#ifdef WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <nitro.h>

struct nitroFolder{
	HANDLE handle;
	WIN32_FIND_DATA raw;
};

int nitroOpenDir(const char *path){
	WIN32_FIND_DATA result;
	FindFirstFile(path, &result);
	return 0;
}

#else

#include <nitro.h>
#include <dirent.h>

struct nitroFolder{
	DIR *dir;
};

int nitroOpenDir(const char *path){
	DIR *dir=opendir(path);
	return 0;
}

#endif

const char *nitroDirEntry(int dirHandle){
	return 0;
}

int nitroDirEntryType(int dirHandle){
	return 0;
}

void nitroDirClose(int dirHandle){

}
