/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:10:03 by faksouss          #+#    #+#             */
/*   Updated: 2023/01/17 05:01:23 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/libft.h"

char	*take_line(char *r)
{
	char	*ln;
	int		i;

	if (!r || !ft_strlen(r))
		return (NULL);
	i = -1;
	while (r[++i])
		if (r[i] == '\n')
			break ;
	ln = ft_substr(r, 0, i + 1);
	return (ln);
}

char	*take_rest(char *r)
{
	char	*rst;
	int		i;

	if (!r)
		return (NULL);
	i = -1;
	while (r[++i])
		if (r[i] == '\n')
			break ;
	i++;
	rst = ft_substr(r, i, ft_strlen(r) - i);
	return (free(r), rst);
}

char	*gnl(int fd)
{
	int			i;
	static char	*r;
	char		*bf;
	char		*ln;

	i = 1;
	while (i && !ft_strchr(r, '\n'))
	{
		bf = (char *)malloc(2);
		i = read(fd, bf, 1);
		if (i < 0)
			return (free(bf), NULL);
		bf[i] = '\0';
		if (!ft_strlen(bf))
		{
			free(bf);
			break ;
		}
		r = ft_strjoin(r, bf);
	}
	return ((ln = take_line(r)), (r = take_rest(r)), ln);
}
