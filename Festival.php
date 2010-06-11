<?php
/**
*	PHP class to represent the desired interface to be implemented in C++
*
*
*/
class Festival 
{
private $_heapSize = 0;

public function __construct($loadInitFiles, $heapSize = 210000)
{

}

public function sayFile($filename) 
{
return true;
}

public function sayText($text)
{

}

public function loadFile($filename)
{

}

public function evalCommand($command) 
{
}

public function textToWave($text)
{
return new Wave($text);
}

}
