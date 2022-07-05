#include "iostream"

extern "C"
{
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

using namespace std;

int add_from_lua(lua_State*, int, int);
int product_from_lua(lua_State*, int, int);

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "lua/product.lua");
    luaL_dofile(L, "lua/sum.lua");
    int sum = add_from_lua(L, 10, 3);
    cout << "The Sum of 10 and 3 from Lua is " << sum << endl;
    int prod = product_from_lua(L, 12, 13);
    cout << "The Product of 12 and 13 from Lua is " << prod << endl;
    lua_close(L);
    return 0;
}

int product_from_lua(lua_State* L, int a, int b)
{
    lua_getglobal(L, "luaprod");
    lua_pushnumber(L, a);
    lua_pushnumber(L, b);
    lua_call(L, 2, 1);
    return (int)lua_tointeger(L, -1);
}

int add_from_lua(lua_State* L, int a, int b)
{
    lua_getglobal(L, "luadd");
    lua_pushnumber(L, a);
    lua_pushnumber(L, b);
    lua_call(L, 2, 1);
    return (int)lua_tointeger(L, -1);
}
