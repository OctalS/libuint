AC_INIT([libuint], [1.0])

cflags_default=" "

if test "$CFLAGS" ; then
	cflags_default=
fi

AC_PROG_CC
AC_CONFIG_HEADERS([include/libuint.h:include/libuint.h.in])

if test "$cflags_default" ; then
	CFLAGS=$cflags_default
fi

if test "$host_alias"; then
	AC_SUBST([AR], [$host_alias-ar])
else
	AC_SUBST([AR], [ar])
fi

AC_CHECK_SIZEOF([void *])
AC_OUTPUT([Makefile])
