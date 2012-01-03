--TEST--
Test the Festival eval Command method
--FILE--
<?php
$festObj = new festival();
$return = $festObj->evalCommand('voice_lp_diphone');
$festObj->sayText('sì, io parlo italiano');
var_dump($return);
--EXPECTF--
bool(true)