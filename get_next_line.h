/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:04:27 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/27 19:49:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

long		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, long len);
char		*ft_strjoin(char const *s1, char const *s2);

char		*get_next_line(int fd);

#endif
