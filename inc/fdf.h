/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:39:01 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/15 22:16:45 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libtool/inc/libft.h"
# include <mlx.h> // MAC
// # include "../mlx/mlx.h" // LINUX

# define W_HT 1500
# define W_WT 1000

/*the map demantions*/
typedef struct f_dmt
{
	int	ht;
	int	wt;
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
	int	x;
	int	y;
	int	z;
	int	cl;
}	t_inf;
/****************************/
/*DATA needed holder*/
typedef struct f_fdf
{
	void	*mlx;
	void	*win;
	t_inf	**crd;
	t_dmt	dm;
	int		du;
	double	zs;
	double	i;
	double	j;
}	t_fdf;
/****************************/
/*Cordination of a point for drawing*/
typedef struct f_pst
{
	double	x;
	double	y;
	int		cl;
}	t_pst;
/****************************/
typedef struct f_draw
{
	t_pst	x;
	t_pst	y;
}	t_draw;
/*TOOLS DIR*/
int		chck_opn(char *fl);
int		chck_map(char **map);
int		error(int er);
int		hex_to_dec(char *s);
int		mtx_len(char **mx);
t_dmt	take_dmnt(char *map);
int		init_drawing_unit(t_dmt dm);
t_pst	init_point(t_inf cr);
t_pst	start_point(t_inf cr);
t_pst	next_x(t_fdf f, t_pst st);
t_pst	next_y(t_fdf f, t_pst st);
double	take_z_scale(t_fdf f);
double	take_j(t_fdf f);
double	take_i(t_fdf f);
t_pst	next_x_crd(t_fdf f, t_pst st, t_inf s, t_inf e);
t_pst	next_y_crd(t_fdf f, t_pst st, t_inf s, t_inf e);
/****************************/
/*SRC DIR*/
int		map_len(int fd);
int		map_wt(int fd);
t_inf	**read_map(char *mp, t_fdf f);
void	draw_line(t_fdf f, t_pst st, t_pst en);
void	draw_map(t_fdf f);
/****************************/

#endif
