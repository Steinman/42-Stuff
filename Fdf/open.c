/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:28:08 by hcorrale          #+#    #+#             */
/*   Updated: 2016/03/24 16:38:49 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int      *ft_inttab(char *buf)
{
	int         *tab;
	int         i;
	int         j;

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
	printf("%s", "\n");
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
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int				ft_open(char *file)
{
	int			fd;
	int			i;
	int			**tab;
	char		*buf;
	char		*line;
	char		**stock;

	fd = open(file, O_RDONLY);
	buf = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, '\n');
		i++;
	}
	close (fd);
	stock = ft_strsplit(buf, '\n');
	tab = ft_inttabtab(stock, i);
	return (tab);
}
