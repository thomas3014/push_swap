/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:45:21 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/04/20 15:50:52 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	less_mvt_at_end_suite(size_t minimal_mvt,
			t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;
	size_t	m;
	size_t	t[2];

	m = minimal_mvt + 1;
	i = stack_a->size;
	if (t[0] > stack_b->size / 2 && t[1] >= (stack_a->size - i) && t[1] < m)
		m = t[1];
	else if (t[0] > stack_b->size / 2
		&& t[1] < (stack_a->size - i) && (stack_a->size - i) < m)
		m = (stack_a->size - i);
	else if ((stack_a->size - i) + t[0] < m)
		m = (stack_a->size - i) + t[0];
	return (m);
}

t_state	*new_empty_state_suite(void)
{
	t_state	*state;

	state = NULL;
	free_stack(state->stack_a);
	free(state);
	return (NULL);
}

t_state	*add_state_suite(t_state *new)
{
	free_states(new);
	return (NULL);
}
