/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:52:13 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/10 20:10:04 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/fdf.h"

long int	hex_to_dec(char *s)
{
	int				i;
	long int		r;

	i = 1;
	r = 0;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (s[i] >= 'A' && s[i] <= 'F')
				s[i] = ft_tolower(s[i]);
			if (s[i] > 'f' || s[i] < 'a')
				exit(error(0));
			r = (r * 16) + (s[i] - 87);
		}
		else
			r = (r * 16) + (s[i] - 48);
	}
	return (r);
}
