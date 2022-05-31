/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:22:11 by eardingh          #+#    #+#             */
/*   Updated: 2022/05/12 17:50:27 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

//line --> first line [27]
//line --> Duplicate the first line [36]
//line --> second line [41]
//line --> check if there is a next line --> for do not add nothing (NULL) [44]

void	ft_make_map(char *filename, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("Error --> Put a Valid File\n");
	line = get_next_line(fd);
	if (!line)
		print_err("File EMPTY\n");
	game->hei = 0;
	game->walk_cnt = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
			game->map = ft_split(game->str_line, '\n');
		}
	}
	close(fd);
}

//CHECK BORDER
//CHECK FIRST LINE
//CHECK LAST LINE
//CHECK Unexpected char(s)
//CHECK EXIT
//CHECK PLAYERS
//CHECK COLLECTIONABLE

void	ft_check_map(t_game *game)
{
	ft_check_rectangular(game);
	ft_check_border(game);
	ft_check_walls(game, 0);
	ft_check_walls(game, ft_check_lastline(game));
	ft_check_character(game);
	ft_check_number(game, 'E');
	ft_check_number(game, 'P');
	ft_check_number(game, 'C');
}
