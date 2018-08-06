# Problem
Sometimes our program has this architechure:

1. Exectuable applicaion: A
2. Static libray: S
3. A dynamic library: D

S is linked in A. and A dynamic load D in runtime.
if A function F isn't used by A, but is used by D, 
there will be an error shows undefined F when D is be loaded.

# solutioin
There are two solution to solve the problem:

- link S to a dynmac libarary.
- use some link options. 

The link_symbol shows two samples of the solutions.

# Key notes

## Link all symbols of archives to target
_-Wl,--whole-archive -l{libname}_ 

Libraries that come after the option 
in the command line will not have unreferenced symbols discarded.

*-Wl,--no-whole-archive* 

Stop link all symbols of arhives.

## Link archives to a dynamic library
Use *-Wl,--whole-archive* for the linking to include the entire .a file Edit, 
you'll need to add *-Wl,--no-whole-archive* after you specify your library 
as well, so the whole thing will be 

	-Wl,--whole-archive archive1.a archive2.a -Wl,--no-whole-archive

## Export all dynamic symbols
*-Wl,-export-dynamic*

Regular executables such as test3 do not export their variables and routines 
as dynamic symbols by default. 
You need to use the *-export-dynamic* directive to specifically 
export the variables and routines.

## Link and load dynmaic library in a directory
*-Wl,-rpath*

When shared libraries are present in non default directories, 
you need to supply an additional linker option, 
usually -R or -Wl,-rpath=, with a run-time library path.

	gcc -o foo foo.c -L$(prefix)/lib -lfoo -Wl,-rpath=$(prefix)/lib

