--TEST--
Test the Festival eval Command method
--FILE--
<?php
$festObj = new festival();
$return = $festObj->evalCommand('voice_rab_diphone');
$festObj->sayText('I am a different voice');
var_dump($return);
--EXPECTF--
bool(true)