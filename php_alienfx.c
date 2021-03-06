#include "php_alienfx.h"

PHP_MINIT_FUNCTION(alienfx) {

	/*//. Register AlienFX Constant Values
	.//*/

	int a;
	alienfx_const_list item;

	for(a = 0; a < sizeof(alienfx_constants); a++) {
		item = alienfx_constants[a];
		if(item.name == NULL) break;

		// php_printf("%s\n",item.name);

		zend_register_long_constant(
			item.name, (strlen(item.name)+1),
			item.value,
			CONST_CS | CONST_PERSISTENT,
			module_number TSRMLS_CC
		);

		// random interesting note.
		// in geoipo (which i have only tested on unixen) i never had to do the
		// +1 to strlen. not sure what is up with that.

	}

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(alienfx) {
	return SUCCESS;
}

PHP_MINFO_FUNCTION(alienfx) {
	php_info_print_table_start();
	php_info_print_table_row(2,"Alienware AlienFX","enabled");
	php_info_print_table_end();
}

zend_module_entry alienfx_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_ALIENFX_EXTNAME,
	alienfx_functions,
	PHP_MINIT(alienfx),
	PHP_MSHUTDOWN(alienfx),
	NULL,
	NULL,
	PHP_MINFO(alienfx),
	PHP_ALIENFX_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_ALIENFX
ZEND_GET_MODULE(alienfx)
#endif
