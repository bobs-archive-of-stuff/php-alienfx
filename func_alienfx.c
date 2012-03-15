
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

PHP_FUNCTION(alienfx_get_device) {
	unsigned int status;
	long index;
	char desc[1024];
	unsigned char type;

	zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &index);

	status = LFX_GetDeviceDescription(index,desc,sizeof(desc),&type);

	if(status != LFX_SUCCESS) {
		RETURN_LONG(status*-1);
	} else {
		object_init(return_value);
		add_property_string(return_value,"desc",desc,TRUE);
		add_property_long(return_value,"type",type);
	}

}

PHP_FUNCTION(alienfx_get_num_lights) {
	unsigned int status;
	long index;
	unsigned int num;

	zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &index);

	status = LFX_GetNumLights(index,&num);

	if(status != LFX_SUCCESS) {
		RETURN_LONG(status*-1);
	} else {
		RETURN_LONG(num);
	}

}

PHP_FUNCTION(alienfx_get_light) {
	unsigned int status;
	long device, light;
	char desc[1024];

	zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &device, &light);

	status = LFX_GetLightDescription(device,light,desc,sizeof(desc));
	if(status != LFX_SUCCESS) {
		RETURN_LONG(status*-1);
	} else {
		RETURN_STRING(desc,TRUE);
	}
}
