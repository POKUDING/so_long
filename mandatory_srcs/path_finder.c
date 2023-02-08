/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:19:48 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/30 19:47:49 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map)
{
	int		i;
	char	**rtn;

	i = 0;
	while (map[i])
		i++;
	rtn = (char **)malloc(sizeof(char *) * (i + 1));
	rtn[i] = NULL;
	i = 0;
	while (*map)
		rtn[i++] = ft_strdup(*map++);
	return (rtn);
}

int	infection(char	**map, int x, int y)
{
	int	rtn;

	rtn = 0;
	map[y][x] = 'X';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
	{
		map[y][x + 1] = 'X';
		rtn = 1;
	}
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
	{
		map[y + 1][x] = 'X';
		rtn = 1;
	}
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
	{
		map[y][x - 1] = 'X';
		rtn = 1;
	}
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
	{
		map[y - 1][x] = 'X';
		rtn = 1;
	}
	return (rtn);
}

void	plague(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' || map[y][x] == 'X')
			{
				if (infection(map, x, y))
					plague(map);
			}
			x++;
		}
		y++;
	}
}

int	exit_check(char	**map, int x, int y)
{
	if (map[y][x + 1] == 'X')
		return (0);
	else if (map[y + 1][x] == 'X')
		return (0);
	else if (map[y][x - 1] == 'X')
		return (0);
	else if (map[y - 1][x] == 'X')
		return (0);
	return (1);
}

int	path_finder(char **map)
{
	char	**tmp;
	int		x;
	int		y;

	tmp = copy_map(map);
	plague(tmp);
	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if ((tmp[y][x] == 'E' && exit_check(tmp, x, y)) || tmp[y][x] == 'C')
				error_control("No path Error\n");
			x++;
		}
		y++;
	}
	free_box(tmp);
	return (0);
}
