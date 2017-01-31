/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_in_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 20:04:18 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 20:04:52 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parc_in_order(t_node *node, t_env *env, t_maxes *max)
{
	if (node == NULL)
		return ;
	parc_in_order(node->left, env, max);
	if (!S_ISDIR(((t_args *)node)->info.st_mode))
		env->reg--;
	else
	{
		env->count_end--;
		env->dir = 0;
	}
	if (S_ISDIR(((t_args *)node)->info.st_mode) && env->nbr_args > 1)
	{
		ft_putstr(((t_args *)node)->name);
		ft_putstr(":");
		ft_putstr("\n");
	}
	show((t_args *)node, env, max);
	if (env->reg == 0 && env->dir > 0)
		ft_putstr("\n");
	if (env->dir == 0 && env->count_end > 0)
		ft_putstr("\n");
	parc_in_order(node->right, env, max);
}
