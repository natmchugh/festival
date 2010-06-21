--TEST--
Test the Festival say File Method
--FILE--
<?php
$festObj = new Festival_FestivalClass();
$return = $festObj->sayFile(__FILE__);
var_dump($return);
--EXPECTF--
bool(true)