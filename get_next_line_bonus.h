/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:38:30 by semebrah          #+#    #+#             */
/*   Updated: 2026/03/30 20:38:54 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_file
{
	int				fd;
	char			*stash;
	int				stash_size;
	struct s_file	*next;

}					t_file;

char				*get_next_line(int fd);

t_file				*create_file(int fd);
t_file				*get_file(t_file **repo, int fd);
int					find(char *str, char c, int size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				update_stash(t_file *file, size_t start, size_t new_size);
void				free_file(t_file **repo, t_file *file);

#endif
