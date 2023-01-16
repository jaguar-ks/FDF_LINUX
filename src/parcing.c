/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:33:23 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/16 20:55:26 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	map_len(int fd)
{
	int		y;
	char	*ln;

	y = 0;
	ln = gnl(fd);
	if (!ln)
		return (0);
	while (ln)
	{
		y++;
		free(ln);
		ln = gnl(fd);
	}
	close(fd);
	return (y);
}

int	map_wt(int fd, t_fdf f)
{
	int		i;
	int		ch;
	char	*ln;
	char	**x;

	ln = gnl(fd);
	x = ft_split(ln, ' ');
	ch = mtx_len(x);
	free(ln);
	deallocate(x);
	while (ln)
	{
		ln = gnl(fd);
		if (!ln)
			break ;
		x = ft_split(ln, ' ');
		i = mtx_len(x);
		free(ln);
		deallocate(x);
		if (i != ch)
			exit(error(-3));
	}
	close(fd);
	return (i);
}

t_inf	*take_x_z_cl(char **y, int j)
{
	int		i;
	t_inf	*inf;
	char	**z;

	inf = (t_inf *)malloc(sizeof(t_inf) * mtx_len(y));
	i = -1;
	while (y[++i])
	{
		inf[i].x = i;
		inf[i].y = j;
		z = ft_split(y[i], ',');
		if (mtx_len(z) == 2)
		{
			inf[i].z = ft_atoi(z[0]);
			inf[i].cl = hex_to_dec(z[1]);
		}
		else
		{
			inf[i].z = ft_atoi(z[0]);
			inf[i].cl = 0xFFFFFF;
		}
		deallocate(z);
	}
	return (deallocate(y), inf);
}

t_inf	**read_map(char *mp, t_fdf f)
{
	int		fd;
	int		i;
	char	*map;
	t_inf	**inf;

	fd = chck_opn(mp);
	inf = (t_inf **)malloc(sizeof(t_inf *) * f.dm.ht + 1);
	i = -1;
	while (++i < f.dm.ht)
	{
		map = gnl(fd);
		inf[i] = take_x_z_cl(ft_split(map, ' '), i);
		free(map);
		printf("[Done reading the line (%d)]\n", i + 1);
	}
	return (inf);
}
