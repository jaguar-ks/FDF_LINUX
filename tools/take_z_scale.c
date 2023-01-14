/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_z_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:08:27 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/13 02:50:30 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

double	take_i(t_fdf f)
{
	t_pst	st;
	t_pst	x;
	int		i;

	st = start_point(f.crd[0][0]);
	x = next_x(f, st);
	i = x.x - st.x;
	return (i);
}

double	take_j(t_fdf f)
{
	t_pst	st;
	t_pst	x;
	t_pst	y;
	int		j;

	st = start_point(f.crd[0][0]);
	x = next_x(f, st);
	y = next_y(f, st);
	j = (y.y - x.y)/2;
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
	zs /= 3;
	zs *= 2;
	return (zs);
}
