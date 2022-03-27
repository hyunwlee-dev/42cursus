#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 11;
    // cnt = 0;
    // hi:
    // cnt = 3;

    // %[flag][width][.precision]서식지정자

    // *format == "d hi:%d\n"
    // init_options(&op);
    //
    // 
    // minus, 
    // zero, 
    // width, 
    // precision, 
    // is_precision, 
    // nbr_minus, 
    // type
    ft_printf("hi:%d hi:%d\n", a, b);
    printf("%-*d\n", 4, a);
    printf("%s\n", NULL);
    return (0);
}