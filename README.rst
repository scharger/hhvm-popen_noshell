# hhvm-popen_noshell
popen_noshell implementation for HHVM

popen_noshell: A faster implementation of popen() and system() for Linux.

Build:

.. code-block:: 
  hphpize;
  cmake . && make;


Usage:

.. code-block:: hack
   
   <?hh
   nshell_exec("ls /");

