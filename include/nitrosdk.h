#ifndef nitrosdk_h
#define nitrosdk_h

#ifdef _WIN32
#include <windows.h>
#define sym(name) GetProcAddress(0,(name))
#else
#include <dlfcn.h>
#define sym(name) dlsym(RTLD_DEFAULT,name);
#endif

#endif
