/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:03 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/04 15:01:10 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
		((char *)s)[--n] = (char)c;
	return (s);
}

ssize_t	get_index(const char *s, char c, size_t size)
{
	size_t	i;

	if (!s || size == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (s[i] == c)
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

void	shift_remainder(char *buff, size_t start, size_t size)
{
	ssize_t	i;

	i = -1;
	while (start + ++i < size)
		buff[i] = buff[start + i];
	ft_memset(&buff[i], 0, size - i);
}

char	*append(char *s1, char *s2, size_t size)
{
	ssize_t	i;
	size_t	s1_len;
	char	*new;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	new = malloc(s1_len + size + 1);
	if (!new)
		return (NULL);
	i = -1;
	while ((size_t)++i < s1_len && s1[i])
		new[i] = s1[i];
	i = -1;
	while ((size_t)++i < size && s2[i])
		new[s1_len + i] = s2[i];
	new[s1_len + i] = '\0';
	if (s1)
		free(s1);
	if (!ft_strlen(new))
		return (free(new), NULL);
	return (new);
}
