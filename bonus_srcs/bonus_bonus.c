/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JUN <JUN@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:24:36 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/11 02:12:18 by JUN              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	make_patrol(t_data *data)
{
	int		patrol;
	int		y;
	int		x;

	patrol = 0;
	data->img->saw = mlx_xpm_file_to_image(data->info->mlx_ptr, "./so_longxpm/saw.xpm", &data->img->width, &data->img->height);
	y = 0;
	while (patrol < data->ground / 10 && data->map[++y])
	{
		x = 0;
		while (data->map[y][(++x) + 1])
		{
			if (data->map[y][x] == '0' && data->map[y][x - 1] == '0' && data->map[y][x + 1] == '0' \
				&& data->map[y + 1][x] == '0' && data->map[y - 1][x] == '0')
			{
				data->map[y][x] = 'S';
				++y;
				break ;
			}
		}
	}
}

void	move_patrol(t_data *data, int n)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'S')
			{
				check_gameover(data, x, y, n);
				my_put_img(*data->info, data->img->img_ground, x * 32, y * 32);
				my_put_img(*data->info, data->img->img_ground,
					(x - 1) * 32, y * 32);
				my_put_img(*data->info, data->img->img_ground,
					(x + 1) * 32, y * 32);
				my_put_img(*data->info, data->img->saw, (x * 32) + (n * 16), y * 32);
			}
		}
	}
}

int	bonus_game(t_data *data)
{
	static int	position;
	static int	way_left;
	static int	i;

	img_anime(data);
	if (!(++i % 50) && data->status != 0 && data->status != 1)
	{
		move_patrol(data, position);
		if (way_left)
			--position;
		else
			++position;
		if (position == 2)
			way_left = 1;
		if (position == -2)
			way_left = 0;
		if (i > 200)
			i = 0;
	}
	return (0);
}

void	graphic_move_cnt(t_data data, t_img img)
{
	char	*cnt;
	int		i;

	cnt = ft_itoa(data.move);
	i = 0;
	my_put_img(*data.info, img.img_wall, 0, 0);
	my_put_img(*data.info, img.img_wall, 32, 0);
	while (cnt[i])
	{
		my_put_img(*data.info, img.num[cnt[i] - '0'], 6 + (i * 16), 6);
		i++;
	}
	free(cnt);
}

void	check_gameover(t_data *data, int x, int y, int n)
{
	if (((n == -2 || n == -1) && \
		x - 1 == data->player_x && y == data->player_y) || \
		((n == -1 || n == 0 || n == 1) && \
		x == data->player_x && y == data->player_y) || \
		((n == 1 || n == 2) && \
		x + 1 == data->player_x && y == data->player_y))
		data->status = 1;
}
