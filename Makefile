.PHONY: hhvm

hhvm:
	${hphpizepatch}hphpize && cmake . && make && cp nshell.so /etc/hhvm/nshell.so && service hhvm restart && hhvm tests/001.php
