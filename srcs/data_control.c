/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:22 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/23 23:09:27 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	info_preset(t_info *info, t_data data)
{
	int	i;

	(void)data;
	i = 0;
	while(data.map[i])
		++i;
	info->map_hegiht = i * 32;
	info->map_width = ft_strlen(data.map[0]) * 32;
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			500, 500, "junhyupa");
	img_preset(info);
}

void	img_preset(t_info *info)
{
	info->img_coin->img = mlx_xpm_file_to_image(info->mlx_ptr,"../so_longxpm/coin.xpm",
			info->img_coin->width,info->img_coin->height);
	info->img_ground->img = mlx_xpm_file_to_image(info->mlx_ptr,"../so_longxpm/ground.xpm",
			info->img_ground->width,info->img_ground->height);
	info->img_wall->img = mlx_xpm_file_to_image(info->mlx_ptr,"../so_longxpm/wall.xpm",
			info->img_wall->width,info->img_wall->height);
}


void	find_components(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (data->map[y])
	{
		x = 1;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[y][x] == 'C')
				data->coins++;
			x++;
		}
		y++;
	}
}

void	data_preset(t_data *data, char *argv)
{
	data->map = build_map(argv);
	data->coins = 0;
	find_components(data);
	data->move = 0;
}

int	key_event(int key, t_data *data)
{
	if (key == 1)
		data->player_x++;
	if (key == 2)
		data->player_x--;
	if (key == 3)
		data->player_y++;
	if (key == 4)
		data->player_y--;
	return (0);
}
