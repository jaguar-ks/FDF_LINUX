/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_dm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:25 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/15 22:29:49 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

t_dmt	take_dmnt(char *map)
{
	int		fd;
	t_dmt	dm;

	fd = chck_opn(map);
	dm.ht = map_len(fd);
	printf("[Done taking the hight]\n");
	fd = chck_opn(map);
	dm.wt = map_wt(fd);
	printf("[Done taking the whight]\n");
	return (dm);
}
