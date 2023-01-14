/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:53 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/14 20:45:04 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_pst	init_point(t_inf cr)
{
	t_pst	p;

	p.x = cr.x;
	p.y = cr.y;
	p.cl = cr.cl;
	return (p);
}

t_pst	start_point(t_inf cr)
{
	t_pst	p;

	p.x = ((W_HT * 250) / 1500);
	p.y = (W_WT / 6) * 4;
	p.cl = cr.cl;
	return (p);
}
