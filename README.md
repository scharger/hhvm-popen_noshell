# hhvm-popen_noshell
popen_noshell implementation for HHVM

popen_noshell: A faster implementation of popen() and system() for Linux.

## Build:

```shell
  hphpize;
  cmake . && make;
```

## Usage:

```hack
   <?hh
   nshell_exec("ls /");
```
