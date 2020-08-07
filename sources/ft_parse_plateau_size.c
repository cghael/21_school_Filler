/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_plateau_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:51:16 by cghael            #+#    #+#             */
/*   Updated: 2020/08/07 11:51:18 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_check_numbers_or_colon(const char *str, int c_flag)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if ((c_flag && str[i] == 58) \
			|| (str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (0);
	}
	if (c_flag && str[i - 1] != ':')
		return (0);
	return (1);
}

static int		ft_valid_plateua_size(t_filler *filler, char *line)
{
	char **str;

	if (3 != ft_word_count(line, ' '))
		return (-1);
	str = ft_strsplit(line, ' ');
	if (!str)
		return (-1);
	if (!ft_strequ(str[0], "Plateau") || \
		!ft_check_numbers_or_colon(str[1], 0) || \
		!ft_check_numbers_or_colon(str[2], 1))
	{
		ft_free_two_dem_str(str);
		return (-1);
	}
	filler->map.h = ft_atoi(str[1]);
	filler->map.w = ft_atoi(str[2]);
	ft_free_two_dem_str(str);
	return (0);
}

int				ft_parse_plateau_size(t_filler *filler)
{
	char	*line;
	int		res;

	if ((res = ft_get_next_line(filler->fd, &line)) > 0)
	{
		if (ft_valid_plateua_size(filler, line) < 0)
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
