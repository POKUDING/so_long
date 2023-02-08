/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:33:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 11:23:24 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coin_anime(t_data *data, int i)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->info->map_hegiht)
	{
		x = 0;
		while (x < data->info->map_width)
		{
			if (data->map[y][x] == 'C')
			{
				my_put_img(*data->info, data->img->img_ground, x * 32, y * 32);
				my_put_img(*data->info, data->img->img_coin[i], x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

int	img_anime(t_data *data)
{
	static int	i;

	if (data->status == 0 || data->status == 1)
		game_over(*data);
	else
	{
		coin_anime(data, (i / 20) % 4);
		my_put_img(*data->info, data->img->img_ground,
			data->player_x * 32, data->player_y * 32);
		if (data->status == 2)
			my_put_img(*data->info, data->img->img_front[(i / 25 % 2)],
				data->player_x * 32 + 7, data->player_y * 32 + 4);
		if (data->status == 8)
			my_put_img(*data->info, data->img->img_back[(i / 25 % 2)],
				data->player_x * 32 + 7, data->player_y * 32 + 4);
		if (data->status == 4)
			my_put_img(*data->info, data->img->img_left[(i / 25 % 3)],
				data->player_x * 32 + 7, data->player_y * 32 + 4);
		if (data->status == 6)
			my_put_img(*data->info, data->img->img_right[(i / 25 % 3)],
				data->player_x * 32 + 7, data->player_y * 32 + 4);
		if (++i > 200)
			i = 0;
	}
	return (0);
}

void	my_put_img(t_info info, void *img, int x, int y)
{
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, img, x, y);
}

void	graphic_map(t_data data, t_info info, t_img img)
{
	int		x;
	int		y;

	y = 0;
	while (y < info.map_hegiht)
	{
		x = 0;
		while (x < info.map_width)
		{
			if (data.map[y][x] == '1')
				my_put_img(info, img.img_wall, x * 32, y * 32);
			else
				my_put_img(info, img.img_ground, x * 32, y * 32);
			if (data.map[y][x] == 'C')
				my_put_img(info, img.img_coin[0], x * 32, y * 32);
			else if (data.map[y][x] == 'P')
				my_put_img(info, img.img_front[0], x * 32 + 7, y * 32 + 4);
			else if (data.map[y][x] == 'E')
				my_put_img(info, img.img_closed, x * 32, y * 32);
			else if (data.map[y][x] == 'O')
				my_put_img(info, img.img_open, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
