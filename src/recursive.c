/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 13:51:24 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/27 14:07:33 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	str_skip(char *str)
{
	char	*tmp;
	int		len;

	tmp = str;
	len = ft_strlen(tmp);
	while (*tmp != '\0')
		tmp++;
	while (*(tmp - 1) != '/' && len > 0)
	{
		tmp--;
		len--;
	}
	if (*tmp == '.')
		return (0);
	return (1);
}

void		parc_r(t_node *node, t_env *env)
{
	if (node == NULL)
		return ;
	parc_r(node->left, env);
	if (S_ISDIR(((t_args *)node)->info.st_mode)
			&& str_skip(((t_args *)node)->name))
	{
		ft_putstr("\n");
		ft_putstr(((t_args *)node)->name);
		ft_putstr(":\n");
		open_dir(((t_args *)node), env);
	}
	parc_r(node->right, env);
	free(node);
	node = NULL;
}

void		append(char *src, char *append)
{
	while (*src != '\0')
		src++;
	while (*append != '\0')
	{
		*src = *append;
		append++;
		src++;
	}
}

int			show2(t_args *av, t_env *env, t_maxes *max)
{
	char	*str;
	int		len;

	len = ft_strlen(av->name);
	str = av->name + len;
	while (len > 0 && *(str - 1) != '/')
	{
		str--;
		len--;
	}
	if (env->flag['a'] == 1 || *str != '.')
	{
		show_l(av, env, max);
		ft_putstr(str);
		if (env->flag['l'] == 1 && S_ISLNK(av->info.st_mode))
		{
			ft_putstr(" -> ");
			ft_putstr(av->link);
		}
		ft_putstr("\n");
	}
	return (0);
}
