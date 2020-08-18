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

static void		ft_check_for_min(t_filler *filler, int y, int x, int sqr)
{
	if (filler->token.min_sqr == 0 || filler->token.min_sqr > sqr)
	{
		filler->token.min_sqr = sqr;
		filler->token.min_x = x;
		filler->token.min_y = y;
	}
}

static int		ft_can_token_stand(t_filler *filler, int y, int x, t_coord p_token)
{
	int i;
	int j;
	int	sqr;

	sqr = 0;
	j = 0;
	while (j < filler->token.h)
	{
		i = 0;
		while (i < filler->token.w)
		{
			if (i != p_token.x || j != p_token.y)
			{
				if (filler->token.coord[j][i] == '*' &&
					((y + j < 0 || x + i < 0 || \
				y + j >= filler->map.h || x + i >= filler->map.w) \
				|| (filler->map.coord[y + j][x + i].name != FREE) \
				|| (i == p_token.x && j == p_token.y)))
					return (FALSE);
				else if (filler->token.coord[j][i] == '*' && filler->map.coord[y + j][x + i].name == FREE)
					sqr += filler->map.coord[y + j][x + i].num;
			}
//			if (filler->token.coord[j][i] == '*' &&
//				((y + j < 0 || x + i < 0 || \
//				y + j >= filler->map.h || x + i >= filler->map.w) \
//				|| (filler->map.coord[y + j][x + i].name != FREE) \
//				|| (i == p_token.x && j == p_token.y)))
//				return (FALSE);
//			else if (filler->token.coord[j][i] == '*' && filler->map.coord[y + j][x + i].name == FREE)
//				sqr += filler->map.coord[y + j][x + i].num;
			i++;
		}
		j++;
	}
	return (sqr);
}

static void		ft_put_token(t_filler *filler, t_coord p_map)
{
	t_coord	p_token;
	int		sqr;

	p_token.y = 0;
	while (p_token.y < filler->token.h)
	{
		p_token.x = 0;
		while (p_token.x < filler->token.w)
		{
			if (filler->token.coord[p_token.y][p_token.x] == '*')
			{
				sqr = ft_can_token_stand(filler, p_map.y - p_token.y, p_map.x - p_token.x, p_token);
				if (sqr)
					ft_check_for_min(filler, p_map.y - p_token.y, p_map.x - p_token.x, sqr);
			}
			p_token.x++;
		}
		p_token.y++;
	}
}

void			ft_count_coords(t_filler *filler)
{
	t_coord	p_map;

	filler->token.min_sqr = 0;
	p_map.y = 0;
	while (p_map.y < filler->map.h)
	{
		p_map.x = 0;
		while (p_map.x < filler->map.w)
		{
			if (filler->map.coord[p_map.y][p_map.x].name == filler->player)
				ft_put_token(filler, p_map);
			p_map.x++;
		}
		p_map.y++;
	}
}
