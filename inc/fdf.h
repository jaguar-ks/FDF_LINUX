/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:39:01 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/11 13:26:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libtool/libft.h"
# include <mlx.h> // MAC
// # include "../mlx/mlx.h" // LINUX

/*the map demantions*/
typedef struct f_dmt
{
	int	ht;
	int wt;
}	t_dmt;
/*****************************/
/*read the data from the file*/
typedef struct f_rd
{
	char	**y;
	char	**x;
	char	**z;
}	t_rd;
/*****************************/
/*the information needed to drow the map*/
typedef struct f_inf
{
	int			x;
	int			y;
	int			z;
	int	cl;
}	t_inf;
/****************************/
/*position*/
typedef struct f_pst
{
	int	i;
	int	j;
	int	z;
}	t_pst;
/****************************/
/*TOOLS DIR*/
int		chck_opn(char *fl);
int		chck_map(char **map);
int		error(int er);
int		hex_to_dec(char *s);
int		mtx_len(char **mx);
t_dmt	take_dmnt(char *map);
/****************************/
/*SRC DIR*/
t_inf		**read_map(char *mp, char **map);
/****************************/

#endif
