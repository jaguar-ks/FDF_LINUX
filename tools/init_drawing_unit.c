/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing_unit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:15:59 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 18:11:35 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	init_drawing_unit(t_dmt dm)
{
	int	md;
	int	wd;
	int	du;

	wd = sqrt(pow(W_HT, 2) + pow(W_WT, 2));
	md = sqrt(pow(dm.ht, 2) + pow(dm.wt, 2));
	du = ((wd * 50) / 100) / md;
	if (du < 2)
		du = 2;
	return (du);
}
