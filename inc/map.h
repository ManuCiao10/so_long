/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:52:26 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:46:47 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h> /* printf */
# include <stdlib.h>
# include <string.h> /* strrchr */

# define X_EVENT_KEY_PRESS 2

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img
{
	void	*chara;
	void	*chest;
	void	*land;
	void	*rune;
	void	*wall;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	int		walk_cnt;
	char	*str_line;
	char	**map;
	int		all_col;
	int		col_cnt;
}			t_game;

int			main(int argc, char **argv);
void		ft_check_input(int argc, char **argv);
void		ft_check_filetype(char **argv);
void		ft_check_map(t_game *game);
int			get_numlines(int *file);
int			get_numcols(int *file);
void		ft_make_map(char *filename, t_game *game);
void		ft_check_walls(t_game *game, int hight);
void		ft_check_rectangular(t_game *game);
int			ft_check_lastline(t_game *game);
void		ft_check_border(t_game *game);
void		ft_check_character(t_game *game);
void		ft_check_number(t_game *game, unsigned char letter);
int			ft_countchar(char *s, char c);
t_img		img_init(void *mlx);
int			ft_strcmp(char *s1, char *s2);
void		game_init(t_game *game, char *filename);
void		ft_check_img(const char *img);
void		put_img(t_game *game);
int			press_key(int key_code, t_game *game);
void		move_a(t_game *game);
void		move_d(t_game *game);
void		move_s(t_game *game);
void		move_w(t_game *game);
void		clear_game(void);
void		check_images(void);
void		print_err(char *message);
void		control_img(t_game *game, char *tmp, int i, int j);
int			ft_count(t_game *game);

#endif