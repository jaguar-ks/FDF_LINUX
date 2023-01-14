/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_crd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:04:45 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/14 18:50:26 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_pst	take_crd(t_fdf f, int x, int y)
{
	t_pst	wn;

	wn.x = f.crd[x][y].x * f.i;  
}

t_pst	**win_crd(t_fdf f)
{
	t_pst	**wn;
	int		x;
	int		y;

	wn = (t_pst **)malloc(sizeof(t_pst *) * f.dm.ht);
	y = -1;
	while (++y < f.dm.ht)
	{
		x = -1;
		wn[y] = (t_pst *)malloc(sizeof(t_pst) * f.dm.wt);
		while (++x < f.dm.wt)
		{
			if (!y && !x)
				wn[y][x] = start_point(f.crd[0][0]);
			else
			{
				wn[y][x].x += f.i;
				wn[y][x].y -= f.j;
				wn[y][x].cl = f.crd[y][x].cl;
			}
		}
	}
}
