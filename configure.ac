#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([pg-password-generator], [1.0], [denis.medeiros@bbd.ca])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AC_PREFIX_DEFAULT([/usr/bin])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CPP
AC_PROG_CC

# Use the C language and compiler for the following checks
AC_LANG([C])

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lpq':
AC_CHECK_LIB([pq], [main])
PKG_CHECK_MODULES([LIBPQ], [libpq], [have_libpq=yes])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([postgresql/libpq-fe.h libpq-fe.h],
                 [libpq_fe_found=1; break;])

AS_IF([test "x$libpq_fe_found" != "x1"],
    [AC_MSG_ERROR([pkg-config unable to find "libpq-fe.h".])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT

