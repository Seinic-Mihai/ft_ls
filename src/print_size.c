/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:48:28 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/19 16:08:36 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_size(t_args *av, t_maxes *max)
{
	int		len;

	len = max->max_size - ret_len(av->info.st_size);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putnbr(av->info.st_size);
	ft_putstr(" ");
}
