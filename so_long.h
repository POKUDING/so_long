/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:54:33 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/23 23:08:47 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
 #define SO_LONG_H

typedef	struct s_data
{
	char	**map;
	int		player_x;
	int		player_y;
	int		coins;
	int		move;
} t_data;

typedef struct s_img
{
	void	*img;
	int		*width;
	int		*height;
}	t_img;

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img_ground;
	t_img	*img_wall;
	t_img	*img_coin;
	int		map_width;
	int		map_hegiht;
}	t_info;


 #include "./libft/libft.h"






#include <stdio.h>







 #include <mlx.h>
 #include <fcntl.h>

void	graphic_preset(t_data data, t_info info);

int		check_components(char *map);
int		check_extention(char *s);
int		check_wall(char **map);
int		check_square(char **map);

void	info_preset(t_info *info, t_data data);
void	img_preset(t_info *info);
void	find_components(t_data *data);
void	data_preset(t_data *data, char *argv);
int		key_event(int key, t_data *data);

char	**copy_map(char **map);
int		infection(char	**map, int x, int y);
void	plague(char **map);
int		path_finder(char **map);

char	*map_reader(char *ber);
char	**build_map(char *ber);

void	error_control(char *err_msg);
void	free_box(char **box);

#endif
