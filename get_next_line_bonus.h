/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:28:31 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/15 18:47:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef STASH_SIZE
#  define STASH_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
int		ft_strchr_sp(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**write_stash(char **stash, int fd, ssize_t bytesread, char *buffer);

char	**free_stash(char **stash);
char	*extract_line(int fd, char **stash);
ssize_t	update_stash(int fd, char **stash);
char	*get_next_line(int fd);

#endif