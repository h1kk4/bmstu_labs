## Laboratory work XV

Данная лабораторная работа посвещена изучению инструментов статического и динамического анализа кода
```ShellSession
$ open http://cppcheck.sourceforge.net
```

## Tasks

- [x] 1. Ознакомиться со ссылками учебного материала
- [x] 2. Используя **cpplint** провести анализ проекта на **C++**
- [x] 3. Используя **Cppcheck** провести анализ проекта на **C++**
- [x] 4. Используя **OCLint** провести анализ проекта на **C++**
- [x] 5. Используя **Valgrind** провести анализ проекта на **C++**
- [x] 6. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

## cpplint
```ShellSession
$ cpplint main.cpp
Done processing main.cpp
```
## cppcheck
```ShellSession
$ cppcheck main.cpp
Checking main.cpp...
```

## oclint
```ShellSession
$oclint main.cpp -- -c

OCLint Report

Summary: TotalFiles=1 FilesWithViolations=0 P1=0 P2=0 P3=0 


[OCLint (http://oclint.org) v0.13]
```

## valgrind
```ShellSession
$ valgrind --tool=memcheck g++ main.cpp -o output -std=c++11
==15779== Memcheck, a memory error detector
==15779== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==15779== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==15779== Command: g++ main.cpp -o output -std=c++11
==15779==
==15779==
==15779== HEAP SUMMARY:
==15779==     in use at exit: 152,798 bytes in 207 blocks
==15779==   total heap usage: 362 allocs, 155 frees, 174,800 bytes allocated
==15779==
==15779== LEAK SUMMARY:
==15779==    definitely lost: 35,514 bytes in 136 blocks
==15779==    indirectly lost: 82 bytes in 5 blocks
==15779==      possibly lost: 0 bytes in 0 blocks
==15779==    still reachable: 117,202 bytes in 66 blocks
==15779==         suppressed: 0 bytes in 0 blocks
==15779== Rerun with --leak-check=full to see details of leaked memory
==15779==
==15779==  For counts of detected and suppressed errors, rerun with: -v
==15779==  ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```