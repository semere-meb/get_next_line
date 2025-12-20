/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:00 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/20 21:36:20 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/select.h>

char	*get_next_line(int fd)
{
	static char	buff[FD_SETSIZE][BUFFER_SIZE];
	int			ix;
	ssize_t		readbytes;
	char		*temp;

	temp = NULL;
	while (1)
	{
		ix = get_index(buff[fd], '\n', BUFFER_SIZE);
		if (ix > -1)
		{
			temp = append(temp, buff[fd], ix + 1);
			shift_remainder(buff[fd], ix + 1, BUFFER_SIZE);
			return (temp);
		}
		temp = append(temp, buff[fd], BUFFER_SIZE);
		ft_memset(buff[fd], 0, BUFFER_SIZE);
		readbytes = read(fd, buff[fd], BUFFER_SIZE);
		if (readbytes == 0)
			return (temp);
		if (readbytes < 1)
			return (NULL);
	}
}
