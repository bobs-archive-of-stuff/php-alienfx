<?php

echo 'Starting AlienFX...', PHP_EOL;
alienfx_initialize();

echo 'Scanning devices...', PHP_EOL;
$DeviceCount = alienfx_get_num_devices();
for($DeviceID = 0; $DeviceID < $DeviceCount; $DeviceID++) {
	$Device = alienfx_get_device($DeviceID);
	echo "   Device: {$Device->desc}", PHP_EOL;

	$LightCount = alienfx_get_num_lights($DeviceID);
	echo "   THERE ARE {$LightCount} LIGHTS!", PHP_EOL;

	for($LightID = 0; $LightID < $LightCount; $LightID++) {
		$Light = alienfx_get_light($DeviceID,$LightID);
		echo "    - {$Light}", PHP_EOL;
		alienfx_set_light_color($DeviceID,$LightID,0,0,255,255);
	}

	echo 'Updating AlienFX...', PHP_EOL;
	alienfx_update();

	echo 'Sleeping so you can see...', PHP_EOL;
	sleep(3);
}

echo 'Releasing AlienFX...', PHP_EOL;
alienfx_release();

?>