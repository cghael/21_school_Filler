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

static int	ft_find_players(t_filler *filler, char *line)
{

}

int			ft_parse_map(t_filler *filler)
{
	char	*line;
	int		res;

	if ((res = ft_get_next_line(filler->fd, &line)) > 0)
	{
		if (ft_find_players(filler, line) < 0)
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
	return (0);
}
