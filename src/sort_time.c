/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:21:23 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 17:00:21 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_cmp(t_args *n1, t_args *n2)
{
	if (n1->info.st_mtimespec.tv_sec == n2->info.st_mtimespec.tv_sec)
	{
		if (n1->info.st_mtimespec.tv_nsec == n2->info.st_mtimespec.tv_nsec)
			return (my_cmp4(n1, n2));
		else if (n1->info.st_mtimespec.tv_nsec > n2->info.st_mtimespec.tv_nsec)
			return (1);
		else if (n1->info.st_mtimespec.tv_nsec < n2->info.st_mtimespec.tv_nsec)
			return (-1);
	}
	else if (n1->info.st_mtimespec.tv_sec > n2->info.st_mtimespec.tv_sec)
		return (1);
	else if (n1->info.st_mtimespec.tv_sec < n2->info.st_mtimespec.tv_sec)
		return (-1);
	return (0);
}

int		time_cmp2(t_args *n1, t_args *n2)
{
	if (n1->info.st_mtimespec.tv_sec == n2->info.st_mtimespec.tv_sec)
	{
		if (n1->info.st_mtimespec.tv_nsec == n2->info.st_mtimespec.tv_nsec)
			return (my_cmp(n1, n2));
		else if (n1->info.st_mtimespec.tv_nsec > n2->info.st_mtimespec.tv_nsec)
			return (-1);
		else if (n1->info.st_mtimespec.tv_nsec < n2->info.st_mtimespec.tv_nsec)
			return (1);
	}
	else if (n1->info.st_mtimespec.tv_sec > n2->info.st_mtimespec.tv_sec)
		return (-1);
	else if (n1->info.st_mtimespec.tv_sec < n2->info.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

int		time_cmp3(t_args *n1, t_args *n2)
{
	if (n1->info.st_mtimespec.tv_sec == n2->info.st_mtimespec.tv_sec)
	{
		if (n1->info.st_mtimespec.tv_nsec == n2->info.st_mtimespec.tv_nsec)
			return (ft_strcmp(n2->name, n1->name));
		else if (n1->info.st_mtimespec.tv_nsec > n2->info.st_mtimespec.tv_nsec)
			return (1);
		else if (n1->info.st_mtimespec.tv_nsec < n2->info.st_mtimespec.tv_nsec)
			return (-1);
	}
	else if (n1->info.st_mtimespec.tv_sec > n2->info.st_mtimespec.tv_sec)
		return (1);
	else if (n1->info.st_mtimespec.tv_sec < n2->info.st_mtimespec.tv_sec)
		return (-1);
	return (0);
}

int		time_cmp4(t_args *n1, t_args *n2)
{
	if (n1->info.st_mtimespec.tv_sec == n2->info.st_mtimespec.tv_sec)
	{
		if (n1->info.st_mtimespec.tv_nsec == n2->info.st_mtimespec.tv_nsec)
			return (ft_strcmp(n1->name, n2->name));
		else if (n1->info.st_mtimespec.tv_nsec > n2->info.st_mtimespec.tv_nsec)
			return (-1);
		else if (n1->info.st_mtimespec.tv_nsec < n2->info.st_mtimespec.tv_nsec)
			return (1);
	}
	else if (n1->info.st_mtimespec.tv_sec > n2->info.st_mtimespec.tv_sec)
		return (-1);
	else if (n1->info.st_mtimespec.tv_sec < n2->info.st_mtimespec.tv_sec)
		return (1);
	return (0);
}
