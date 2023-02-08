/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:51:09 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 15:09:28 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_data *data)
{
	mlx_destroy_window(data->info->mlx_ptr, data->info->win_ptr);
	exit(0);
}

int	key_event(int key, t_data *data)
{
	if (key == 13)
		move_up(data, *data->info, *data->img);
	if (key == 1)
		move_down(data, *data->info, *data->img);
	if (key == 0)
		move_left(data, *data->info, *data->img);
	if (key == 2)
		move_right(data, *data->info, *data->img);
	if (key == 53)
		close_game(data);
	return (0);
}

void	game_over(t_data data)
{
	static int	i;
	int			x;
	int			y;

	y = -1;
	while (++y < data.info->map_hegiht * 32)
	{
		x = -1;
		while (++x < data.info->map_width * 32)
			mlx_pixel_put(data.info->mlx_ptr, data.info->win_ptr, x, y, 0);
	}
	if (data.status == 1)
		my_put_img(*data.info, data.img->game_over,
			((data.info->map_width * 32) - 90) / 2,
			((data.info->map_hegiht * 32) - 39) / 2);
	else
		my_put_img(*data.info, data.img->game_clear[(i / 3) % 3],
			((data.info->map_width * 32) - 68) / 2,
			((data.info->map_hegiht * 32) - 55) / 2);
	if (++i > 30)
		close_game(&data);
}
