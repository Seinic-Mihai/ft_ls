/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 15:51:23 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/27 17:37:45 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	get_ac(t_args *tmp)
{
	char	str[1024];

	ft_bzero(&str, 1023);
	ft_memcpy(str, tmp->name, ft_strlen(tmp->name));
	str[ft_strlen(tmp->name)] = '\0';
	ft_memcpy(tmp->name, tmp->link, ft_strlen(tmp->link));
	tmp->name[ft_strlen(tmp->link)] = '\0';
	get_lstat(tmp);
	ft_memcpy(tmp->name, str, ft_strlen(str));
	tmp->name[ft_strlen(str)] = '\0';
}

static void	count_files(int *nbr, t_env *env, t_args *tmp, t_maxes *max)
{
	if (tmp->status != -1)
	{
		if (S_ISDIR(tmp->info.st_mode))
		{
			env->dir++;
			env->count_end++;
		}
		else
		{
			env->reg++;
			max_len(max, tmp);
		}
	}
	else
		(*nbr)++;
}

static void	check_sort(t_tree *tree, t_env *env)
{
	if (env->flag['r'] == 1)
	{
		if (env->flag['t'] == 1)
			*tree = NEW_TREE(sizeof(t_args), time_cmp);
		else
			*tree = NEW_TREE(sizeof(t_args), my_cmp4);
	}
	else
	{
		if (env->flag['t'] == 1)
			*tree = NEW_TREE(sizeof(t_args), time_cmp2);
		else
			*tree = NEW_TREE(sizeof(t_args), my_cmp);
	}
}

void		get_tree(int index, int ac, char **av, t_env *env)
{
	t_tree	tree;
	t_args	tmp;
	int		nbr;
	t_maxes	max;

	ft_bzero(&max, sizeof(t_maxes));
	nbr = 0;
	check_sort(&tree, env);
	while (index < ac)
	{
		ft_bzero(&tmp, sizeof(t_args));
		ft_memcpy(tmp.name, av[index], ft_strlen(av[index]));
		get_lstat(&tmp);
		if (ret_dir(&tmp) == 1 && env->flag['l'] == 0)
			get_ac(&tmp);
		ft_add_node_to_tree(&tree, (t_node *)&tmp);
		count_files(&nbr, env, &tmp, &max);
		index++;
	}
	if (env->reg > 0)
		env->reg += nbr;
	parc_in_order(tree.root, env, &max);
	ft_tree_destructor(tree.root);
}

int			create_env(int ac, char **av, t_env *env)
{
	char const *const str = ".";

	get_flags_args(ac, av, env);
	if (env->nbr_args == 0)
		get_tree(0, 1, (char **)&str, env);
	get_tree(ac - env->nbr_args, ac, av, env);
	return (0);
}
