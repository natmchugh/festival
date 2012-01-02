dnl
dnl $Id $
dnl 

PHP_ARG_ENABLE(festival,
[whether to enable the "festival" extension],
[  --enable-festival[=DIR]       Enable "festival" support])

PHP_ARG_WITH(speech-tools-dir,  for festival,
[  --with-speech-tools-dir[=DIR]   Set the path to Edinburgh Speech tools install prefix.], yes)

if test "$PHP_FESTIVAL" != "no"; then
	AC_MSG_CHECKING([for festival headers])
	for i in /usr /usr/lib $PHP_FESTIVAL; do 
		AC_MSG_CHECKING([looking in $i])
dnl hmmm sometimes its /include/festival sometimes it /include
		if test -r $i/include/festival/festival.h; then
			FESTIVAL_DIR=$i
			FESTIVAL_INC_DIR=$FESTIVAL_DIR/include/festival
			AC_MSG_RESULT(found festival.h in $i)
		elif test -r $i/include/festival.h; then
			FESTIVAL_DIR=$i
			FESTIVAL_INC_DIR=$FESTIVAL_DIR/include
			AC_MSG_RESULT(found festival.h in $i)
		fi
	done
fi
if test "$PHP_SPEECH_TOOLS_DIR" != "no" && test "$PHP_SPEECH_TOOLS_DIR" != "yes"; then
	if test -r $PHP_SPEECH_TOOLS_DIR/include/EST.h; then
		EST_DIR=$PHP_SPEECH_TOOLS_DIR
	fi
else
	AC_MSG_CHECKING([for EST headers])
	for i in /usr /usr/lib /usr/lib/speech_tools ; do 
		if test -r $i/include/EST.h; then
			EST_DIR=$i
			AC_MSG_RESULT(found EST in $i)
		fi
	done
fi		

if test -z "$FESTIVAL_DIR"; then
	AC_MSG_ERROR(festival.h $FESTIVAL_DIR not found)
else
	PHP_ADD_INCLUDE($FESTIVAL_INC_DIR)
	PHP_ADD_LIBRARY_WITH_PATH(Festival, $FESTIVAL_DIR/lib, FESTIVAL_SHARED_LIBADD)
fi

if test -z "$EST_DIR"; then
	AC_MSG_ERROR(EST.h not found)
else
	PHP_ADD_INCLUDE($EST_DIR/include)
	PHP_ADD_LIBRARY_WITH_PATH(estbase, $EST_DIR/lib, FESTIVAL_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(estools, $EST_DIR/lib, FESTIVAL_SHARED_LIBADD)
	PHP_ADD_LIBRARY_WITH_PATH(eststring, $EST_DIR/lib, FESTIVAL_SHARED_LIBADD)
fi

 PHP_SUBST(FESTIVAL_SHARED_LIBADD)
 PHP_REQUIRE_CXX()
 PHP_ADD_LIBRARY(stdc++, "", FESTIVAL_SHARED_LIBADD) 
 PHP_NEW_EXTENSION(festival, festival_php.cpp, $ext_shared)