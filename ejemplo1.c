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
 
const char* s1 = R"foo(
Hello
World
)foo";
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
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
	gets(response);

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
    char *ptr_char  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}

/*
  gcc compilation:

  - ejemplo1.c: In function 'gets_example_func':
  - ejemplo1.c:34:16: warning: 'return' with a value, in function returning void
          return 1;
                  ^
  - ejemplo1.c:30:6: note: declared here
  void gets_example_func(void) {
        ^~~~~~~~~~~~~~~~~
  ejemplo1.c

  gcc compilation with -std=c99

  -ejemplo1.c:24:19: warning: missing terminating " character
    const char* s1 = R"foo(
                      ^
  -ejemplo1.c:24:19: error: missing terminating " character
    const char* s1 = R"foo(
                      ^~~~~
  -ejemplo1.c:24:18: error: 'R' undeclared here (not in a function)
    const char* s1 = R"foo(
                      ^
  -ejemplo1.c:25:1: error: expected ',' or ';' before 'Hello'
    Hello
    ^~~~~
  -ejemplo1.c:27:5: warning: missing terminating " character
    )foo";
        ^
  -ejemplo1.c:27:5: error: missing terminating " character
    )foo";
        ^~
  -ejemplo1.c: In function 'gets_example_func':
  -ejemplo1.c:34:16: warning: 'return' with a value, in function returning void
            return 1;
                    ^
  -ejemplo1.c:30:6: note: declared here
    void gets_example_func(void) {
          ^~~~~~~~~~~~~~~~~
  -ejemplo1.c: In function 'main':
  -ejemplo1.c:96:11: error: 's2' undeclared (first use in this function)
        puts (s2);
              ^~
  -ejemplo1.c:96:11: note: each undeclared identifier is reported only once for each function it appears in


  gcc compilation with -std=c99

  -ejemplo1.c:24:19: warning: missing terminating " character
  const char* s1 = R"foo(
                   ^
  -ejemplo1.c:24:19: error: missing terminating " character
  const char* s1 = R"foo(
                    ^~~~~
  -ejemplo1.c:24:18: error: 'R' undeclared here (not in a function)
  const char* s1 = R"foo(
                    ^
  -ejemplo1.c:25:1: error: expected ',' or ';' before 'Hello'
  Hello
  ^~~~~
  -ejemplo1.c:27:5: warning: missing terminating " character
  )foo";
      ^
  -ejemplo1.c:27:5: error: missing terminating " character
  )foo";
      ^~
  -ejemplo1.c: In function 'gets_example_func':
  -ejemplo1.c:34:16: warning: 'return' with a value, in function returning void
          return 1;
                  ^
  -ejemplo1.c:30:6: note: declared here
  void gets_example_func(void) {
        ^~~~~~~~~~~~~~~~~
  -ejemplo1.c: In function 'main':
  -ejemplo1.c:96:11: error: 's2' undeclared (first use in this function)
      puts (s2);
            ^~
  -ejemplo1.c:96:11: note: each undeclared identifier is reported only once for each function it appears in

*/

/*
  g++ compilation:
  
  - ejemplo1.c: In function 'void gets_example_func()':
  
  - ejemplo1.c:34:16: error: return-statement with a value, in function returning 'void' [-fpermissive]
         return 1;

  - ejemplo1.c:69:23: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *ptr_char  = "new string literal";

*/
