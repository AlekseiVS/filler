/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <osokoliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:16:21 by osokoliu          #+#    #+#             */
/*   Updated: 2018/05/05 13:27:08 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inicialization(t_main *main)
{
	main->fd = 0;
	main->line = 0;
	main->map = 0;
	main->figure = 0;
	main->sum1 = 0;
	main->sum2 = 2147483647;
	main->tmpx = 0;
	main->tmpy = 0;
	main->width = 0;
	main->height = 0;
	main->width1 = 0;
	main->height1 = 0;
	main->simbol1 = 0;
	main->simbol2 = 0;
	main->minx = 0;
	main->miny = 0;
	main->min = 2147483647;
	main->count = 0;
	main->i = 0;
	main->j = 0;
}

void	ft_read_m(char ***map, char *line, int *width, int *height)
{
	int i;
	int j;

	*height = ft_atoi(line + 8);
	*width = ft_atoi(line + 11);
	i = *height;
	j = 0;
	get_next_line(0, &line);
	*map = (char**)malloc(sizeof(char*) * (i + 1));
	(*map)[i] = 0;
	while (i--)
	{
		get_next_line(0, &line);
		(*map)[j++] = ft_strdup(line + 4);
	}
}

void	ft_read_f(char ***figure, char *line, int *width1, int *height1)
{
	int i;
	int j;

	get_next_line(0, &line);
	*height1 = ft_atoi(line + 6);
	*width1 = ft_atoi(line + 8);
	i = *height1;
	j = 0;
	*figure = (char**)malloc(sizeof(char*) * (i + 1));
	(*figure)[i] = 0;
	while (i--)
	{
		get_next_line(0, &line);
		(*figure)[j++] = ft_strdup(line);
	}
}

int		main(void)
{
	t_main	main;

	ft_inicialization(&main);
	get_next_line(main.fd, &(main.line));
	main.simbol1 = ft_atoi(main.line + 10) == 1 ? 'O' : 'X';
	main.simbol2 = main.simbol1 == 'O' ? 'X' : 'O';
	while (get_next_line(main.fd, &(main.line)))
	{
		ft_read_m(&(main.map), main.line, &(main.width), &(main.height));
		ft_read_f(&(main.figure), main.line, &(main.width1), &(main.height1));
		ft_pars(main);
	}
	return (0);
}
