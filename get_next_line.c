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
	static char		buffer[BUFFER_SIZE];
	static ssize_t	last = -1;
	int				index;
	int				readbytes;
	char			*temp;

	temp = "";
	while (1)
	{
		index = ft_index(buffer, last + 1, BUFFER_SIZE, '\n');
		if (index > -1)
		{
			temp = ft_str_append(temp, buffer, last + 1, index + 1);
			last = index;
			return (temp);
		}
		else
		{
			temp = ft_str_append(temp, buffer, last + 1, BUFFER_SIZE);
			last = -1;
			ft_memset(buffer, 0, BUFFER_SIZE);
			readbytes = read(fd, buffer, BUFFER_SIZE);
			if (readbytes < 0)
				return (temp);
		}
	}
}
