--TEST--
Test the Festival construtor
--FILE--
<?php
$festObj = new festival(true, 210000);
var_dump($festObj);

--EXPECTF--
object(festival)#1 (0) {
}