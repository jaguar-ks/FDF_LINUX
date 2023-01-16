/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:24:27 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/16 21:56:13 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

int	chck_opn(char *fl)
{
	int	fd;
	int	i;

	i = ft_strlen(fl);
	if (!ft_strncmp((fl + (i - 4)), ".fdf", 5))
		fd = open(fl, O_RDWR);
	else
		fd = -2;
	if (fd < 0)
		exit(error(fd));
	return (fd);
}
