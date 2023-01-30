/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:22 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/30 20:09:35 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	info_preset(t_info *info, t_data data)
{
	int	i;

	i = 0;
	while (data.map[i])
		++i;
	info->map_hegiht = i;
	info->map_width = ft_strlen(data.map[0]);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->map_width * 32, info->map_hegiht * 32, "junhyupa");
}

void	img_preset(t_img *img, t_info *info)
{
	img->img_coin = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/coin16.xpm", &img->width, &img->height);
	img->img_ground = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/sand.xpm", &img->width, &img->height);
	img->img_wall = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/wall.xpm", &img->width, &img->height);
	img->img_closed = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/close32.xpm", &img->width, &img->height);
	img->img_open = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/open32.xpm", &img->width, &img->height);
	img->img_front[0] = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/front_0.xpm", &img->width, &img->height);
	img->img_front[1] = mlx_xpm_file_to_image(info->mlx_ptr,
			"./so_longxpm/front_1.xpm", &img->width, &img->height);
}
	// img->img_back[0] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/back_0.xpm", &img->width, &img->height);
	// img->img_back[1] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/back_1.xpm", &img->width, &img->height);
	// img->img_right[0] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/right_0.xpm", &img->width, &img->height);
	// img->img_right[1] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/right_1.xpm", &img->width, &img->height);
	// img->img_right[2] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/right_2.xpm", &img->width, &img->height);
	// img->img_left[0] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/left_0.xpm", &img->width, &img->height);
	// img->img_left[1] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/left_1.xpm", &img->width, &img->height);
	// img->img_left[2] = mlx_xpm_file_to_image(info->mlx_ptr,
	//"./so_longxpm/left_2.xpm", &img->width, &img->height);

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
			else if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
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
	printf("%d \n", key);
	printf("coin : %d\n", data->coins);
	if (key == 13)
		move_up(data, *data->info, *data->img);
	if (key == 1)
		move_down(data, *data->info, *data->img);
	if (key == 0)
		move_left(data, *data->info, *data->img);
	if (key == 2)
		move_right(data, *data->info, *data->img);
	return (0);
}
