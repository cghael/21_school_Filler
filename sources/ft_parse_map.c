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

//void		ft_print_map(t_plat map) //todo del
//{
//	int i;
//	int j;
//
//	j = 0;
//	while (j < map.h)
//	{
//		i = 0;
//		while (i < map.w)
//		{
//			ft_printf("%d", map.coord[j][i].num);
//			i++;
//		}
//		j++;
//		ft_printf("\n");
//	}
//}

static int	ft_get_plateau_line(t_filler *filler, char *line, int j)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_toupper(line[i]) == filler->player)
			filler->map.coord[j][i].name = filler->player;
		else if (ft_toupper(line[i]) == filler->enemy)
			filler->map.coord[j][i].name = filler->enemy;
		else if (line[i] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int			ft_parse_map(t_filler *filler)
{
	char	*line;
	int		i;

	if (ft_get_next_line(filler->fd, &line) != 1 \
		|| (int)ft_strlen(line) != filler->map.w + 4)
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	i = 0;
	while (i < filler->map.h)
	{
		if (ft_get_next_line(filler->fd, &line) != 1 \
			|| (int)ft_strlen(line) != filler->map.w + 4 \
			|| ft_get_plateau_line(filler, &line[4], i) < 0)
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
		i++;
	}
//	ft_print_map(filler->map); //todo del
	return (0);
}
