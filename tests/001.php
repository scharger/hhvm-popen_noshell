<?hh // partial

echo "Check:\n";
echo "\tnshell_exec function exists: ";
if (function_exists("nshell_exec")) {
	echo "yes\n";
	echo "\t\tcheck nshell_exec function (expect: return of 'ls /' ): ";
	echo nshell_exec("ls /");
} else {
		echo "no\n";
}