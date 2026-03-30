/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:38:25 by semebrah          #+#    #+#             */
/*   Updated: 2026/03/30 20:38:54 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void	free_file(t_file **repo, t_file *file)
{
	t_file	*curr;
	t_file	*prev;

	if (!repo)
		return ;
	curr = *repo;
	while (curr && curr != file)
	{
		prev = curr;
		curr = curr->next;
	}
	if (*repo == file)
		*repo = file->next;
	else
		prev->next = file->next;
	free(file->stash);
	free(file);
}

char	*get_next_line(int fd)
{
	static t_file	*repo = NULL;
	t_file			*file;
	char			buffer[BUFFER_SIZE];
	int				readbytes;
	int				ix;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = get_file(&repo, fd);
	while (true)
	{
		ix = find(file->stash, '\n', file->stash_size);
		if (ix > -1)
		{
			ret = malloc(ix + 2);
			ft_memcpy(ret, file->stash, ix + 1);
			ret[ix + 1] = '\0';
			update_stash(file, ix + 1, file->stash_size - (ix + 1));
			return (ret);
		}
		else
		{
			ix = file->stash_size;
			readbytes = read(fd, buffer, BUFFER_SIZE);
			update_stash(file, 0, ix + readbytes);
			ft_memcpy(&file->stash[ix], buffer, readbytes);
			if (readbytes < 0)
				return (free_file(&repo, file), NULL);
			if (readbytes == 0)
			{
				if (!file->stash_size)
					return (free_file(&repo, file), NULL);
				ret = malloc(file->stash_size + 1);
				ft_memcpy(ret, file->stash, file->stash_size);
				ret[file->stash_size] = '\0';
				return (free_file(&repo, file), ret);
			}
		}
	}
}
