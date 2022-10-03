#ifndef LUABINS_LUAHEADERS_H_INCLUDED_
#define LUABINS_LUAHEADERS_H_INCLUDED_

#if defined (__cplusplus) && !defined (LUABINS_LUABUILTASCPP)
extern "C" {
#endif

#include <lua.h>
#include <lauxlib.h>

#if (LUA_VERSION_NUM == 502)

#undef lua_equal
#define lua_equal(L,idx1,idx2)  lua_compare(L,(idx1),(idx2),LUA_OPEQ)

#undef lua_getfenv
#define lua_getfenv	lua_getuservalue
#undef lua_setfenv
#define lua_setfenv	lua_setuservalue

#undef lua_objlen
#define lua_objlen	lua_rawlen

#undef luaL_register
#define luaL_register(L,n,f) \
	{ if ((n) == NULL) luaL_setfuncs(L,f,0); else luaL_newlib(L,f); }

#endif

#if defined (__cplusplus) && !defined (LUABINS_LUABUILTASCPP)
}
#endif

#endif /* LUABINS_LUAHEADERS_H_INCLUDED_ */
