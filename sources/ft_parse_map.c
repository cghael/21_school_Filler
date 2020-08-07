/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:44:42 by cghael            #+#    #+#             */
/*   Updated: 2020/08/07 16:44:44 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_n_write_players(t_filler *filler, char *line, int j)
{
	size_t	i;

	i = 0;
	while(*line)
	{
		if (*line != '.')
		{
			if (*line != 'X' && *line != 'O' && *line != 'x' && *line != 'o')
				return (-1);
			filler->map.coord[j][i].name = *line;
		}
		line++;
	}
	return (0);
}

static int	ft_find_players(t_filler *filler, char *line, int j)
{
	char *tmp;

	if (ft_word_count(line, ' ') != 2)
		return (-1);
	if (!(tmp = ft_strchr(line, ' ')))
		return (-1);
	tmp++;
	if (ft_strlen(tmp) != filler->map.w)
		return (-1);
	if (ft_check_n_write_players(filler, tmp, j) < 0)
		return (-1);
	return (0);
}

int			ft_parse_map(t_filler *filler)
{
	char	*line;
	int		res;
	int		i;

	i = 0;
	while (i < filler->map.h)
	{
		if ((res = ft_get_next_line(filler->fd, &line)) > 0)
		{
			if (i > 0 && ft_find_players(filler, line, i) < 0)
			{
				free(line);
				return (-1);
			}
			free(line);
		}
		if (res == 0)
			free(line);
		if (res < 0)
			return (-1);
		i++;
	}
	return (0);
}
