/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:24:36 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/05 17:22:35 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	make_patrol(t_data data)
{
	int		patrol;
	char	**map;
	int		x;

	patrol = 0;
	x = 0;
	map = data.map;
	while (patrol < data.ground / 10 && *++map)
	{
		while (*map[++x] && *map[x + 1])
		{
			if (*map[x] == '0' && *map[x - 1] == '0' && *map[x + 1] == '0')
			{
				map[x] = 'S';
				*++map;
				break ;
			}
		}
	}
}

void	check_gameover(t_data data, int x, int y, int n)
{
	if (((n == -2 || n == -1) && \
		x - 1 == data.player_x && y == data.player_y) || \
		((n == -1 || n == 0 || n == 1) && \
		x == data.player_x && y == data.player_y) || \
		((n == 1 || n == 2) && \
		x + 1 == data.player_x && y == data.player_y))
		game_over(data, 1);
}

void	move_patrol(t_data data, int n)
{
	int	x;
	int	y;

	y = 0;
	while (data.map[++y])
	{
		x = 0;
		while (data.map[y][++x])
		{
			if (data.map[y][x] == 'S')
			{
				check_gameover(data, x, y, n);
				my_put_img(*data.info, data.img->img_ground, x * 32, y * 32);
				my_put_img(*data.info, data.img->img_ground,
					(x - 1) * 32, y * 32);
				my_put_img(*data.info, data.img->img_ground,
					(x + 1) * 32, y * 32);
				my_put_img(*data.info, data.img->saw, x + (n * 16), y * 32);
			}
		}
	}
}

void	patrol_position(t_data data, int n)
{
	static int	position;
	static int	way_left;

	move_patrol(data, position);
	if (n % 10)
	{
		if (way_left)
			--position;
		else
			++position;
		if (position == 2)
			way_left = 1;
		if (position == -2)
			way_left = 0;
	}
}

void	graphic_move_cnt(t_data data, t_img img)
{
	char	*cnt;
	int		i;

	cnt = ft_itoa(data.move);
	i = 0;
	while (cnt[i])
	{
		my_put_img(*data.info, img.num[*cnt - '0'], 6 + (i * 26), 6);
		i++;
	}
	free(cnt);
}
