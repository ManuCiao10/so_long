/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:02:14 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 18:50:56 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

/* argc should be 2 for correct execution */

void	ft_check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		print_err("Error\n");
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		print_err("File not found!\n");
	}
	if (fd == 0)
	{
		print_err("Could not open file\n");
	}
}

//--> [ft_strcmp(ext + 1,"ber") == 0] 
//Check if the contents of the two strings are the same.

void	ft_check_filetype(char **argv)
{
	char	*filename;
	char	*ext;

	filename = argv[1];
	ext = ft_strrchr(filename, '.');
	if (!ext)
	{
		print_err("No extension\n");
	}
	if (!(ft_strcmp(ext + 1, "ber") == 0))
	{
		print_err("The typefile must be --> [.ber]\n");
	}
}

void	check_images(void)
{
	ft_check_img("./img/chara.xpm");
	ft_check_img("./img/land.xpm");
	ft_check_img("./img/wall.xpm");
	ft_check_img("./img/chest.xpm");
	ft_check_img("./img/rune.xpm");
}
