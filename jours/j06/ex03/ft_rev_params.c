/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrale <hcorrale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 14:53:26 by hcorrale          #+#    #+#             */
/*   Updated: 2015/07/16 16:42:54 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int cpt;

	cpt = 0;
	i = argc - 1;
	while (i > 0)
	{
		while (*(argv[i] + cpt) != '\0')
		{
			ft_putchar(*(argv[i] + cpt));
			cpt++;
		}
		i--;
		ft_putchar('\n');
		cpt = 0;
	}
	return (0);
}
