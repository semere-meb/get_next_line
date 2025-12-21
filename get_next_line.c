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

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	int			ix;
	ssize_t		readbytes;
	char		*temp;

	temp = NULL;
	while (1)
	{
		ix = get_index(buff, '\n', BUFFER_SIZE);
		if (ix > -1)
		{
			temp = append(temp, buff, ix + 1);
			shift_remainder(buff, ix + 1, BUFFER_SIZE);
			return (temp);
		}
		temp = append(temp, buff, BUFFER_SIZE);
		ft_memset(buff, 0, BUFFER_SIZE);
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == 0)
			return (temp);
		if (readbytes < 0)
			return (NULL);
	}
}
