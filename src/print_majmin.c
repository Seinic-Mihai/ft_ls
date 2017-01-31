/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_majmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:17:09 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/19 14:30:15 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_majmin(t_args *av, t_maxes *max)
{
	int len;

	len = max->max_maj - ret_len(av->major);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putnbr(av->major);
	ft_putstr(", ");
	len = max->max_min - ret_len(av->minor);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putnbr(av->minor);
	ft_putstr(" ");
}
