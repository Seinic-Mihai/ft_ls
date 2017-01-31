/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:49:04 by mseinic           #+#    #+#             */
/*   Updated: 2016/07/20 18:21:57 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
}

int				main(int ac, char **av)
{
	t_env	env;

	init(&env);
	create_env(ac, av, &env);
	return (0);
}
