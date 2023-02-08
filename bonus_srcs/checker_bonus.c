/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:27:22 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 12:37:47 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_extention(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	return (ft_strncmp(&s[len - 4], ".ber", 4));
}

int	check_components(char *map)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	while (*map)
	{
		if (*map == 'C')
			c++;
		if (*map == 'P')
			p++;
		if (*map == 'E')
			e++;
		if (*map != '1' && *map != '0' && *map != '\n'\
			&& *map != 'C' && *map != 'P' && *map != 'E')
			break ;
		map++;
	}
	if (*map || c == 0 || p != 1 || e != 1)
		error_control("invalid map Error\n");
	return (0);
}

int	check_wall(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] && map[y][x] == '1')
		x++;
	x--;
	while (map[y] && map[y][x] == '1')
		y++;
	y--;
	if (x < 0 || y < 0 || map[y][x + 1] || map[y + 1])
		return (1);
	while (x >= 0 && map[y][x] && map[y][x] == '1')
		x--;
	x++;
	while (y >= 0 && map[y] && map[y][x] == '1')
		y--;
	y++;
	if (x > 0 || y > 0)
		return (1);
	return (0);
}

int	check_square(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i] && ft_strlen(map[i]) == len)
		i++;
	if (map[i])
		return (1);
	return (0);
}
