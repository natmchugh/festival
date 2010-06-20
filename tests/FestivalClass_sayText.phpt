--TEST--
Test the Festival say Text Method
--FILE--
<?php
error_reporting(E_ALL ^ E_DEPRECATED);
$festObj = new Festival_FestivalClass();
$festObj->sayText('php '.phpversion());
--EXPECTF--
