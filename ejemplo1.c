/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) != NULL) {
        buf[strlen(buf) - 1] = '\0';
  }
  
}

const char *get_dirname(char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	fgets(response, sizeof( response ), stdin);

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char ptr_char[]  = "new string literal";
    //int size_array1 = strlen("аналитик");
    //int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
   //char analitic3[100]="аналитик";


        
    //strcpy(key, argv[1]);  Removed due to sementation fault
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return argc;
}

/*
  gcc compilation:

  ejemplo1.c: In function ‘gets_example_func’:
  ejemplo1.c:34:16: warning: ‘return’ with a value, in function returning void
    34 |         return 1;
        |                ^
  ejemplo1.c:30:6: note: declared here
    30 | void gets_example_func(void) {
        |      ^~~~~~~~~~~~~~~~~
  ejemplo1.c: In function ‘get_y_or_n’:
  ejemplo1.c:53:9: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
    53 |         gets(response);
        |         ^~~~
        |         fgets
  /usr/bin/ld: /tmp/ccymeojN.o: en la función `get_y_or_n':
  ejemplo1.c:(.text+0xe7): aviso: the `gets' function is dangerous and should not be used.


  gcc compilation with -std=c99

  ejemplo1.c:24:19: warning: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^
  ejemplo1.c:24:19: error: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^~~~~
  ejemplo1.c:24:18: error: ‘R’ undeclared here (not in a function)
    24 | const char* s1 = R"foo(
        |                  ^
  ejemplo1.c:25:1: error: expected ‘,’ or ‘;’ before ‘Hello’
    25 | Hello
        | ^~~~~
  ejemplo1.c:27:5: warning: missing terminating " character
    27 | )foo";
        |     ^
  ejemplo1.c:27:5: error: missing terminating " character
    27 | )foo";
        |     ^~
  ejemplo1.c: In function ‘gets_example_func’:
  ejemplo1.c:34:16: warning: ‘return’ with a value, in function returning void
    34 |         return 1;
        |                ^
  ejemplo1.c:30:6: note: declared here
    30 | void gets_example_func(void) {
        |      ^~~~~~~~~~~~~~~~~
  ejemplo1.c: In function ‘get_y_or_n’:
  ejemplo1.c:53:9: warning: ‘gets’ is deprecated [-Wdeprecated-declarations]
    53 |         gets(response);
        |         ^~~~
  In file included from ejemplo1.c:15:
  /usr/include/stdio.h:605:14: note: declared here
    605 | extern char *gets (char *__s) __wur __attribute_deprecated__;
        |              ^~~~
  ejemplo1.c: In function ‘main’:
  ejemplo1.c:96:11: error: ‘s2’ undeclared (first use in this function); did you mean ‘s1’?
    96 |     puts (s2);
        |           ^~
        |           s1
  ejemplo1.c:96:11: note: each undeclared identifier is reported only once for each function it appears in


  gcc compilation with -std=c11

  ejemplo1.c:24:19: warning: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^
  ejemplo1.c:24:19: error: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^~~~~
  ejemplo1.c:24:18: error: ‘R’ undeclared here (not in a function)
    24 | const char* s1 = R"foo(
        |                  ^
  ejemplo1.c:25:1: error: expected ‘,’ or ‘;’ before ‘Hello’
    25 | Hello
        | ^~~~~
  ejemplo1.c:27:5: warning: missing terminating " character
    27 | )foo";
        |     ^
  ejemplo1.c:27:5: error: missing terminating " character
    27 | )foo";
        |     ^~
  ejemplo1.c: In function ‘gets_example_func’:
  ejemplo1.c:34:16: warning: ‘return’ with a value, in function returning void
    34 |         return 1;
        |                ^
  ejemplo1.c:30:6: note: declared here
    30 | void gets_example_func(void) {
        |      ^~~~~~~~~~~~~~~~~
  ejemplo1.c: In function ‘get_y_or_n’:
  ejemplo1.c:53:9: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
    53 |         gets(response);
        |         ^~~~
        |         fgets
  ejemplo1.c: In function ‘main’:
  ejemplo1.c:96:11: error: ‘s2’ undeclared (first use in this function); did you mean ‘s1’?
    96 |     puts (s2);
        |           ^~
        |           s1
  ejemplo1.c:96:11: note: each undeclared identifier is reported only once for each function it appears in

/*
  g++ compilation:
  
  ejemplo1.c:24:19: warning: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^
  ejemplo1.c:24:19: error: missing terminating " character
    24 | const char* s1 = R"foo(
        |                   ^~~~~
  ejemplo1.c:24:18: error: ‘R’ undeclared here (not in a function)
    24 | const char* s1 = R"foo(
        |                  ^
  ejemplo1.c:25:1: error: expected ‘,’ or ‘;’ before ‘Hello’
    25 | Hello
        | ^~~~~
  ejemplo1.c:27:5: warning: missing terminating " character
    27 | )foo";
        |     ^
  ejemplo1.c:27:5: error: missing terminating " character
    27 | )foo";
        |     ^~
  ejemplo1.c: In function ‘gets_example_func’:
  ejemplo1.c:34:16: warning: ‘return’ with a value, in function returning void
    34 |         return 1;
        |                ^
  ejemplo1.c:30:6: note: declared here
    30 | void gets_example_func(void) {
        |      ^~~~~~~~~~~~~~~~~
  ejemplo1.c: In function ‘get_y_or_n’:
  ejemplo1.c:53:9: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
    53 |         gets(response);
        |         ^~~~
        |         fgets
  ejemplo1.c: In function ‘main’:
  ejemplo1.c:96:11: error: ‘s2’ undeclared (first use in this function); did you mean ‘s1’?
    96 |     puts (s2);
        |           ^~
        |           s1
  ejemplo1.c:96:11: note: each undeclared identifier is reported only once for each function it appears in
*/
