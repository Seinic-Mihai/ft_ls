/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:48:08 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/27 15:55:02 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parc_in_order2(t_node *node, t_env *env, t_maxes *max)
{
	if (node == NULL)
		return ;
	parc_in_order2(node->left, env, max);
	show2((t_args *)node, env, max);
	parc_in_order2(node->right, env, max);
}

int		my_cmp2(t_args *n1, t_args *n2)
{
	return (ft_strcmp(n1->name, n2->name));
}

int		my_cmp3(t_args *n1, t_args *n2)
{
	return (ft_strcmp(n2->name, n1->name));
}
