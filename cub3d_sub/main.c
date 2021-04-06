#include "queue.h"
#include <stdio.h>

int		main(void)
{
	t_queue q;
	q.front = 0;
	q.rear = 0;

	t_position p;
	p.x = 11;
	p.y = 22;
	offer(&q, p);
	p.x = 33;
	p.y = 4;
	offer(&q, p);

	t_position tmp = poll(&q);
	printf("%d %d\n", tmp.x, tmp.y);
	tmp = poll(&q);
	printf("%d %d\n", tmp.x, tmp.y);

	free_q(&q);
	return(0);
}
