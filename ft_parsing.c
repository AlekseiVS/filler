/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:16:33 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/05 13:27:12 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_alignment_figure(t_main main, int x, int y)
{
	main.i = main.height1 - 1;
	while (main.figure[main.i] && main.i > -1)
	{
		main.j = main.width1 - 1;
		while (main.figure[main.i][main.j] && main.j > -1)
		{
			if (main.figure[main.i][main.j] == '*')
			{
				if ((x + main.i) < main.height && (y + main.j) < main.width)
				{
					if (main.map[x + main.i][y + main.j] == main.simbol1)
						main.count++;
					else if (main.map[x + main.i][y + main.j] == main.simbol2)
						return (0);
				}
				else
					return (0);
			}
			main.j--;
		}
		main.i--;
	}
	return (main.count == 1 ? 1 : 0);
}

static	void	ft_sum(t_main *main, int i, int j)
{
	int x;
	int y;

	x = 0;
	while (main->figure[x])
	{
		y = 0;
		while (main->figure[x][y])
		{
			if (main->figure[x][y] == '*')
			{
				main->sum1 = (main->map[i + x][j + y]);
				if (main->sum1 <= main->sum2)
				{
					main->sum2 = main->sum1;
					main->tmpx = i;
					main->tmpy = j;
				}
			}
			y++;
		}
		x++;
	}
}

void			ft_pars(t_main main)
{
	int i;
	int j;

	i = main.height - 1;
	ft_filling_in_value_min_coord(main);
	while (main.map[i] && i > -1)
	{
		j = main.width - 1;
		while (main.map[i][j] && j > -1)
		{
			if (ft_alignment_figure(main, i, j) == 1)
				ft_sum(&main, i, j);
			j--;
		}
		i--;
	}
	ft_putnbr(main.tmpx);
	write(1, " ", 1);
	ft_putnbr(main.tmpy);
	write(1, "\n", 1);
}
