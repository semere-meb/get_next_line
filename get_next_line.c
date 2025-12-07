/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:00 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/04 15:01:10 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd){
	static char buffer[BUFFER_SIZE];
	static ssize_t last = -1;

	int index;
	int readbytes;
	char *temp = "";

	while (1) {
		index = ft_index(&buffer[last+1], BUFFER_SIZE - last, '\n');
		
		if (index > -1){
			temp = ft_strappend(temp, &buffer[last+1], index);
			last = index;
			dprintf(1, "DEBUG start:\n");
			dprintf(1, "%s", buffer);
			dprintf(1, "\nDEBUG end:\n");
			return temp;
		}
		else {
			temp = ft_strappend(temp, &buffer[last+1], BUFFER_SIZE - last);
			ft_memset(buffer, 0, BUFFER_SIZE);
			readbytes = read(fd, buffer, BUFFER_SIZE);
			if (readbytes < 0)
				return temp;
			else if (readbytes < BUFFER_SIZE)
				return ft_strappend(temp, buffer, readbytes);
		}
	}
}

size_t ft_strlen(char *str) {
	size_t len = 0;
	while (str[len])
		len++;

	return len;
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_display_file(char *filename)
{
	int		fd;
	char	*res;
	char c;
	int readbytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while ((res = get_next_line(fd)))
	{
		ft_putstr(res);
		ft_putstr("\nPress 'Enter' to continue: ");
		readbytes = read(0, &c, 1);
		if (!readbytes || c != '\n')
			break;
	}
	close(fd);
}

int	main()
{
		ft_display_file("get_next_line.c");
}
