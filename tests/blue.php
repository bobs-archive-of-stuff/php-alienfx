<?php

alienfx_initialize();

$DeviceCount = alienfx_get_num_devices();
for($DeviceID = 0; $DeviceID < $DeviceCount; $DeviceID++) {
	$Device = alienfx_get_device($DeviceID);
	echo "Device: {$Device->desc}", PHP_EOL;

	$LightCount = alienfx_get_num_lights($DeviceID);
	echo "THERE ARE {$LightCount} LIGHTS!", PHP_EOL;

	for($LightID = 0; $LightID < $LightCount; $LightID++) {
		$Light = alienfx_get_light($DeviceID,$LightID);
		echo " - {$Light}", PHP_EOL;
	}
}

alienfx_release();

?>