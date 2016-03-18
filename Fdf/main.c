/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:56 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/18 17:33:41 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "libft/libft.h"

static int		**ft_inttab(char **buf, int h)
{
	int			**tab;
	int			j;
	int			i;
	int			k;

	tab = (int **)malloc(sizeof(int) * h);
	j = 0;
	i = 0;
	k = 0;
	while (buf[i] != '\0')
	{
		tab[k] = (int *)malloc(sizeof(int));
		if (buf[i] == ' ')
			i++;
		tab[k][j] = ft_atoi_nb(buf, i);
		i++;
		j++;
	}
	tab[k] = NULL;
	return (tab);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			**tab;
	char 		*line;
	char		*buf;
	char		**stock;
	size_t		i;
	int			j;

	if (argc != 2)
		return (0);
	j = 0;
	fd = open(argv[1], O_RDONLY);
	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
		j++;
	}
	close(fd);
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	printf("%s\n", buf);
	stock = ft_strsplit(buf, '\n');
	tab = ft_inttab(stock, j);
	return (0);
}