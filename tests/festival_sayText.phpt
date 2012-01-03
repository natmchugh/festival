--TEST--
Test the Festival say Text Method
--FILE--
<?php
$festObj = new festival();
$return = $festObj->sayText('php '.phpversion());
var_dump($return);
--EXPECTF--
bool(true)
