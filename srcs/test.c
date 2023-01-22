/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:56:30 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/22 21:03:27 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test_window");
	image.img = mlx_new_image(mlx_ptr, 500, 500);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	for (int i = 0; i < 500; i++)
	{
		for(int j = 0; j < 500; j++)
		{
			if(i == j || i + j == 500)
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
		}
	}
	mlx_loop(mlx_ptr);
	return (0);
}
