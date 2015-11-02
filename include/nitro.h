#ifndef NITRO_H
#define NITRO_H

#define NitroWindowBorderless

enum EventKey{
	KEY_ESCAPE=27
};

enum EventType{
	NONE,QUIT,TERMINATE,
	LOWMEMORY,
	SLEEPING,ASLEEP,WAKING,AWAKE,
	WINDOWEVENT,
	SYSTEMEVENT,
	KEYDOWN,KEYUP,TEXTEDITING,TEXTINPUT,
	MOUSEMOVE,MOUSEDOWN,MOUSEUP,MOUSEWHEEL,
	JOYAXIS,JOYBALL,JOYHAT,JOYDOWN,JOYUP,JOYADDED,JOYREMOVED,
	AXIS,BUTTONDOWN,BUTTONUP,
	CONTROLLERADDED,CONTROLLERREMOVED,CONTROLLERREMAPPED,
	TOUCHDOWN,TOUCHUP,TOUCHDRAG,
	DOLLARGESTURE,DOLLARRECORD,MULTIGESTURE,CLIPBOARDEVENT,DROPFILE,TARGETRESET,
};

enum WindowEventType{
	WINDOWNONE,
	WINDOWSHOW,
	WINDOWHIDE,
	WINDOWEXPOSE,
	WINDOWMOVE,
	WINDOWSIZE,
	WINDOWMIN,
	WINDOWMAX,
	WINDOWRESTORE,
	WINDOWENTER,
	WINDOWLEAVE,
	WINDOWFOCUS,
	WINDOWUNFOCUS,
	WINDOWCLOSE,	
};

enum LightType {
	POINTLIGHT=1,
	DIRECTIONALLIGHT=2
};

enum MidiEventTypes{
	NoteOn,
	Noteoff,
	Control,
	SysEx
};

extern const char *nitroSymbols[];

#ifdef _WIN32
#define N __declspec(dllexport) 
#else
#define N
#endif

