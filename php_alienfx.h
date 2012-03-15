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

	// LFX_RESULT Values
	{ "ALIENFX_SUCCESS",        LFX_SUCCESS },
	{ "ALIENFX_FAILURE",        LFX_FAILURE },
	{ "ALIENFX_ERROR_NOINIT",   LFX_ERROR_NOINIT },
	{ "ALIENFX_ERROR_NODEVS",   LFX_ERROR_NODEVS },
	{ "ALIENFX_ERROR_NOLIGHTS", LFX_ERROR_NOLIGHTS },
	{ "ALIENFX_ERROR_BUFFSIZE", LFX_ERROR_BUFFSIZE },

	// LFX Positional Values
	{ "ALIENFX_FRONT_LOWER_LEFT", LFX_FRONT_LOWER_LEFT }, 
	{ "ALIENFX_FRONT_LOWER_CENTER", LFX_FRONT_LOWER_CENTER },
	{ "ALIENFX_FRONT_LOWER_RIGHT", LFX_FRONT_LOWER_RIGHT },
	{ "ALIENFX_FRONT_MIDDLE_LEFT", LFX_FRONT_MIDDLE_LEFT }, 
	{ "ALIENFX_FRONT_MIDDLE_CENTER", LFX_FRONT_MIDDLE_CENTER },
	{ "ALIENFX_FRONT_MIDDLE_RIGHT", LFX_FRONT_MIDDLE_RIGHT },
	{ "ALIENFX_FRONT_UPPER_LEFT", LFX_FRONT_UPPER_LEFT }, 
	{ "ALIENFX_FRONT_UPPER_CENTER", LFX_FRONT_UPPER_CENTER },
	{ "ALIENFX_FRONT_UPPER_RIGHT", LFX_FRONT_UPPER_RIGHT },
	{ "ALIENFX_MIDDLE_LOWER_LEFT", LFX_MIDDLE_LOWER_LEFT }, 
	{ "ALIENFX_MIDDLE_LOWER_CENTER", LFX_MIDDLE_LOWER_CENTER },
	{ "ALIENFX_MIDDLE_LOWER_RIGHT", LFX_MIDDLE_LOWER_RIGHT },
	{ "ALIENFX_MIDDLE_MIDDLE_LEFT", LFX_MIDDLE_MIDDLE_LEFT }, 
	{ "ALIENFX_MIDDLE_MIDDLE_CENTER", LFX_MIDDLE_MIDDLE_CENTER },
	{ "ALIENFX_MIDDLE_MIDDLE_RIGHT", LFX_MIDDLE_MIDDLE_RIGHT },
	{ "ALIENFX_MIDDLE_UPPER_LEFT", LFX_MIDDLE_UPPER_LEFT }, 
	{ "ALIENFX_MIDDLE_UPPER_CENTER", LFX_MIDDLE_UPPER_CENTER },
	{ "ALIENFX_MIDDLE_UPPER_RIGHT", LFX_MIDDLE_UPPER_RIGHT },
	{ "ALIENFX_REAR_LOWER_LEFT", LFX_REAR_LOWER_LEFT }, 
	{ "ALIENFX_REAR_LOWER_CENTER", LFX_REAR_LOWER_CENTER },
	{ "ALIENFX_REAR_LOWER_RIGHT", LFX_REAR_LOWER_RIGHT },
	{ "ALIENFX_REAR_MIDDLE_LEFT", LFX_REAR_MIDDLE_LEFT }, 
	{ "ALIENFX_REAR_MIDDLE_CENTER", LFX_REAR_MIDDLE_CENTER },
	{ "ALIENFX_REAR_MIDDLE_RIGHT", LFX_REAR_MIDDLE_RIGHT },
	{ "ALIENFX_REAR_UPPER_LEFT", LFX_REAR_UPPER_LEFT }, 
	{ "ALIENFX_REAR_UPPER_CENTER", LFX_REAR_UPPER_CENTER },
	{ "ALIENFX_REAR_UPPER_RIGHT", LFX_REAR_UPPER_RIGHT },
	{ "ALIENFX_ALL", LFX_ALL },
	{ "ALIENFX_ALL_RIGHT", LFX_ALL_RIGHT },
	{ "ALIENFX_ALL_LEFT", LFX_ALL_UPPER },
	{ "ALIENFX_ALL_UPPER", LFX_ALL_LOWER },
	{ "ALIENFX_ALL_LOWER", LFX_ALL_FRONT },
	{ "ALIENFX_ALL_REAR", LFX_ALL_REAR },

	// LFX Quick Colours
	{ "ALIENFX_OFF", LFX_OFF },
	{ "ALIENFX_BLACK", LFX_BLACK },
	{ "ALIENFX_RED", LFX_RED },
	{ "ALIENFX_GREEN", LFX_GREEN },
	{ "ALIENFX_BLUE", LFX_BLUE },
	{ "ALIENFX_WHITE", LFX_WHITE },
	{ "ALIENFX_YELLOW", LFX_YELLOW },
	{ "ALIENFX_ORANGE", LFX_ORANGE },
	{ "ALIENFX_PINK", LFX_PINK },
	{ "ALIENFX_CYAN", LFX_CYAN },

	// LFX Brightness Values
	{ "ALIENFX_FULL_BRIGHTNESS", LFX_FULL_BRIGHTNESS },
	{ "ALIENFX_HALF_BRIGHTNESS", LFX_HALF_BRIGHTNESS },
	{ "ALIENFX_MIN_BRIGHTNESS", LFX_MIN_BRIGHTNESS },

	// LFX Action Values
	{ "ALIENFX_ACTION_MORPH", LFX_ACTION_MORPH },
	{ "ALIENFX_ACTION_PULSE", LFX_ACTION_PULSE },
	{ "ALIENFX_ACTION_COLOR", LFX_ACTION_COLOR },

	// LFX Device Types
	{ "ALIENFX_DEVTYPE_UNKNOWN", LFX_DEVTYPE_UNKNOWN },
	{ "ALIENFX_DEVTYPE_NOTEBOOK", LFX_DEVTYPE_NOTEBOOK },
	{ "ALIENFX_DEVTYPE_DESKTOP", LFX_DEVTYPE_DESKTOP },
	{ "ALIENFX_DEVTYPE_SERVER", LFX_DEVTYPE_SERVER },
	{ "ALIENFX_DEVTYPE_DISPLAY", LFX_DEVTYPE_DISPLAY },
	{ "ALIENFX_DEVTYPE_MOUSE", LFX_DEVTYPE_MOUSE },
	{ "ALIENFX_DEVTYPE_KEYBOARD", LFX_DEVTYPE_KEYBOARD },
	{ "ALIENFX_DEVTYPE_GAMEPAD", LFX_DEVTYPE_GAMEPAD },
	{ "ALIENFX_DEVTYPE_SPEAKER", LFX_DEVTYPE_SPEAKER },
	{ "ALIENFX_DEVTYPE_OTHER", LFX_DEVTYPE_OTHER },

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
PHP_FUNCTION(alienfx_get_device);
PHP_FUNCTION(alienfx_get_num_lights);
PHP_FUNCTION(alienfx_get_light);
PHP_FUNCTION(alienfx_get_light_position);
PHP_FUNCTION(alienfx_get_light_color);
PHP_FUNCTION(alienfx_set_light_color);
PHP_FUNCTION(alienfx_light);

static zend_function_entry alienfx_functions[] = {
	PHP_FE(alienfx_initialize, NULL)
	PHP_FE(alienfx_release, NULL)
	PHP_FE(alienfx_reset, NULL)
	PHP_FE(alienfx_update, NULL)
	PHP_FE(alienfx_update_default, NULL)
	PHP_FE(alienfx_get_num_devices, NULL)
	PHP_FE(alienfx_get_device, NULL)
	PHP_FE(alienfx_get_num_lights, NULL)
	PHP_FE(alienfx_get_light, NULL)
	PHP_FE(alienfx_get_light_position, NULL)
	PHP_FE(alienfx_get_light_color, NULL)
	PHP_FE(alienfx_set_light_color, NULL)
	PHP_FE(alienfx_light, NULL)
	PHP_FE_END
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


extern zend_module_entry alienfx_module_entry;
