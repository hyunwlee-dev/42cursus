/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:30:40 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/07/30 18:26:02 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    init_deques(t_deque *a_deque, t_deque *b_deque, int argc, char **argv)
{
    int idx;

    idx = 0;
    a_deque->head = NULL;
	a_deque->tail = NULL;
	a_deque->size = 0;
	b_deque->head = NULL;
	b_deque->tail = NULL;
	b_deque->size = 0;
    while (++idx < argc)
    {
        if (add_rear(a_deque, ft_atoi(argv[idx])))
        {
            clear(a_deque, b_deque);
            ft_putstr("ERROR\n");
            return (-1);
        }
    }
    return (0);
}

t_node	*creat_node(t_node *l_link, t_node *r_link, int value, int idx)
{
	t_node *node;
    
	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
    node->idx = idx;
	node->value = value;
	node->l_link = l_link;
	node->r_link = r_link;
	return (node);
}

int add_front(t_deque *deque, int value)
{
	t_node *new_node;
    
    if (!(new_node = creat_node(deque->tail, deque->head, value, deque->size)))
        return(-1);
	if (!deque->size)
	{
		deque->head = new_node;
		deque->tail = new_node;
	}
	else
	{
		deque->head->l_link = new_node;
		deque->head = new_node;
		deque->tail->r_link = deque->head;
	}
	++deque->size;
    return (0);
}

int     add_rear(t_deque *deque, int value)
{
	t_node *new_node;
    
    if (!(new_node = creat_node(deque->tail, deque->head, value, deque->size)))
        return (-1);
	if (!deque->size)
	{
		deque->head = new_node;
		deque->tail = new_node;
	}
	else
	{
		deque->tail->r_link = new_node;
		deque->tail = new_node;
		deque->head->l_link = deque->tail;
	}
	++deque->size;
    return (0);
}

int		delete_front(t_deque *deque)
{
	t_node 	*removed_node;
    int     value;

    value = 0;
	if (deque->size == 0)
	{
        ft_putstr("ERROR\n");
		exit(1);
	}
   else if (deque->size == 1)
   {
        value = deque->head->value;
        free(deque->head);
        deque->head = NULL;
        deque->tail = NULL;
   }
	else
	{
		removed_node = deque->head;
		value = removed_node->value;
		deque->head = deque->head->r_link;
		free(removed_node);
		deque->tail->r_link = deque->head;
		deque->head->l_link = deque->tail;
        // t_node *now_node = deque->head;
        // while (now_node->idx != deque->size - 1)
        // {
        //     now_node->idx--;
        //     now_node = now_node->r_link;
        // }
        // now_node->idx--;
	}
	--deque->size;
	return (value);
}

// void    decrease_nodes_idx(t_node *node,int deq_size)
// {
//     int i;

//     i = 0;
//     while (++i < deq_size)
//     {
//         node->
//     }
// }
void    increase_idxs()
{
    
}

int		delete_rear(t_deque *deque)
{
	t_node 	*removed_node;
	int 	value;

    value = 0;
	if (!deque->size)
	{
        ft_putstr("ERROR\n");
		exit(1);
	}
    else if (deque->size == 1)
    {
        value = deque->head->value;
        free(deque->head);
        deque->head = NULL;
        deque->tail = NULL;
    }
	else
	{
		removed_node = deque->tail;
		value = removed_node->value;
		deque->tail = deque->tail->l_link;
		free(removed_node);
		deque->head->l_link = deque->tail;
		deque->tail->r_link = deque->head;
	}
	--deque->size;
	return (value);
}

int		get_front(t_deque *deque)
{
	if (!deque->size)
	{
        ft_putstr("ERROR\n");
		exit(1);
	}
	return (deque->head->value);
}

int		get_rear(t_deque *deque)
{
	if (!deque->size)
	{
        ft_putstr("ERROR\n");
		exit(1);
	}
	return (deque->tail->value);
}

void    clear(t_deque *a_deque, t_deque *b_deque)
{
    while (a_deque->size)
    {
        ft_putnbr(delete_front(a_deque));
        ft_putstr("\n");
    }
    ft_putstr("-------------\n");
    while (b_deque->size)
    {
        ft_putnbr(delete_front(b_deque));
        ft_putstr("\n");
    }
}

// int     find_pivot(t_deque deque)
// {
    
// }

void    print_all(t_deque *deque)
{
    int idx = -1;
    t_node *node = deque->head;

    ft_putstr("🥲🥲🥲🥲🥲🥲🥲🥲🥲🥲\n");
    while (++idx < deque->size)
    {
        ft_putstr("idx: ");
        ft_putnbr(node->idx);
        ft_putstr("\t");
        ft_putstr("value: ");
        ft_putnbr(node->value);
        ft_putstr("\n");
        ft_putstr("\n");
        node = node->r_link;
    }
    ft_putstr("🥲🥲🥲🥲🥲🥲🥲🥲🥲🥲\n");
}