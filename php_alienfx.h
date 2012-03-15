#ifndef PHP_ALIENFX_H
#define PHP_ALIENFX_H 1
#endif

#include "php.h"
#include "LFX2.h"

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_ALIENFX_VERSION "1.0.0"
#define PHP_ALIENFX_EXTNAME "alienfx"

////////////////////////////////////////////////////////////////////////////////
// AlienFX Constants ///////////////////////////////////////////////////////////

typedef struct _alienfx_const_list {
	const char *name;
	long value;        
} alienfx_const_list;

static alienfx_const_list alienfx_constants[] = {
	{ "ALIENFX_SUCCESS",        LFX_SUCCESS },
	{ "ALIENFX_FAILURE",        LFX_FAILURE },
	{ "ALIENFX_ERROR_NOINIT",   LFX_ERROR_NOINIT },
	{ "ALIENFX_ERROR_NODEVS",   LFX_ERROR_NODEVS },
	{ "ALIENFX_ERROR_NOLIGHTS", LFX_ERROR_NOLIGHTS },
	{ "ALIENFX_ERROR_BUFFSIZE", LFX_ERROR_BUFFSIZE },
	{ NULL,   0 }
};

////////////////////////////////////////////////////////////////////////////////
// AlienFX Functions ///////////////////////////////////////////////////////////

PHP_FUNCTION(alienfx_initialize);
PHP_FUNCTION(alienfx_release);
PHP_FUNCTION(alienfx_reset);
PHP_FUNCTION(alienfx_update);
PHP_FUNCTION(alienfx_update_default);
PHP_FUNCTION(alienfx_get_num_devices);

static zend_function_entry alienfx_functions[] = {
	PHP_FE(alienfx_initialize, NULL)
	PHP_FE(alienfx_release, NULL)
	PHP_FE(alienfx_reset, NULL)
	PHP_FE(alienfx_update, NULL)
	PHP_FE(alienfx_update_default, NULL)
	PHP_FE(alienfx_get_num_devices, NULL)
	PHP_FE_END
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


extern zend_module_entry alienfx_module_entry;
