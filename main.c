#include <stdio.h>
#include <stdlib.h>

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

int initialize_employee_id(void)
{
    static int id = 0;
    id++;
    return id;
}

int main()
{

    struct __attribute__((__packed__)) employee_entry {
        char c;
        int i;
    };

    struct employee_entry *richard = malloc(sizeof(struct employee_entry));
    richard->c = 'r';
    richard->i = initialize_employee_id();

    struct employee_entry *emily = malloc(sizeof(struct employee_entry));
    emily->c = 'e';
    emily->i = initialize_employee_id();



    printf("c = %c i = %d \n", richard->c, richard->i);
    printf("c = %c i = %d \n", emily->c, emily->i);

    free(richard);
    free(emily);

    return 0;
}