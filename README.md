*Festival PHP*

Festival PHP is a PHP extension designed to offer the basic API of the festival text to speach library described here http://www.cstr.ed.ac.uk/projects/festival/manual/festival_28.html#SEC132

**Installation**
----------------------------
	e.g. on Ubuntu
	sudo apt-get install festival festival-dev festvox-don
	cd festival
	phpize
	./configure --enable-festival
	make
	sudo make install

**Usage**
----------------------------
	$festObj = new festival();
	$festObj->sayText('hello world');
	$festObj->sayText('php '.phpversion());
