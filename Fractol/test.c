/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:34:26 by hcorrale          #+#    #+#             */
/*   Updated: 2016/05/26 16:25:32 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_escape(int keycode, t_var *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		free(v);
		exit(0);
	}
	return (0);
}

int			main()
{
	t_var	*v;
	void	*img;
	char	*info;
	int		*bpp;
	int		*line;

	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 800, 800, "mlx_win");
	img = mlx_new_image(v->mlx, 800, 800);
	info = mlx_get_data_addr(v->mlx, bpp, line, 0);
	printf(info);
	mlx_key_hook(v->win, ft_escape, v);
	mlx_loop(v->mlx);
}
