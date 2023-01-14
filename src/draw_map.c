/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:27:41 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/14 20:22:57 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

void	draw_map(t_fdf f)
{
	t_pst	st;
	t_pst	nt;
	t_pst	j;
	t_pst	i;
	int		y;
	int		x;

	f.du = init_drawing_unit(f.dm);
	f.zs = take_z_scale(f);
	f.i = take_i(f);
	f.j = take_j(f);
	st = start_point(f.crd[0][0]);
	y = 0;
	while (y < f.dm.ht - 1)
	{
		x = 0;
		i = next_x_crd(f, st, f.crd[y][x], f.crd[y][x + 1]);
		j = next_y_crd(f, st, f.crd[y][x], f.crd[y + 1][x]);
		nt = j;
		while (x < f.dm.wt - 1)
		{
			draw_line(f, st, i);
			draw_line(f, st, j);
			x++;
			st = i;
			j = next_y_crd(f, st, f.crd[y][x], f.crd[y + 1][x]);
			i = next_x_crd(f, st, f.crd[y][x], f.crd[y][x + 1]);
		}
		y++;
		st = nt;
	}
}