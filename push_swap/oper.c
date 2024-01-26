/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:37:46 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/04/20 10:16:29 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = tmp;
	}
}

void	rotate_stack(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = tmp;
	}
}

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	if (stack2->size > 0)
	{
		stack1->size++;
		reverse_rotate_stack(stack1);
		stack1->array[0] = stack2->array[0];
		rotate_stack(stack2);
		stack2->size--;
	}
}

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = tmp;
	}
}
