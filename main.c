#include <stdio.h>

#define A_MACRO 123
#undef A_MACRO 

/*
Macros (#)
define - defines a macro
undef - undefines a macro
include - includes a file
if - conditional compilation directive
ifdef - checks if macro is defined
ifndef - checks if macro is not defined
elif - else if condition
else - else condition
endif - ends a if, ifdef of ifndef block
error - generated compiler error
pragma - specified diverse behavior based on compiler
line - specified original line number and file name
warning - in gcc, generates a compiler warning with a specified message

Good practice to #define a variable constant i.e. #define MAX_IDS 32

*/
// What are the best practices when using macros

/*

*/

int main()
{
    // printf("Hello world!\n");

    // char my_str[] = {'h', 'e', 'l', 'l', 'o'};

    struct __attribute__((__packed__)) my_struct {
        int i;
        char c;
    };

    struct my_struct str;


    // printf("%s\n", my_struct);
    printf("%ld\n", sizeof(str));

    return 0;
}