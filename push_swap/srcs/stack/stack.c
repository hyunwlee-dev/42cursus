/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:16:41 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/06/04 16:34:08 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_node
{
	int				value;
	struct s_stack	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*head;
	t_node	*tail;
}				t_stack;

int		is_empty()
{

}

void	push()
{

}

void	pop()
{

}

int		peek()
{

}
