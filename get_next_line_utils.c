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

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
		((char *)s)[--n] = (char)c;
	return (s);
}

ssize_t	ft_index(const char *s, size_t start, size_t end, char c)
{
	size_t	i;

	if (!s || end == 0)
		return (-1);
	i = start;
	while (i < end)
	{
		if (s[i] == c)
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

char	*ft_str_append(char const *s1, char const *s2, size_t start, size_t end)
{
	ssize_t	i;
	size_t	s1_len;
	char	*new;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	new = malloc(s1_len + end - start + 1);
	if (!new)
		return (NULL);
	i = -1;
	while ((size_t)++i < s1_len)
		new[i] = s1[i];
	while (start < end)
		new[i++] = s2[start++];
	new[i] = '\0';
	return (new);
}
