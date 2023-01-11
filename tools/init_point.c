/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:53 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/12 00:02:00 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_pst	init_point(t_inf cr)
{
	t_pst	p;

	p.x = cr.x;
	p.y = cr.y;
	p.z = cr.z;
	p.cl = cr.cl;
	return (p);
}

t_pst	start_point(t_inf cr)
{
	t_pst	p;

	p.x = (W_HT * 250) / 1500;
	p.y = W_WT / 2;
	p.z = cr.z;
	p.cl = cr.cl;
	return (p);
}
