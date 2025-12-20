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
#include <sys/select.h>

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

void	display_files(int count, char **f_names)
{
	char	*res;
	int		fd_count;
	int		*fds;

	fd_count = count;
	fds = malloc(sizeof(int) * count);
	if (!fds)
		return ;
	for (int i = 0; i < count; i++)
	{
		fds[i] = open(f_names[i], O_RDONLY);
		if (fds[i] == -1)
		{
			dprintf(1, "Can't open %s\n", f_names[i]);
			fd_count--;
		}
	}
	while (fd_count > 0)
	{
		for (int i = 0; i < count; i++)
			if (fds[i] > 0)
			{
				if ((res = get_next_line(fds[i])))
				{
					dprintf(1, "%s", res);
					free(res);
				}
				else
				{
					close(fds[i]);
					fds[i] = -1;
					fd_count--;
				}
			}
	}
	free(fds);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_display_file(0);
	else
		display_files(argc - 1, &argv[1]);
}
