/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:44:51 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/18 15:47:36 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_nlink(t_args *av, t_maxes *max)
{
	int		len;

	len = 0;
	len = max->max_nlink - ret_len(av->info.st_nlink);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putnbr(av->info.st_nlink);
	ft_putstr(" ");
}
