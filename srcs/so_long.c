/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:05:59 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/23 22:34:16 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;

	if (argc != 2 || check_extention(argv[1]))
		error_control("map file Error\n");
	data_preset(&data, argv[1]);
	info_preset(&info, data);
	return (0);
}
