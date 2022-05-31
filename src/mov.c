/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:20:40 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:46:19 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'P')
			break ;
	}
	if (game->str_line[i - 1] == 'E' && ft_count(game) == 0)
		clear_game();
	if (game->str_line[i - 1] != '1' && game->str_line[i - 1] != 'E')
	{
		game->str_line[i] = '0';
		game->str_line[i - 1] = 'P';
		game->map = ft_split(game->str_line, '\n');
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		put_img(game);
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'P')
			break ;
	}
	if (game->str_line[i + 1] == 'E' && ft_count(game) == 0)
		clear_game();
	if (game->str_line[i + 1] != '1' && game->str_line[i + 1] != 'E')
	{
		game->str_line[i] = '0';
		game->str_line[i + 1] = 'P';
		game->map = ft_split(game->str_line, '\n');
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		put_img(game);
	}
}

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'P')
			break ;
	}
	if (game->str_line[i - ((game->wid) + 1)] == 'E' && ft_count(game) == 0)
		clear_game();
	if (game->str_line[i - ((game->wid) + 1)] != '1' && game->str_line[i \
		- ((game->wid) + 1)] != 'E')
	{
		game->str_line[i] = '0';
		game->str_line[i - ((game->wid) + 1)] = 'P';
		game->map = ft_split(game->str_line, '\n');
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		put_img(game);
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'P')
			break ;
	}
	if (game->str_line[i + ((game->wid) + 1)] == 'E' && ft_count(game) == 0)
		clear_game();
	if (game->str_line[i + ((game->wid) + 1)] != '1' && game->str_line[i \
		+ ((game->wid) + 1)] != 'E')
	{
		game->str_line[i] = '0';
		game->str_line[i + ((game->wid) + 1)] = 'P';
		game->map = ft_split(game->str_line, '\n');
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		put_img(game);
	}
}
