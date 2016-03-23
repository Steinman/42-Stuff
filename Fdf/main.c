/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:53:56 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/23 16:38:34 by hcorrale         ###   ########.fr       */
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
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int));
	while (buf[i] != '\0')
	{
		while (buf[i] == ' ')
			i++;
		tab[j] = ft_atoi_nb(buf, &i);
		printf("%i  ", tab[j]);
		j++;
		i++;
	}
	return (tab);
}

static int      **ft_inttabtab(char **stock, int nb)
{
	int         **tab;
	int         i;

	i = 0;
	tab = (int **)malloc(sizeof(int) * nb);
	while (i < nb)
	{
		tab[i] = ft_inttab(stock[i]);
		ft_putchar('\n');
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			**tab;
	char 		*line;
	char		*buf;
	char		**stock;
	int			i;

	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
		i++;
	}
	close(fd);
	printf("%s\n", buf);
	stock = ft_strsplit(buf, '\n');
	tab = ft_inttabtab(stock, i);
	return (0);
}
