/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grpw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 15:43:52 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 18:51:19 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_space(int len, char *str)
{
	if (str != NULL)
		ft_putstr(str);
	while (len > 0)
	{
		ft_putstr(" ");
		len--;
	}
	ft_putstr("  ");
}

void		print_pwgr(t_args *av, t_maxes *max)
{
	int		len;

	if (av->grpw.status_pw == 0)
	{
		len = max->max_pw - ft_strlen(av->grpw.pw);
		print_space(len, av->grpw.pw);
	}
	else
	{
		len = max->max_pw - ret_len(av->grpw.pwid);
		ft_putnbr(av->grpw.pwid);
		print_space(len, NULL);
	}
	if (av->grpw.status_gr == 0)
	{
		len = max->max_gr - ft_strlen(av->grpw.gr);
		print_space(len, av->grpw.gr);
	}
	else
	{
		len = max->max_gr - ret_len(av->grpw.grid);
		ft_putnbr(av->grpw.grid);
		print_space(len, NULL);
	}
}
