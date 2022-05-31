/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:04:19 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:47:10 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	ft_count(t_game *game)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (game->map[i])
	{
		num += ft_countchar(game->map[i], 'C');
		i++;
	}
	return (num);
}
