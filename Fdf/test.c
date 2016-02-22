/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:46:02 by hcorrale          #+#    #+#             */
/*   Updated: 2016/02/22 15:16:30 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int		ft_key(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (0);
}

int		main(void)
{
	void *mlx;
	void *win;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx test");
	while (x != 400 && y != 400)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
		y++;
	}
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
}
