/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:28:08 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/09 16:12:53 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_intnb(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] < 48 && str[i] > 57 && str[i] != '\0')
			i++;
		if (str[i] >= 48 && str[i] <= 57)
		{
			j++;
			while (str[i + 1] >= 48 && str[i + 1] <= 57)
				i++;
		}
		i++;
	}
	return (j);
}

static int		*ft_inttab(char *buf)
{
	int			*tab;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int) * ft_intnb(buf));
	while (buf[i] != '\0')
	{
		while (buf[i] == ' ')
			i++;
		tab[j] = ft_atoi_nb(buf, &i);
		j++;
		i++;
	}
	return (tab);
}

static int		**ft_inttabtab(char **stock, int nb)
{
	int			**tab;
	int			i;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * nb);
	while (i < nb)
	{
		tab[i] = ft_inttab(stock[i]);
		i++;
	}
	return (tab);
}

t_var			*ft_open(char *file, t_var *v, int fd)
{
	char		*buf;
	char		*line;
	char		**stock;

	v->l = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		v->err = -1;
		return (v);
	}
	buf = ft_strnew(1);
	while ((v->err = get_next_line(fd, &line)) > 0)
	{
		buf = ft_strjoin(buf, line);
		buf = ft_strjoin(buf, "\n");
		v->l++;
	}
	if (v->err == -1)
		return (v);
	close(fd);
	stock = ft_strsplit(buf, '\n');
	free(buf);
	v->len = ft_intnb(stock[0]);
	v->tab = ft_inttabtab(stock, v->l);
	free(stock);
	return (v);
}
