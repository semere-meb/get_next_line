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

#include <fcntl.h>
#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *get_next_line(int fd) {
	
	char buff[1024];
	size_t readbytes;

	readbytes = read(fd, buff, 1024);


	while ((readbytes = read(fd, buff, 1))) {
		if ()
	}

}

void	ft_display_file(char *filename)
{
	int		fd;
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	res = get_next_line(fd);
	while (res)
	{
		ft_putstr(res);
		res = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc == 2)
		ft_display_file(argv[1]);
	else
		ft_putstr("Too many arguments.\n");
}
