/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:54 by deman_wolf        #+#    #+#             */
/*   Updated: 2023/01/10 21:04:23 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	main(int ac, char **av)
{
	// void	*mlx;
	// void	*win;
	t_inf	**crd;
	char	*map;
	t_dmt	dm;
	int	x;
	int y;

	if (ac == 2)
	{
		printf("\t~|The start of the program|~\n");
		crd = read_map(av[1], &map);
		printf("|Done reading the map|\n");
		dm = take_dmnt(map);
		printf("|Done taking demantions|\n");
		y = -1;
		while (++y < dm.ht)
		{
			x = -1;
			while (++x < dm.wt)
			{
				printf("[%d/%ld] ", crd[y][x].z, crd[y][x].cl);
			}
			free(crd[y]);
			printf("\n\n");
		}
		// mlx = mlx_init();
		// win = mlx_new_window(mlx, 750, 500, av[1]);
		// mlx_loop(mlx);
	}
}
