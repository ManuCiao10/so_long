/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:04:19 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 17:55:59 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	ft_check_rectangular(t_game *game)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i] != NULL)
	{
		if (len != ft_strlen(game->map[i]))
		{
			print_err("Map must be a rectangular\n");
		}
		i++;
	}
}

void	ft_check_walls(t_game *game, int hight)
{
	unsigned int	i;

	i = 0;
	while (game->map[hight][i] == '1' && game->map[hight][i] != '\0')
	{
		i++;
	}
	if (ft_strlen(game->map[0]) != i)
	{
		print_err("Map must be surrounded by walls!\n");
	}
}

void	ft_check_border(t_game *game)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
		{
			print_err("Map must be surrounded by 1!\n");
		}
		i++;
	}
}

int	ft_check_lastline(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		i++;
	}
	return (i - 1);
}

void	print_err(char *message)
{
	write(2, message, ft_strlen(message));
	exit(0);
}
