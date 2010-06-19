/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Nathaniel McHugh nat@fishtrap.co.uk			  |
   +----------------------------------------------------------------------+
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
extern "C" {
#include "festival_php.h"
}

#include<festival.h>
using namespace std;


/* {{{ proto resource festival_say_text()
   Says the passed in text  */
PHP_FUNCTION(festival_say_text)
{
int heap_size=210000;
int load_init_files=1;
char * text = NULL;
int    text_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }

festival_initialize(load_init_files,heap_size);
festival_say_text(text);
RETURN_TRUE;
}
/* }}} */

/* {{{ proto resource festival_say_file()
   Says the passed in text  */
PHP_FUNCTION(festival_say_file)
{
int heap_size=210000;
int load_init_files=1;
char * filename = NULL;
int    filename_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }

festival_initialize(load_init_files,heap_size);
festival_say_file(filename);
festival_wait_for_spooler();
RETURN_TRUE;
}
/* }}} */

/* {{{ proto resource festival_say_file()
   Says the passed in text  */
PHP_FUNCTION(festival_text_to_wave)
{
int heap_size=210000;
int load_init_files=1;
char * text = NULL;
int    text_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }
EST_Wave wave;
festival_initialize(load_init_files,heap_size);
festival_text_to_wave(text,wave);
wave.save("wave.wav","riff");
RETURN_TRUE;
}
/* }}} */



ZEND_BEGIN_ARG_INFO_EX(festival_php_args, 0, 0, 0)
ZEND_END_ARG_INFO()

static function_entry festival_php_functions[] = {
	PHP_FE(festival_say_text, festival_php_args)
	PHP_FE(festival_say_file, festival_php_args)
        PHP_FE(festival_text_to_wave, festival_php_args)
	/* End of functions */
	{NULL, NULL, NULL}
};

PHP_MINFO_FUNCTION(festival_php)
{
	char version[256];
	php_info_print_table_start();
	php_info_print_table_header(2, "festival php support", "enabled");
	php_info_print_table_row(2, "version", FESTIVAL_PHP_VERSION);
	php_info_print_table_end();
}

zend_class_entry *php_festivalphp_fc_entry;
#define PHP_FESTIVAL_PHP_FC_NAME "Festival_FestivalClass"
static function_entry php_festivalphp_fc_functions [] = {
      {NULL, NULL, NULL}
};


PHP_MINIT_FUNCTION(festival_php)
{
      zend_class_entry ce;
      INIT_CLASS_ENTRY(ce, PHP_FESTIVAL_PHP_FC_NAME,
                       php_festivalphp_fc_functions);
      php_festivalphp_fc_entry =
            zend_register_internal_class(&ce TSRMLS_CC);
      return SUCCESS;
}



zend_module_entry festival_php_module_entry = {
	STANDARD_MODULE_HEADER,
	"festival_php",
	festival_php_functions,
        PHP_MINIT(festival_php), /* MINIT */
        NULL, /* MSHUTDOWN */
	NULL,	/* RINIT */
	NULL,   /* RSHUTDOWN */
	PHP_MINFO(festival_php),
	FESTIVAL_PHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_FESTIVAL_PHP
BEGIN_EXTERN_C()
ZEND_GET_MODULE(festival_php)
END_EXTERN_C()
#endif
/*
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * End:
 * vim600: fdm=marker
 * vim: sw=4 ts=4 noet
 */
