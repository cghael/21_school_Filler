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

static void		ft_valid_plateua_size(t_filler **filler, char *line)
{
	char **str;

	if (3 != ft_word_count(line, ' '))
		ft_error_exit("Error\n", NULL);
}

void			ft_parse_plateau_size(t_filler **filler)
{
	char	*line;
	int		res;

	if ((res = ft_get_next_line((*filler)->fd, &line)) > 0)
	{
		ft_valid_plateua_size(filler, line);
		free(line);
	}
	if (res == 0)
		free(line);
	if (res < 0)
		ft_error_exit("Error gnl in ft_parse_player()\n", NULL);
}
