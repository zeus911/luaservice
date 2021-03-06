/*!
 * \file luaservice.h
 * \brief Public declarations.
 */
#ifndef LUASERVICE_H_
#define LUASERVICE_H_

// From LuaMain.c
/** An opaque pointer to a Lua state. */
typedef void *LUAHANDLE;
extern LUAHANDLE LuaWorkerLoad(LUAHANDLE h, const char *cmd);
extern LUAHANDLE LuaWorkerRun(LUAHANDLE h);
extern void LuaWorkerCleanup(LUAHANDLE h);
extern char *LuaResultString(LUAHANDLE h, int item);
extern int LuaResultInt(LUAHANDLE h, int item);
extern char *LuaResultFieldString(LUAHANDLE h, int item, const char *field);
extern int LuaResultFieldInt(LUAHANDLE h, int item, const char *field);
extern void LuaWorkerSetArgs(LUAHANDLE h, size_t argc, const char **argv);

// From LuaService.c
extern void SvcDebugTrace(LPCSTR fmt, DWORD Status);
extern void SvcDebugTraceStr(LPCSTR fmt, LPCSTR s);
extern int SvcDebugTraceLevel;
extern const char *ServiceName;
extern const char *ServiceDisplayName;
extern const char *ServiceScript;
extern const char *LuaPackagePath;
extern const char *LuaPackageCPath;
extern const char *LuaInitScript;
extern volatile int ServiceStopping;
extern const char **LuaServiceArgv;
extern size_t LuaServiceArgc;

// From SvcController.c
extern int SvcControlMain(int argc, char *argv[]);

#ifndef LUA_OK
#  define LUA_OK 0
#endif

#define LUA_INIT_VAR "LUA_INIT"

#if defined LUA_VERSION_MAJOR && defined LUA_VERSION_MINOR
#  define LUA_INITVARVERSION  LUA_INIT_VAR "_" LUA_VERSION_MAJOR "_" LUA_VERSION_MINOR
#else
#  define LUA_INITVARVERSION  LUA_INIT_VAR
#endif

#endif /*LUASERVICE_H_*/
