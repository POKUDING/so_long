/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:54:33 by junhyupa          #+#    #+#             */
/*   Updated: 2023/01/22 21:01:30 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
 #define SO_LONG_H

// typedef	struct s_data
// {
// 	char	**map;
// 	int		player_x;
// 	int		player_y;
// 	int		coins;
// 	int		move;
// } t_data;


 #include "./libft/libft.h"






#include <stdio.h>







 #include <mlx.h>
 #include <fcntl.h>

int		check_components(char *map);
int		check_extention(char *s);
int		check_wall(char **map);
int		check_square(char **map);

char	**copy_map(char **map);
int		infection(char	**map, int x, int y);
void	plague(char **map);
int		path_finder(char **map);

char	*map_reader(char *ber);
char	**build_map(char *ber);

void	error_control(char *err_msg);
void	free_box(char **box);

#endif
