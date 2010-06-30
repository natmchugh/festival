--TEST--
Test the Festival say Text Method
--FILE--
<?php
$festObj = new Festival_FestivalClass();
$return = $festObj->sayText('php '.phpversion());
var_dump($return);
--EXPECTF--
bool(true)
