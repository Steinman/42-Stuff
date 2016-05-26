/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:28:08 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/26 14:01:12 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_intnb(char *str)
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
			while (str[i + 1] != ' ' && str[i + 1] != '\0')
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
		if (!ft_isdigitchar(buf[i]) && buf[i] != '-')
			i++;
		else
		{
			tab[j] = ft_atoi_nb(buf, &i);
			j++;
			while (buf[i] != ' ' && buf[i])
				i++;
		}
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
	char		**stock;

	v = ft_fd_error(v, fd, file);
	if ((v->err = ft_emptyline(v->buf)) == -1)
	{
		ft_putstr("ERROR: empty line\n");
		return (v);
	}
	close(fd);
	stock = ft_strsplit(v->buf, '\n');
	free(v->buf);
	if ((v->err = ft_lineerror(stock, v)) == -1)
	{
		ft_putstr("ERROR: file error\n");
		return (v);
	}
	v->len = ft_intnb(stock[0]);
	v->tab = ft_inttabtab(stock, v->l);
	free(stock);
	return (v);
}
