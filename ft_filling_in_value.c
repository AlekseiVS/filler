/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_in_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:16:58 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/05 13:27:24 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_min_coord_enemy(t_main *main, int i, int j)
{
	int ii;
	int jj;

	ii = main->height - 1;
	while (main->map[ii] && ii > 0)
	{
		jj = main->width - 1;
		while (main->map[ii][jj] && jj > 0)
		{
			if (main->map[ii][jj] != main->simbol1)
			{
				jj--;
				continue ;
			}
			if (ft_abs(i - ii) + ft_abs(j - jj) < main->min)
			{
				main->min = ft_abs(i - ii) + ft_abs(j - jj);
				main->minx = i;
				main->miny = j;
			}
			jj--;
		}
		ii--;
	}
}

static	void	ft_filling_in_value(t_main main)
{
	int i;
	int j;

	i = main.height - 1;
	while (main.map[i] && i > -1)
	{
		j = main.width - 1;
		while (main.map[i][j] && j > -1)
		{
			if (main.map[i][j] != main.simbol1 &&
			main.map[i][j] != main.simbol2)
			{
				main.map[i][j] = (ft_abs(i - main.minx) > ft_abs(j - main.miny))
				? ft_abs(i - main.minx) : ft_abs(j - main.miny);
			}
			j--;
		}
		i--;
	}
}

void			ft_filling_in_value_min_coord(t_main main)
{
	int i;
	int j;

	i = main.height - 1;
	while (main.map[i] && i > -1)
	{
		j = main.width - 1;
		while (main.map[i][j] && j > -1)
		{
			if (main.map[i][j] == main.simbol2)
			{
				ft_min_coord_enemy(&main, i, j);
			}
			j--;
		}
		i--;
	}
	ft_filling_in_value(main);
}
