/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:10:03 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/14 20:49:11 by faksouss         ###   ########.fr       */
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
		bf = (char *)malloc(1000);
		i = read(fd, bf, 1000);
		if (i < 0)
			return (free(bf), NULL);
		bf[i] = '\0';
		r = ft_strjoin(r, bf);
		if (!ft_strlen(bf))
			break ;
	}
	return (r);
}
