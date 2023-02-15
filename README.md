<h1 align="center">
  GARBAGE COLLECTOR 🛡🔰
</h1>

<p align="center">
	<b><i>  A Simple Garbage Collector implementation in C </i></b><br>
  <p align="center">
    <a href="https://github.com/anuraghazra/github-readme-stats/actions">
      <img alt="Tests Passing" src="https://github.com/anuraghazra/github-readme-stats/workflows/Test/badge.svg" />
    </a>
    <a href="https://github.com/anuraghazra/github-readme-stats/graphs/contributors">
      <img alt="GitHub Contributors" src="https://img.shields.io/github/contributors/anuraghazra/github-readme-stats" />
    </a>
    <a href="https://codecov.io/gh/anuraghazra/github-readme-stats">
      <img src="https://codecov.io/gh/anuraghazra/github-readme-stats/branch/master/graph/badge.svg" />
    <a href="https://github.com/anuraghazra/github-readme-stats/pulls">
      <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/joseph-el/Simple_Garbage_Collector_in_C?color=0088ff" />
    </a>
  </p>
 
 ### About Project 💡
- Garbage Collection (GC) is a mechanism that provides automatic memory reclamation for unused memory blocks.
- Programmers dynamically allocate memory, but when a block is no longer needed, they do not have to return it to the system explicitly with a free() call.   The GC engine takes care of recognizing that a particular block of allocated memory (heap) is not used anymore and puts it back into the free memory area.
#### How to use it
#####  Include header file of ``GC_MEMORY`` in your program.
```C
 # include "gc_memory.h"
```
###### - Generate ``gc_memory.a`` library
```SHELL
 make re
 make
```
##### > Add This in your compilation ⬇️
###### - Linking include  in you compilation
 ```Shell
 -I ./$(PATH_OF_GC_MEMORY)/include
 ```
###### - Call ``gc_memory.a`` library in your compilation
```Shell
 -L ./$(PATH_OF_GC_MEMORY)/gc_memory.a
 ```
##### For more details check :
- [Header file](/include/gc_memory.h#L27) : All information about how to use the function of gc_memory.
 
