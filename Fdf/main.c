/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:56 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/14 16:59:58 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "libft/libft.h"

static int		*ft_inttab(char *buf)
{
	int			*tab;
	int			j;
	int i;

	tab = (int *)malloc(sizeof(int));
	j = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == ' ' || buf[i] == '\n')
			i++;
		else
		{
			tab[j] = ft_atoi_nb(buf, i);
			i++;
			j++;
		}
	}
	return (tab);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			*tab;
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
	printf("%s\n", buf);
	tab = ft_inttab(buf);
	printf("%d", tab[42]);
	return (0);
}
