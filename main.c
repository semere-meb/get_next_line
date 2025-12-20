/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:03 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/04 15:01:10 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_display_file(int fd)
{
	char	*res;

	// char	c;
	if (fd == -1)
	{
		dprintf(1, "Cannot read file.\n");
		return ;
	}
	while ((res = get_next_line(fd)))
	{
		dprintf(1, "%s", res);
		// dprintf(1, ">> Press 'Enter' to continue: ");
		// scanf("%c", &c);
		// if (c != '\n')
		// 	break ;
		free(res);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_display_file(0);
	if (argc == 2)
		ft_display_file(open(argv[1], O_RDONLY));
}
