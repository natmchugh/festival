--TEST--
Test the Festival construtor
--FILE--
<?php
$festObj = new Festival_FestivalClass();
var_dump($festObj);

--EXPECTF--
object(Festival_FestivalClass)#1 (0) {
}