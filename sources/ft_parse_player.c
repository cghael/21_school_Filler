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

static void			ft_valid_player(t_filler **filler, char *line)
{
	char **str;

	str = ft_strsplit(line, ' ');
	if (!str)
		ft_error_exit("Error in ft_strsplit()\n", NULL);
	if (!ft_strequ(str[0], "$$$") || !ft_strequ(str[1], "exec") \
		|| !ft_strequ(str[4], "[cghael.filler]"))
		ft_error_exit("Error\n", NULL);
	if (ft_strequ(str[2], "p1"))
		(*filler)->player = 'O';
	else if (ft_strequ(str[2], "p2"))
		(*filler)->player = 'X';
	else
		ft_error_exit("Error\n", NULL);
}

static t_filler		*ft_create_filler(void)
{
	t_filler *tmp;

	tmp = ft_memalloc(sizeof(t_filler));
	if (!tmp)
		ft_error_exit("Error malloc ft_create_filler()\n", NULL);
	return (tmp);
}

t_filler			*ft_parse_player(int fd)
{
	t_filler	*filler;
	char		*line;
	int			res;

	filler = ft_create_filler();
	if ((res = ft_get_next_line(fd, &line)) > 0)
	{
		ft_valid_player(&filler, line);
		free(line);
	}
	if (res == 0)
		free(line);
	if (res < 0)
		ft_error_exit("Error gnl in ft_parse_player()\n", NULL);
	return (filler);
}
