#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

void optionThree(){
    char *s = (char *) malloc(100);
    free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

/*

Error found:

==36813==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x7fa981a522c3 bp 0x7ffffc60ef10 sp 0x7ffffc60e6b8
WRITE of size 19 at 0x60b0000000f0 thread T0
    #0 0x7fa981a522c2 in __interceptor_memcpy ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827
    #1 0x560dc7c8849b in optionThree (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x149b)
    #2 0x560dc7c88803 in main (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x1803)
    #3 0x7fa981819d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7fa981819e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x560dc7c882e4 in _start (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x12e4)

0x60b0000000f0 is located 0 bytes inside of 100-byte region [0x60b0000000f0,0x60b000000154)
freed by thread T0 here:
    #0 0x7fa981acc517 in __interceptor_free ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:127
    #1 0x560dc7c88480 in optionThree (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x1480)
    #2 0x560dc7c88803 in main (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x1803)
    #3 0x7fa981819d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

previously allocated by thread T0 here:
    #0 0x7fa981acc867 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x560dc7c88470 in optionThree (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x1470)
    #2 0x560dc7c88803 in main (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x1803)
    #3 0x7fa981819d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-use-after-free ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827 in __interceptor_memcpy
Shadow bytes around the buggy address:
  0x0c167fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c167fff8000: fa fa fa fa fa fa fa fa fd fd fd fd fd fd fd fd
=>0x0c167fff8010: fd fd fd fd fd fa fa fa fa fa fa fa fa fa[fd]fd
  0x0c167fff8020: fd fd fd fd fd fd fd fd fd fd fd fa fa fa fa fa
  0x0c167fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c167fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==36813==ABORTING

This error happens because we make a call to the free function. 
This function deallocates the memory previously allocated by a call to calloc, malloc, or realloc. So we are trying to copy a string 
in a location with no space allocated for it.

*/

void optionFour(){
    char *s = (char *) malloc(18);
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

/*

Error found:

==36857==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000052 at pc 0x7fc4ca5982c3 bp 0x7ffc4f6c2a30 sp 0x7ffc4f6c21d8
WRITE of size 19 at 0x603000000052 thread T0
    #0 0x7fc4ca5982c2 in __interceptor_memcpy ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827
    #1 0x556f9f6eb4ee in optionFour (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x14ee)
    #2 0x556f9f6eb80f in main (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x180f)
    #3 0x7fc4ca35fd8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #4 0x7fc4ca35fe3f in __libc_start_main_impl ../csu/libc-start.c:392
    #5 0x556f9f6eb2e4 in _start (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x12e4)

0x603000000052 is located 0 bytes to the right of 18-byte region [0x603000000040,0x603000000052)
allocated by thread T0 here:
    #0 0x7fc4ca612867 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x556f9f6eb4cf in optionFour (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x14cf)
    #2 0x556f9f6eb80f in main (/home/xabier/Escritorio/DPS/lab1-strings-Xabier-Barguilla/ejemplo2+0x180f)
    #3 0x7fc4ca35fd8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:827 in __interceptor_memcpy
Shadow bytes around the buggy address:
  0x0c067fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00[02]fa fa fa fa fa
  0x0c067fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==36857==ABORTING


The error happens because the line "char *s = (char *) malloc(18)" declares that the maximum length is 18. However, the length of "Welcome Sanitizer!" is 19.

*/


int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}