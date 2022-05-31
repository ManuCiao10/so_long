/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:05:18 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:37:00 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	ft_check_character(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = game->map[j];
	while (tmp)
	{
		i = 0;
		while (tmp[i])
		{
			if (!ft_strchr("01CEP", tmp[i]))
			{
				print_err("Unexpected char(s) in map!\n");
			}
			i++;
		}
		j++;
		tmp = game->map[j];
	}
}

void	ft_check_number(t_game *game, unsigned char letter)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (game->map[i])
	{
		num = ft_countchar(game->map[i], letter);
		if (num != 0)
		{
			count++;
		}
		i++;
	}
	if (count < 1)
	{
		print_err("Invalid number!\n");
	}
}

int	ft_countchar(char *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}
