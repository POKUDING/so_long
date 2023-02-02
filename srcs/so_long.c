/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:05:59 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/02 14:52:20 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;
	t_img	img;

	if (argc != 2 || check_extention(argv[1]))
		error_control("map file Error\n");
	data_preset(&data, argv[1]);
	info_preset(&info, data);
	img_preset(&img, &info);
	graphic_map(data, info, img);
	data.img = &img;
	data.info = &info;
	mlx_key_hook(info.win_ptr, key_event, &data);
	mlx_loop_hook(info.mlx_ptr, img_anime, &data);
	mlx_loop(info.mlx_ptr);
	return (0);
}
