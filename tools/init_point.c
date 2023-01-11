/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:37:53 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 15:43:02 by faksouss         ###   ########.fr       */
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

	p.x = 200;
	p.y = 500;
	p.z = cr.z;
	p.cl = cr.cl;
	return (p);
}
