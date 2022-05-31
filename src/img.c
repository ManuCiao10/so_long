/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:47 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:19:09 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	ft_check_img(const char *img)
{
	int	file;

	file = open(img, O_RDONLY);
	if (file < 0)
	{
		print_err("File xpm not found!\n");
	}
	if (file == 0)
	{
		print_err("Could not open file\n");
	}
}

t_img	img_init(void *mlx)
{
	int		wid;
	int		hei;
	t_img	img;

	img.chara = mlx_xpm_file_to_image(mlx, "./img/chara.xpm", &hei, &wid);
	img.land = mlx_xpm_file_to_image(mlx, "./img/land.xpm", &hei, &wid);
	img.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &hei, &wid);
	img.chest = mlx_xpm_file_to_image(mlx, "./img/chest.xpm", &hei, &wid);
	img.rune = mlx_xpm_file_to_image(mlx, "./img/rune.xpm", &hei, &wid);
	return (img);
}

void	put_img(t_game *game)
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
			control_img(game, tmp, i, j);
			i++;
		}
		j++;
		tmp = game->map[j];
	}
}

void	control_img(t_game *game, char *tmp, int i, int j)
{
	if (tmp[i] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, i * 64, j
			* 64);
	else if (tmp[i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.chest, i * 64, j
			* 64);
	else if (tmp[i] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.chara, i * 64, j
			* 64);
	else if (tmp[i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.rune, i * 64, j
			* 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img.land, i * 64, j
			* 64);
}
