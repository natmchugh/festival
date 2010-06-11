/bin/bash /home/nat/festival_php/libtool --mode=compile g++  -I. -I/home/nat/festival_php -DPHP_ATOM_INC -I/home/nat/festival_php/include -I/home/nat/festival_php/main -I/home/nat/festival_php -I/usr/include/php5 -I/usr/include/php5/main -I/usr/include/php5/TSRM -I/usr/include/php5/Zend -I/usr/include/php5/ext -I/usr/include/php5/ext/date/lib -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/include/festival -I/usr/lib/speech_tools/include  -DHAVE_CONFIG_H  -g -O2   -c /home/nat/festival_php/festival_php.cpp -o festival_php.lo 
libtool: compile:  g++ -I. -I/home/nat/festival_php -DPHP_ATOM_INC -I/home/nat/festival_php/include -I/home/nat/festival_php/main -I/home/nat/festival_php -I/usr/include/php5 -I/usr/include/php5/main -I/usr/include/php5/TSRM -I/usr/include/php5/Zend -I/usr/include/php5/ext -I/usr/include/php5/ext/date/lib -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/include/festival -I/usr/lib/speech_tools/include -DHAVE_CONFIG_H -g -O2 -c /home/nat/festival_php/festival_php.cpp  -fPIC -DPIC -o .libs/festival_php.o
/bin/bash /home/nat/festival_php/libtool --mode=link cc -DPHP_ATOM_INC -I/home/nat/festival_php/include -I/home/nat/festival_php/main -I/home/nat/festival_php -I/usr/include/php5 -I/usr/include/php5/main -I/usr/include/php5/TSRM -I/usr/include/php5/Zend -I/usr/include/php5/ext -I/usr/include/php5/ext/date/lib -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/include/festival -I/usr/lib/speech_tools/include  -DHAVE_CONFIG_H  -g -O2   -o festival_php.la -export-dynamic -avoid-version -prefer-pic -module -rpath /home/nat/festival_php/modules  festival_php.lo -lstdc++
libtool: link: cc -shared  .libs/festival_php.o   -lstdc++    -Wl,-soname -Wl,festival_php.so -o .libs/festival_php.so
libtool: link: ( cd ".libs" && rm -f "festival_php.la" && ln -s "../festival_php.la" "festival_php.la" )
/bin/bash /home/nat/festival_php/libtool --mode=install cp ./festival_php.la /home/nat/festival_php/modules
libtool: install: cp ./.libs/festival_php.so /home/nat/festival_php/modules/festival_php.so
libtool: install: cp ./.libs/festival_php.lai /home/nat/festival_php/modules/festival_php.la
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/sbin" ldconfig -n /home/nat/festival_php/modules
----------------------------------------------------------------------
Libraries have been installed in:
   /home/nat/festival_php/modules

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------

Build complete.
Don't forget to run 'make test'.

