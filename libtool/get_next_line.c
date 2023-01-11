/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:10:03 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/10 21:13:14 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*gnl(int fd)
{
	int			i;
	int			j;
	char		*r;
	char		*bf;

	i = 1;
	r = NULL;
	j = 1;
	while (i)
	{
		bf = (char *)malloc(100);
		i = read(fd, bf, 100);
		if (i < 0)
			return (free(bf), NULL);
		bf[i] = '\0';
		if (ft_strchr(bf, '\n'))
			printf("|still reading...The line nb [%d]|\n", j++);
		r = ft_strjoin(r, bf);
		if (!ft_strlen(bf))
			break ;
	}
	return (r);
}
