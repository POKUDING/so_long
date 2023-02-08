/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:05:59 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 14:41:39 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	make_patrol(&data);
	mlx_hook(data.info->win_ptr, 17, 0, close_game, &data);
	mlx_key_hook(info.win_ptr, key_event, &data);
	mlx_loop_hook(info.mlx_ptr, bonus_game, &data);
	mlx_loop(info.mlx_ptr);
	return (0);
}
