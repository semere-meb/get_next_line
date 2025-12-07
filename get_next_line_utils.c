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

void *ft_memset(void *s, int c, size_t n) {
	while (n > 0)
		((char *)s)[--n] = (char) c;
	return s;
}

ssize_t	ft_index(const char *s, size_t size, char c)
{
	size_t	i;

	if (!s || size == 0)
		return -1;
	
	i = 0;
	while (i < size && s[i]){
		if (s[i] == c)
			return (ssize_t)i;
		i++;
	}

	return -1;
}

char	*ft_strappend(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;
	char	*new;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	new = malloc(s1_len + n + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	while (i - s1_len < n)
	{
		new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}
