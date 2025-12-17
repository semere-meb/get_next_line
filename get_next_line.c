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
	static char	buffer[BUFFER_SIZE];
	int			index;
	ssize_t		readbytes;
	char		*temp;

	temp = NULL;
	while (1)
	{
		index = ft_index(buffer, '\n', BUFFER_SIZE);
		if (index > -1)
		{
			temp = ft_str_append(temp, buffer, index + 1);
			ft_move_remainder(buffer, index + 1, BUFFER_SIZE);
			return (temp);
		}
		else
		{
			temp = ft_str_append(temp, buffer, BUFFER_SIZE);
			ft_memset(buffer, 0, BUFFER_SIZE);
			readbytes = read(fd, buffer, BUFFER_SIZE);
			if (readbytes <= 0 && ft_strlen(temp))
				return (temp);
			else if (readbytes <= 0 && !ft_strlen(temp))
				return (NULL);
		}
	}
}
