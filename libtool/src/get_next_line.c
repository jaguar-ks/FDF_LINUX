/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:10:03 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/12 00:14:00 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/libft.h"

char	*gnl(int fd)
{
	int			i;
	char		*r;
	char		*bf;

	i = 1;
	r = NULL;
	while (i)
	{
		bf = (char *)malloc(10000);
		i = read(fd, bf, 10000);
		if (i < 0)
			return (free(bf), NULL);
		bf[i] = '\0';
		r = ft_strjoin(r, bf);
		if (!ft_strlen(bf))
			break ;
	}
	return (r);
}
