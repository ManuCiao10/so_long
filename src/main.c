/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:34:15 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/13 12:12:00 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac != 2)
		print_err("Map is missing.\n");
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_loop(game->mlx);
	return (0);
}
