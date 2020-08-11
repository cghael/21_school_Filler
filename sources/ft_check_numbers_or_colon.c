//
// Created by Anton on 11.08.2020.
//
#include "filler.h"

int		ft_check_numbers_or_colon(const char *str, int c_flag)
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
