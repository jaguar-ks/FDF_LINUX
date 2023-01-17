/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_z_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:08:27 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/17 06:05:14 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

double	take_i(t_fdf f)
{
	t_pst	st;
	t_pst	x;
	double	i;

	st = start_point(f.crd[0][0]);
	x = next_x(f, st);
	i = x.x - st.x;
	if (i < 1)
		i = 1;
	return (i);
}

double	take_j(t_fdf f)
{
	t_pst	st;
	t_pst	x;
	t_pst	y;
	double	j;

	st = start_point(f.crd[0][0]);
	x = next_x(f, st);
	y = next_y(f, st);
	j = (y.y - x.y) / 2;
	if (j < 0.5)
		j = 0.5;
	return (j);
}

double	take_z_scale(t_fdf f)
{
	t_pst	st;
	t_pst	x;
	t_pst	y;
	double	zs;

	st = start_point(f.crd[0][0]);
	x = next_x(f, st);
	y = next_y(f, st);
	zs = y.y - x.y;
	zs /= 6;
	zs *= 2;
	if (zs < 0.25)
		zs = 0.25;
	return (zs);
}
