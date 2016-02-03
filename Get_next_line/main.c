/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:55:05 by hcorrale          #+#    #+#             */
/*   Updated: 2016/02/03 16:15:00 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

int				main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%d\n", strcmp(line, "abc"));
	printf("%s", line);
	return (0);
}
