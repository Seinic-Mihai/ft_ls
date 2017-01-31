/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 15:12:58 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/27 17:37:41 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		init_tree(t_tree *tree, t_env *env, t_maxes *max)
{
	ft_bzero(max, sizeof(t_maxes));
	if (env->flag['r'] == 1)
	{
		if (env->flag['t'] == 1)
			*tree = NEW_TREE(sizeof(t_args), time_cmp3);
		else
			*tree = NEW_TREE(sizeof(t_args), my_cmp3);
	}
	else
	{
		if (env->flag['t'] == 1)
			*tree = NEW_TREE(sizeof(t_args), time_cmp4);
		else
			*tree = NEW_TREE(sizeof(t_args), my_cmp2);
	}
}

static void		append_tmp(t_args *tmp, t_args *av, struct dirent *dp)
{
	ft_bzero(tmp, sizeof(t_args));
	if ((ft_strlen(av->name) + ft_strlen("/") + ft_strlen(dp->d_name))
			< 1024)
	{
		append(tmp->name, av->name);
		if (tmp->name[ft_strlen(tmp->name) - 1] != '/')
			append(tmp->name, "/");
		append(tmp->name, dp->d_name);
	}
	get_lstat(tmp);
}

static void		add_tmp(t_env *env, struct dirent *dp, t_maxes *max)
{
	if ((env->flag['l'] == 1 && dp->d_name[0] != '.')
			|| (env->flag['s'] == 1 && dp->d_name[0] != '.')
			|| (env->flag['a'] == 1 && (env->flag['l'] == 1
					|| env->flag['s'] == 1)))
		max->nbr++;
}

static void		read_dir(t_var *var, t_args *av, t_env *env)
{
	while ((var->dp = readdir(var->dirptr)) != NULL)
	{
		append_tmp(&var->tmp, av, var->dp);
		if (var->tmp.status == -1)
			error_text(var->dp->d_name);
		else
		{
			if (env->flag['a'] == 0 && var->dp->d_name[0] == '.')
				ft_bzero(&var->tmp.info, sizeof(struct stat));
			add_tmp(env, var->dp, &var->max);
			ft_add_node_to_tree(&var->tree, (t_node *)&var->tmp);
			max_len(&var->max, &var->tmp);
		}
	}
}

void			open_dir(t_args *av, t_env *env)
{
	t_var		var;

	ft_bzero(&var, sizeof(t_var));
	init_tree(&var.tree, env, &var.max);
	if ((var.dirptr = opendir(av->name)) != NULL)
	{
		read_dir(&var, av, env);
		print_total(env, &var.max);
		parc_in_order2(var.tree.root, env, &var.max);
		if (env->flag['R'] == 1)
			parc_r(var.tree.root, env);
		closedir(var.dirptr);
	}
	else
		error_text(av->name);
}
