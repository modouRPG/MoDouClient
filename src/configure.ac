#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([modouclient], [1.0], [xudongsecret@qq.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([helloworld.hpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PATH_PROG(SDL_CONFIG, sdl-config)
if test -n "$SDL_CONFIG"; then
    LIBS="$LIBS `$SDL_CONFIG --libs`"
    CPPFLAGS="$CPPFLAGS `$SDL_CONFIG --cflags`"
fi
# Checks for libraries.
AC_CHECK_LIB([SDL], [SDL_Init])
AC_CHECK_LIB([SDL_image], [IMG_LoadPNG_RW])
AC_CHECK_LIB([SDL_ttf], [TTF_Quit])
AC_CHECK_LIB([guichan], [main])
AC_CHECK_LIB([guichan_sdl], [main])
AC_CHECK_LIB([tmxparser], [main])
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([SDL.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_OUTPUT([Makefile])
