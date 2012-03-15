
#include "php_alienfx.h"

PHP_FUNCTION(alienfx_initialize) {
	RETURN_LONG(LFX_Initialize());
}

PHP_FUNCTION(alienfx_release) {
	RETURN_LONG(LFX_Release());
}

PHP_FUNCTION(alienfx_reset) {
	RETURN_LONG(LFX_Reset());
}

PHP_FUNCTION(alienfx_update) {
	RETURN_LONG(LFX_Update());
}

PHP_FUNCTION(alienfx_update_default) {
	RETURN_LONG(LFX_UpdateDefault());
}

PHP_FUNCTION(alienfx_get_num_devices) {
	unsigned int num;
	unsigned int status;

	status = LFX_GetNumDevices(&num);

	if(status != LFX_SUCCESS) {
		RETURN_LONG(status*-1);
	} else {
		RETURN_LONG(num);
	}
}
