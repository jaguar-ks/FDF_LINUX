/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:10:03 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 11:55:07 by faksouss         ###   ########.fr       */
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
