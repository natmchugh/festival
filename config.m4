dnl
dnl $Id $
dnl 

PHP_ARG_ENABLE(festival_php, whether to enable the festival extension,
[  --enable-festival_php       Enable festival support])

if test "$PHP_FESTIVAL" != "no"; then

PHP_SUBST(FESTIVAL_PHP_SHARED_LIBADD)
PHP_ADD_INCLUDE(/usr/include/festival)
PHP_ADD_INCLUDE(/usr/lib/speech_tools/include)
PHP_ADD_LIBRARY_WITH_PATH(Festival, /usr/lib, FESTIVAL_PHP_SHARED_LIBADD)
PHP_ADD_LIBRARY_WITH_PATH(eststring, /usr/lib, FESTIVAL_PHP_SHARED_LIBADD)
PHP_ADD_LIBRARY_WITH_PATH(estools, /usr/lib, FESTIVAL_PHP_SHARED_LIBADD)
PHP_ADD_LIBRARY_WITH_PATH(estbase, /usr/lib, FESTIVAL_PHP_SHARED_LIBADD)


 PHP_REQUIRE_CXX()
 PHP_ADD_LIBRARY(stdc++, "", FESTIVAL_PHP_SHARED_LIBADD) 
 PHP_NEW_EXTENSION(festival_php, festival_php.cpp, $ext_shared)
fi
