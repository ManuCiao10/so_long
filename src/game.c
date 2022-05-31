/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:20:40 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:01:04 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

void	game_init(t_game *game, char *filename)
{
	game->mlx = mlx_init();
	check_images();
	game->img = img_init(game->mlx);
	ft_make_map(filename, game);
	ft_check_map(game);
	game->win = mlx_new_window(game->mlx, game->wid * 64, game->hei * 64,
			"So-Long");
	put_img(game);
}

void	clear_game(void)
{
	print_err("Congratulations!\n");
}
