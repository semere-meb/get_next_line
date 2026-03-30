/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:38:48 by semebrah          #+#    #+#             */
/*   Updated: 2026/03/30 20:38:54 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_file	*create_file(int fd)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->stash = NULL;
	file->stash_size = 0;
	file->next = NULL;
	return (file);
}

t_file	*get_file(t_file **repo, int fd)
{
	t_file	*curr;
	t_file	*prev;

	if (!repo)
		return (NULL);
	if (!*repo)
	{
		*repo = create_file(fd);
		return (*repo);
	}
	curr = *repo;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		prev = curr;
		curr = curr->next;
	}
	prev->next = create_file(fd);
	return (prev->next);
}

int	find(char *str, char c, int size)
{
	int	ix;

	ix = 0;
	if (!str)
		return (-1);
	while (ix < size)
	{
		if (str[ix] == c)
			return (ix);
		ix++;
	}
	return (-1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*_dest;
	const unsigned char	*_src = src;

	i = 0;
	_dest = dest;
	while (i < n)
	{
		_dest[i] = _src[i];
		i++;
	}
	return (dest);
}

void	update_stash(t_file *file, size_t start, size_t new_size)
{
	char	*new;

	if (!file)
		return ;
	if (!new_size)
	{
		free(file->stash);
		file->stash = NULL;
		file->stash_size = 0;
		return ;
	}
	new = malloc(new_size);
	if (!new)
		return ;
	ft_memcpy(new, &file->stash[start], file->stash_size - start);
	free(file->stash);
	file->stash = new;
	file->stash_size = new_size;
}
