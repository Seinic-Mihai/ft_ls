/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 16:43:13 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/27 16:45:05 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		error_text(char *str)
{
	ft_putstr("./ft_ls: ");
	ft_putstr(str);
	ft_putstr(": Permission denied\n");
}

void		print_total(t_env *env, t_maxes *max)
{
	if ((env->flag['l'] == 1 || env->flag['s'] == 1) && max->nbr > 0)
	{
		ft_putstr("total ");
		ft_putnbr(max->total);
		ft_putstr("\n");
	}
}
