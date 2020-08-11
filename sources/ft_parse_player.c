/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:00:08 by cghael            #+#    #+#             */
/*   Updated: 2020/08/05 13:00:11 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			ft_valid_player(t_filler *filler, char **str)
{
	if (!ft_strequ(str[0], "$$$") \
		|| !ft_strequ(str[1], "exec") \
		|| !ft_strequ(str[4], "[cghael.filler]"))
	{
		ft_free_two_dem_str(str);
		return (-1);
	}
	if (ft_strequ(str[2], "p1"))
		filler->player = 'O';
	else if (ft_strequ(str[2], "p2"))
		filler->player = 'X';
	else
	{
		ft_free_two_dem_str(str);
		return (-1);
	}
	filler->enemy = (filler->player == 'O') ? 'X' : 'O';
	return (0);
}

static t_filler		*ft_create_filler(int fd)
{
	t_filler *tmp;

	tmp = ft_memalloc(sizeof(t_filler));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	return (tmp);
}

t_filler			*ft_parse_player(int fd)
{
	t_filler	*filler;
	char		*line;
	char		**str;

	if (!(filler = ft_create_filler(fd)))
		return (NULL);
	if (ft_get_next_line(filler->fd, &line) != 1 \
		|| ft_word_count(line, ' ') != 5 \
		|| !(str = ft_strsplit(line, ' ')) \
		|| ft_valid_player(filler, str) < 0)
	{
		ft_strdel(&line);
		return (NULL);
	}
	ft_strdel(&line);
	ft_free_two_dem_str(str);
	return (filler);
}
