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
#include "php_open_temporary_file.h"
extern "C" {
#include "festival_php.h"
}
#include<festival.h>
using namespace std;



/* {{{ proto resource festival_say_text()
   Says the passed in text  */
PHP_METHOD(festival, sayText)
{
char * text = NULL;
int    text_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }
	festival_say_text(text);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto resource festival_say_file()
   Says the passed in text  */
PHP_METHOD(festival, sayFile)
{
char * filename = NULL;
int    filename_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &filename, &filename_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }

festival_say_file(filename);
festival_wait_for_spooler();
RETURN_TRUE;
}
/* }}} */

/* {{{ proto resource festival_say_file()
         Says the passed in text  */
PHP_METHOD(festival, textToWave)
{
char * text = NULL;
int    text_len = 0;
char * filename = NULL;
int    filename_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &text, &text_len, &filename, &filename_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }
EST_Wave wave;
festival_text_to_wave(text,wave);
wave.save(filename,"riff");
RETVAL_STRING(filename, 1);
}
/* }}} */

PHP_METHOD(festival, __construct) {
bool load_init_files = TRUE;
int load_init_files_len = 0;
int heap_size = 210000;
int   heap_size_len = 0;
long   count = 1;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|bl", &load_init_files, &load_init_files_len, &heap_size, &heap_size_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }
    festival_initialize(load_init_files,heap_size);
}



/* {{{ proto resource evalCommand
      */
PHP_METHOD(festival, evalCommand)
{
char * command = NULL;
int    command_len = 0;
long   count = 1;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &command, &command_len, &count) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid arguments!");
        RETURN_FALSE;
    }
char est_str[command_len+2];
strcpy (est_str,"(");
strcat (est_str,command);
strcat (est_str,")");
festival_eval_command(est_str);
RETURN_TRUE;
/* return; */
}
/* }}} */


ZEND_BEGIN_ARG_INFO_EX(festival_args, 0, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry festival_functions[] = {
	{NULL, NULL, NULL}
};

PHP_MINFO_FUNCTION(festival)
{
	char version[256];
	php_info_print_table_start();
	php_info_print_table_header(2, "festival support", "enabled");
	php_info_print_table_row(2, "version", FESTIVAL_PHP_VERSION);
	php_info_print_table_end();
}

zend_class_entry *php_festival_fc_entry;
#define PHP_FESTIVAL_FC_NAME "festival"
static zend_function_entry php_festival_fc_functions [] = {
      PHP_ME(festival, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
      PHP_ME(festival, sayText, NULL, ZEND_ACC_PUBLIC)
      PHP_ME(festival, sayFile, NULL, ZEND_ACC_PUBLIC)
      PHP_ME(festival, textToWave, NULL, ZEND_ACC_PUBLIC)
      PHP_ME(festival, evalCommand, NULL, ZEND_ACC_PUBLIC)
      {NULL, NULL, NULL}
};

PHP_MINIT_FUNCTION(festival)
{
      zend_class_entry ce;
      INIT_CLASS_ENTRY(ce, PHP_FESTIVAL_FC_NAME,
                       php_festival_fc_functions);
      php_festival_fc_entry =
            zend_register_internal_class(&ce TSRMLS_CC);
      return SUCCESS;
}

zend_module_entry festival_module_entry = {
	STANDARD_MODULE_HEADER,
	"festival",
	festival_functions,
        PHP_MINIT(festival), /* MINIT */
        NULL, /* MSHUTDOWN */
	NULL,	/* RINIT */
	NULL,   /* RSHUTDOWN */
	PHP_MINFO(festival),
	FESTIVAL_PHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_FESTIVAL
BEGIN_EXTERN_C()
ZEND_GET_MODULE(festival)
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
