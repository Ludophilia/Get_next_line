/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:00 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/24 14:30:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open(".gitignore", O_RDONLY);
	if (fd == -1 && dprintf(2, "There was a problem with that m*fuc*r\n"))
		return (1);
	printf("Ca marche !!\n");
}
