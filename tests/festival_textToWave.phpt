--TEST--
Test the Festival method text to wave
--FILE--
<?php
$festObj = new festival();
$temp_name = tempnam('pre', '/tmp');
$return = $festObj->textToWave('php '.phpversion(), $temp_name);
echo $return,PHP_EOL;
var_dump($return == $temp_name);
var_dump(file_exists($return));
--EXPECTF--
/tmp/tmp%s
bool(true)
bool(true)