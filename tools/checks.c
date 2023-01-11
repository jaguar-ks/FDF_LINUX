/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:24:27 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 12:24:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	chck_opn(char *fl)
{
	int	fd;
	int	i;

	i = ft_strlen(fl);
	if (!ft_strncmp((fl + (i - 4)), ".fdf", 5))
	{
		fd = open(fl, O_RDWR);
		if (fd < 0)
			fd = -1;
	}
	else
		fd = -2;
	if (fd < 0)
		exit(error(fd));
	return (fd);
}

int	chck_map(char **map)
{
	int		*x;
	char	**ax;
	int		i;
	int		j;

	i = -1;
	x = (int *)malloc(mtx_len(map) * sizeof(int));
	if (!x)
		return (-1);
	while (map[++i])
	{
		ax = ft_split(map[i], ' ');
		x[i] = mtx_len(ax);
		deallocate(ax);
	}
	j = -1;
	while (++j < i)
		if (x[j] != x[i - 1])
			return (free(x), 0);
	return (free(x), 1);
}
