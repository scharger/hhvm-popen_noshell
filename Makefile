.PHONY: hhvm

hhvm:
	hphpize && cmake . && make && cp nshell.so /etc/hhvm/nshell.so && service hhvm restart && hhvm tests/test.php
