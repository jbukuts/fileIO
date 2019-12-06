# fileIO
Program that displays the use of `open()`, `fopen()`, and `mmap()` for file I/O

## Compilation
included makefile has multiple options
- `make` will run the `test`  option in the makefile which will clean the directory and then proceed to run a test case on all three of the APIs showing both the original file and the new file
- `make build` will compile all three sub projects
- `make sub_one` will only compile the first sub project and nothing else
- `make sub_two` will only compile the second sub project and nothing else
- `make sub_three` will only compile the third sub project and nothing else
- `make clean` of course will clean the working the directory of compiled files

## Usage
Once compiled each sub project will have its own executable either by the name of `sub_one`, `sub_two`, or `sub_three` with them relating each sub project respectively. 

In order to properly execute each of the programs the proper usage is:
`./sub_one [file_path]`

Order is the same for both sub projects.
