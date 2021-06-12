#include "libft.h"
#include <stdio.h>

int main(void)
{
	int rgb[3];
	int color;
	
	rgb[0] = 225;
	rgb[1] = 30;
	rgb[2] = 0;
	color = rgb[0];

	color = (rgb[0] << 16);
	color += (rgb[1] << 8);
	color += rgb[2];
	printf("color: %d", color);
	printf("color: %x", color);
	return (0);
}
