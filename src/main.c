/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/16 23:26:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	f;
	int		i;

	if (ac == 2)
	{
		f.dm = take_dmnt(av[1]);
		f.crd = read_map(av[1], f);
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, W_HT, W_WT, av[1]);
		draw_map(f);
		mlx_loop(f.mlx);
		i = -1;
		while (f.crd[++i])
			free(f.crd[i]);
		free(f.crd);
	}
}
