/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/02 18:09:24 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

// should work without BUFFER_SIZE size, maybe with an ifndef
// Use read (WITH constant macro BUFFER_SIZE), malloc, free

char	*get_next_line(int fd)
{
	(void)fd;
	printf("Buffer size: %i\n", BUFFER_SIZE);
	// return the line (with a \n if it contains one) as a char *
	// or NULL/(char *)0 in case of error
	return (0);
}

int	main(void)
{
	get_next_line(0);
}