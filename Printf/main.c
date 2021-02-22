#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	int one;
	int two;

	one = 0;
	two = 0;

	//ft_printf("%s, %c, %d, %u, %x, %X","1", 1, 1, 1, 1, 1);
	one = ft_printf("%d, %u, %x, %X\n", 97, 4294967284, 4294967284, 4294967284);
	two = printf("%d, %u, %x, %X\n", 97, 4294967284, 4294967284, 4294967284);
	printf("[%d / %d]\n", one, two);
	return (0);
}
