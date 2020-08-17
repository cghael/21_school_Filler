/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:41:25 by cghael            #+#    #+#             */
/*   Updated: 2020/08/17 15:41:27 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_can_token_stand(t_filler *filler, int y, int x, t_coord p_token)
{
	int i;
	int j;

	j = 0;
	while (j < filler->token.h)
	{
		i = 0;
		while (i < filler->token.w)
		{
			if (filler->token.coord[j][i] == '*' &&
				((y + j < 0 || x + i < 0 || \
				y + j >= filler->map.h || x + i >= filler->map.w) \
				|| (filler->map.coord[y + j][x + i].name != FREE && \
				i != p_token.x && j != p_token.y)))
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

static t_coord	ft_check_position(t_filler *filler, t_coord p_map, t_coord tmp)
{
	t_coord p_token;

	p_token.y = 0;
	while (p_token.y < filler->token.h)
	{
		p_token.x = 0;
		while (p_token.x < filler->token.w)
		{
			if (filler->token.coord[p_token.y][p_token.x] == '*')
			{
				if (TRUE == ft_can_token_stand(filler, p_map.y - p_token.y, p_map.x - p_token.x, p_token))
					tmp = //todo проверить на минимальную площадь этого токена
			}
			p_token.x++;
		}
		p_token.y++;
	}
}

static t_coord		ft_put_token(t_filler *filler, t_coord p_map, t_coord p_put)
{
	t_coord tmp;

	tmp = ft_check_position(filler, p_map, tmp);
	if (tmp.sqr)
	{
		//todo проверить на мин площадь вообще на этой карте
	}
}

void			ft_count_coords(t_filler *filler)
{
	t_coord	p_map;
	t_coord	p_put;

	p_map.y = 0;
	while (p_map.y < filler->map.h)
	{
		p_map.x = 0;
		while (p_map.x < filler->map.w)
		{
			if (filler->map.coord[p_map.y][p_map.x].name == filler->player)
				p_put = ft_put_token(filler, p_map, p_put);
			p_map.x++;
		}
		p_map.y++;
	}
}
