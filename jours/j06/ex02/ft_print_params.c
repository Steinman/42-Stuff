/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:57:43 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/16 16:48:23 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int cpt;

	cpt = 1;
	while (cpt < argc)
	{
		while (*(argv[cpt] + i) != '\0')
		{
			ft_putchar(*(argv[cpt] + i));
			i++;
		}
		cpt++;
		ft_putchar('\n');
		i = 0;
	}
	return (0);
}
