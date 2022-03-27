/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senoh <senoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:38:52 by hyunwlee          #+#    #+#             */
/*   Updated: 2022/01/09 00:52:14 by senoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)&str[i]);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			k = i;
			while (1)
			{
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
				if (!(str[k + j] == to_find[j]))
					break ;
				j++;
			}
		}
		i++;
	}
	return (0);
}
