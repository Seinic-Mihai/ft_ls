/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:43:58 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 18:16:05 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int			my_cmp(t_args *n1, t_args *n2)
{
	int		test;

	test = 0;
	if (n1->status == -1 && n2->status == -1)
		return (ft_strcmp(n1->name, n2->name));
	else if (n1->status == -1 && n2->status != -1)
		return (-1);
	else if (n1->status != -1 && n2->status == -1)
		return (1);
	else
	{
		if (S_ISDIR(n1->info.st_mode) && !S_ISDIR(n2->info.st_mode))
			return (1);
		else if (S_ISDIR(n2->info.st_mode) && !S_ISDIR(n1->info.st_mode))
			return (-1);
		else
			return (ft_strcmp(n1->name, n2->name));
	}
}

int			my_cmp4(t_args *n1, t_args *n2)
{
	int		test;

	test = 0;
	if (n1->status == -1 && n2->status == -1)
		return (ft_strcmp(n2->name, n1->name));
	else if (n1->status == -1 && n2->status != -1)
		return (-1);
	else if (n1->status != -1 && n2->status == -1)
		return (1);
	else
	{
		if (S_ISDIR(n1->info.st_mode) && !S_ISDIR(n2->info.st_mode))
			return (1);
		else if (S_ISDIR(n2->info.st_mode) && !S_ISDIR(n1->info.st_mode))
			return (-1);
		else
			return (ft_strcmp(n2->name, n1->name));
	}
}

int			ret_len(int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0 && nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void		max_len(t_maxes *max, t_args *av)
{
	int		nbr;

	if (max->max_size < (nbr = ret_len(av->info.st_size)))
		max->max_size = nbr;
	if (max->max_nlink < (nbr = ret_len(av->info.st_nlink)))
		max->max_nlink = nbr;
	if (max->max_blocks < (nbr = ret_len(av->info.st_blocks)))
		max->max_blocks = nbr;
	if (max->max_maj < (nbr = ret_len(av->major)))
		max->max_maj = nbr;
	if (max->max_min < (nbr = ret_len(av->minor)))
		max->max_min = nbr;
	if (av->grpw.status_pw == 0 && max->max_pw < (nbr = ft_strlen(av->grpw.pw)))
		max->max_pw = nbr;
	else if (av->grpw.status_pw == 1
			&& max->max_pw < (nbr = ret_len(av->grpw.pwid)))
		max->max_pw = nbr;
	if (av->grpw.status_gr == 0 && max->max_gr < (nbr = ft_strlen(av->grpw.gr)))
		max->max_gr = nbr;
	else if (av->grpw.status_gr == 1
			&& max->max_gr < (nbr = ret_len(av->grpw.grid)))
		max->max_gr = nbr;
	max->total += av->info.st_blocks;
}
