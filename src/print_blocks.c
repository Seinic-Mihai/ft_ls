/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_blocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:38:44 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/19 15:51:39 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_blocks(t_args *av, t_maxes *max)
{
	int		len;

	len = max->max_blocks - ret_len(av->info.st_blocks);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putnbr(av->info.st_blocks);
	ft_putstr(" ");
}
