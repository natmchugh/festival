--TEST--
Test the Festival construtor
--FILE--
<?php
$festObj = new Festival_FestivalClass(true, 210000);
var_dump($festObj);

--EXPECTF--
object(Festival_FestivalClass)#1 (0) {
}