/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:05:59 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/30 19:14:22 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;
	t_img	img;

	if (argc != 2 || check_extention(argv[1]))
		error_control("map file Error\n");
	data_preset(&data, argv[1]);
	info_preset(&info, data);
	printf("info preset 완료\n");
	img_preset(&img, &info);
	graphic_map(data, info, img);
	data.img = &img;
	data.info = &info;
	mlx_key_hook(info.win_ptr, key_event, &data);
	mlx_loop(info.mlx_ptr);
	return (0);
}
