/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:56 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/10 16:11:01 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "libft/libft.h"

int				main(int argc, char **argv)
{
	int			fd;
	char 		*line;
	char		*buf;
	size_t		i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
	}
	close(fd);
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	printf("%s", buf);
	return (0);
}
