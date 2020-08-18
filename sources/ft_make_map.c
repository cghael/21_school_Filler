/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghael <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:05:35 by cghael            #+#    #+#             */
/*   Updated: 2020/08/17 14:05:37 by cghael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_change_num(t_filler *filler, int j, int i, int step)
{
	filler->map.coord[j][i].num = step;
	return (1);
}

static int	ft_put_step(t_filler *filler, int j, int i, int step)
{
	int flag;

	flag = 0;
	if (i - 1 >= 0 && filler->map.coord[j][i - 1].name != filler->enemy \
		&& filler->map.coord[j][i - 1].num == 0)
		flag = ft_change_num(filler, j, i - 1, step);
	if (i + 1 < filler->map.w \
		&& filler->map.coord[j][i + 1].name != filler->enemy \
		&& filler->map.coord[j][i + 1].num == 0)
		flag = ft_change_num(filler, j, i + 1, step);
	if (j - 1 >= 0 && filler->map.coord[j - 1][i].name != filler->enemy \
		&& filler->map.coord[j - 1][i].num == 0)
		flag = ft_change_num(filler, j - 1, i, step);
	if (j + 1 < filler->map.h \
		&& filler->map.coord[j + 1][i].name != filler->enemy \
		&& filler->map.coord[j + 1][i].num == 0)
		flag = ft_change_num(filler, j + 1, i, step);
	return (flag);
}

static int	ft_put_numb_on_map(t_filler *filler, int j, int i, int step)
{
	int flag;

	flag = 0;
	if ((step == 1 && filler->map.coord[j][i].name == filler->enemy) \
		|| (step > 1 && filler->map.coord[j][i].num == step - 1))
		flag = ft_put_step(filler, j, i, step);
	return (flag);
}

void		ft_make_map(t_filler *filler)
{
	int flag;
	int i;
	int j;
	int step;

	flag = 1;
	step = 1;
	while (flag)
	{
		flag = 0;
		j = 0;
		while (j < filler->map.h)
		{
			i = 0;
			while (i < filler->map.w)
			{
				if (ft_put_numb_on_map(filler, j, i, step) && flag == 0)
					flag = 1;
				i++;
			}
			j++;
		}
		step++;
	}
}
