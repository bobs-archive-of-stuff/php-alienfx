<?php

$list = array();
foreach(current(get_defined_functions()) as $func) {
	if(strpos($func,'alien') !== false) $list[] = $func;
}
print_r($list);

$consts = get_defined_constants(true);
print_r($consts['alienfx']);

?>