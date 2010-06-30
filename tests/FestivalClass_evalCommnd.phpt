--TEST--
Test the Festival eval Command method
--FILE--
<?php
$festObj = new Festival_FestivalClass();
$return = $festObj->evalCommand('voice_don_diphone');
$festObj->sayText('I am a different voice');
var_dump($return);
--EXPECTF--
bool(true)