#ifdef __cplusplus
extern "C"{
#endif

N int nitroVersion();
N void nitroLog(const char *utf8);
N void nitroDebug(const char *format,...);

N int nitroNoticeCount();
N const char *nitroNotice(int index);

N int nitroInit();
N void nitroUpdate();
N void nitroTerminate();

N double nitroTime();
N void nitroSleep(double delay);

N void nitroBeep(double volume,double rate,double duration);

N int nitroControllerCount();
N void nitroOpenController(int index);
N void nitroCloseController(int index);
N const char *nitroControllerName(int index);
N const char *nitroControllerSpec(int index);

N int nitroControllerButtons(int index);
N int nitroControllerAxis(int index,int *sixaxis);

N int nitroDisplayCount();
N void nitroDisplaySize(int display,int *widthheight);
N void nitroDisplayPosition(int display,int *xposypos);

N int nitroCreateWindow(int x,int y,int width,int height,int flags);
N int nitroWindowFullscreen(int id,int display);
N void nitroWindowState(int id,int *xywhf);
N void nitroWindowHandle(int id,struct SDL_Window **);
N int nitroWindowDraw(int id,int *commands,int count);
N void nitroWindowPresent(int id);
N void nitroWindowClose(int id);

N int nitroEvent();
N int nitroEventType();
N int nitroEventTime();
N int nitroWindowEventType();
N const char *nitroEventString();

N int nitroMouseWindow();
N int nitroMouseButton();
N int nitroMouseX();
N int nitroMouseY();
N int nitroMouseXSpeed();
N int nitroMouseYSpeed();

N int nitroKeyboardKey();
N int nitroKeyboardModifiers();

N int nitroMouseDown(int button);
N int nitroKeyDown(int keycode);
N int nitroJoyDown(int index,int button);

N int nitroInitGlew();

N int nitroCreateRenderer();
N int nitroCreateLight(int type);

N int nitroCreateSprite(int mat);

N int nitroCreateScene();
N void nitroSetParent(int id, int parent);
N void nitroSetColor(int id,int argb);
N void nitroSetPosition(int id,double x,double y,double z);
N void nitroRevolve(int id,double qx,double qy,double qz,double qw);

N int nitroCreateCamera();
N void nitroSetRange(int id,double near,double far);
N void nitroSetFOV(int id,double radians);

N int nitroCreateBox(double width,double height,double depth,int mat);
N void nitroRendererSetScene(int rendera,int scene);
N void nitroRendererSetCamera(int rendera,int camera);
N void nitroRendererSetViewport(int rendera,int x,int y,int w,int h);
N void nitroRendererRender(int rendera);

N int nitroCreateMesh(int mat);
N void nitroAddVertices(int mesh,int n,double *xyz,double *nxnynz,double *uv);
N void nitroAddPoint(int mesh,int v0);
N void nitroAddLine(int mesh,int v0,int v1);
N void nitroAddTriangle(int mesh,int v0,int v1,int v2);
N void nitroAddQuad(int mesh,int v0,int v1,int v2,int v3);
N void nitroUpdateMesh(int mesh);

N int nitroCreateModel();
N void nitroAddMesh(int model,int mesh);

N int nitroReadJPEGFile(const char *path);
N int nitroWriteJPEGFile(const char *path,int width,int height,int channels,int quality);

N int nitroReadPNGFile(const char *path);
N int nitroWritePNGFile(const char *path,int width,int height,int depth,int quality);

N void nitroImageClose(int imageHandle);
N int nitroImageWidth(int imageHandle);
N int nitroImageHeight(int imageHandle);
N int nitroImageChannels(int imageHandle);
N int nitroImageFlags(int imageHandle);
N int nitroImageType(int imageHandle);
N int nitroImageReadLine(int imageHandle,int *data32);
N int nitroImageWriteLine(int imageHandle,int *data32);

// sampler

N int nitroLoadWAV(const char *path);
N int nitroLoadOGG(const char *path);
N int nitroStreamSample(int hertz,int channels,int bit);

N int nitroSampleLength(int sampleHandle);
N int nitroSampleHertz(int sampleHandle);
N int nitroSampleChannels(int sampleHandle);
N int nitroSampleBits(int sampleHandle);
N int nitroSamplePlay(int sampleHandle,double volume,double rate,double duration);

N int nitroChannelWrite(int channelHandle,int *samples,int sampleCount);


// ttf

N int nitroLoadTTF(const char *path,int size,int *metrics8);
N int nitroGlyphMetrics(int fontHandle,int charcode,int *metrics6);
N int nitroGlyphPixels(int fontHandle,int span,int height,int *data32);

// materials

N int nitroCreateTexture(int width,int height,int flags,int *data32);

N int nitroCreateShader(const char *src);
N int nitroCreateMaterial(int shader);
N int nitroColorMaterial(const char *key,int argb,int materialHandle);
N int nitroTextureMaterial(const char *key,int textureHandle,int materialHandle);

N void nitroSwapInterval(int interval);

// database

N int nitroOpenDB(const char *path);
N const char *nitroDBExecute(int dbHandle, const char *query);
N void nitroDBClose(int dbHandle);

// midi

N int nitroMidiDeviceCount();
N int nitroOpenMidiDevice(int index);

N const char *nitroMidiDeviceName(int deviceHandle);
N int nitroMidiDeviceInputCount(int deviceHandle);
N int nitroMidiDeviceOutputCount(int deviceHandle);

N int nitroMidiOutOpen(int deviceHandle);
N int nitroMidiOutSend(int deviceHandle,int b0,int b1,int b2);
N void nitroMidiOutClose(int deviceHandle);

N int nitroMidiInOpen(int deviceHandle);
N int nitroMidiInPoll(int deviceHandle);
N void nitroMidiInClose(int deviceHandle);

N int nitroMidiEventData();
N int nitroMidiEventTimestamp();

// audio

N int nitroAudioDeviceCount();
N int nitroOpenAudioDevice(int index);

N const char *nitroAudioDeviceName(int deviceHandle);
N int nitroAudioDeviceInputCount(int deviceHandle);
N int nitroAudioDeviceOutputCount(int deviceHandle);

N int nitroAudioOutOpen(int deviceHandle);
N int nitroAudioOutSend(int deviceHandle,int b0,int b1,int b2);
N void nitroAudioOutClose(int deviceHandle);

N int nitroAudioInOpen(int deviceHandle);
N int nitroAudioInPoll(int deviceHandle);
N void nitroAudioInClose(int deviceHandle);

N int nitroAudioEventData();
N int nitroAudioEventTimestamp();

// sockets

N int nitroListen(int port);
N int nitroConnect(const char *host,int port);

N const char *nitroSocketRead(int socketHandle);
N int nitroSocketWrite(int socketHandle,const char *data,int count);
N void nitroSocketClose(int socketHandle);

// filesystem

N int nitroOpenDir(const char *path);
N const char *nitroDirEntry(int dirHandle);
N int nitroDirEntryType(int dirHandle);
N void nitroDirClose(int dirHandle);

#ifdef __cplusplus
};
#endif

#endif
