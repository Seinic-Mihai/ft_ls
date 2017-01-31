/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:29:16 by mseinic           #+#    #+#             */
/*   Updated: 2016/08/03 14:25:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		show_l(t_args *av, t_env *env, t_maxes *max)
{
	if (env->flag['s'] == 1)
		print_blocks(av, max);
	if (env->flag['l'] == 1)
	{
		print_rights(av);
		print_nlink(av, max);
		print_pwgr(av, max);
		if (S_ISCHR(av->info.st_mode) || S_ISBLK(av->info.st_mode))
			print_majmin(av, max);
		else
			print_size(av, max);
		print_time(av->info.st_mtimespec.tv_sec);
	}
}

int			show_reg(t_args *av, t_env *env, t_maxes *max)
{
	if (env->flag['a'] == 1 || av->name[0] != '.')
	{
		show_l(av, env, max);
		ft_putstr(av->name);
		if (av->link_exist == 1 && env->flag['l'] == 1)
		{
			ft_putstr(" -> ");
			ft_putstr(av->link);
		}
		ft_putstr("\n");
	}
	return (0);
}

int			show_dir(t_args *av, t_env *env)
{
	open_dir(av, env);
	return (0);
}

int			show(t_args *av, t_env *env, t_maxes *max)
{
	if (av->status != -1)
	{
		if (!S_ISDIR(av->info.st_mode))
			show_reg(av, env, max);
		else if (S_ISDIR(av->info.st_mode))
			show_dir(av, env);
	}
	else
	{
		ft_putstr("./ft_ls: ");
		ft_putstr(av->name);
		ft_putstr(": No such file or directory");
		ft_putstr("\n");
	}
	return (0);
}
