/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:01:29 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:48 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;
	void	*content;

	tmp = 0;
	if (!lst)
		return (tmp);
	while (lst)
	{
		if ((*f))
			content = (*f)(lst->content);
		else
			content = lst->content;
		tmp2 = ft_lstnew(content);
		if (!tmp2)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&tmp, tmp2);
		lst = lst->next;
	}
	return (tmp);
}
