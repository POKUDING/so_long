/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:20:00 by junhyupa          #+#    #+#             */
/*   Updated: 2023/02/08 15:07:43 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_ground;
	void	*img_wall;
	void	*img_coin[4];
	void	*img_front[2];
	void	*img_back[2];
	void	*img_right[3];
	void	*img_left[3];
	void	*img_closed;
	void	*img_open;
	void	*num[10];
	void	*game_clear[3];
	void	*game_over;
	void	*saw;
	int		width;
	int		height;
}	t_img;

typedef struct s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_width;
	int		map_hegiht;
}	t_info;

typedef struct s_data
{
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		ground;
	int		coins;
	int		move;
	int		status;
	t_img	*img;
	t_info	*info;
}	t_data;

int		close_game(t_data *data);
int		key_event(int key, t_data *data);
void	game_over(t_data data);

void	make_patrol(t_data *data);
void	check_gameover(t_data *data, int x, int y, int n);
void	move_patrol(t_data *data, int n);
int		bonus_game(t_data *data);
void	graphic_move_cnt(t_data data, t_img img);

void	img_preset(t_img *img, t_info *info);
void	player_img_preset(t_img *img, t_info *info);
void	coin_img_preset(t_img *img, t_info *info);
void	end_img_preset(t_img *img, t_info *info);

void	coin_anime(t_data *data, int i);
int		img_anime(t_data *data);
void	my_put_img(t_info info, void *img, int x, int y);
void	graphic_map(t_data data, t_info info, t_img img);

void	get_coin(t_data *data, t_img img, int x, int y);
void	move_up(t_data *data, t_info info, t_img img);
void	move_down(t_data *data, t_info info, t_img img);
void	move_right(t_data *data, t_info info, t_img img);
void	move_left(t_data *data, t_info info, t_img img);

int		check_components(char *map);
int		check_extention(char *s);
int		check_wall(char **map);
int		check_square(char **map);

void	info_preset(t_info *info, t_data data);
void	find_components(t_data *data);
void	data_preset(t_data *data, char *argv);

char	**copy_map(char **map);
int		infection(char	**map, int x, int y);
void	plague(char **map);
int		path_finder(char **map);

char	*map_reader(char *ber);
char	**build_map(char *ber);

void	print_move(t_data *data);
void	error_control(char *err_msg);
void	free_box(char **box);

#endif
