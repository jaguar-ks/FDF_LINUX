/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/14 20:57:03 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	f;
	char	*map;

	if (ac == 2)
	{
		f.crd = read_map(av[1], &map);
		f.dm = take_dmnt(map);
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, W_HT, W_WT, av[1]);
		draw_map(f);
		mlx_loop(f.mlx);
	}
}
