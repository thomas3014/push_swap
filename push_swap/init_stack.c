/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:30:01 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/04/20 10:15:53 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	pt = malloc((i + 1) * sizeof(char));
	while (str[i] && str[i] != stop)
		i++;
	if (!(pt))
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int	fill_stack_arg(char *arg, t_stack *stack, size_t *stack_nb)
{
	int		num;
	char	*str;

	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (!*arg)
			break ;
		str = ft_strdup_char(arg, ' ');
		if (ft_atoi(str, &num))
		{
			free(str);
			return (1);
		}
		free(str);
		if (stack_contains(stack, num))
			return (1);
		stack->array[(*stack_nb)++] = num;
		stack->size++;
		while (*arg && *arg != ' ')
			arg++;
	}
	return (0);
}

int	fill_stack(int argc, char *argv[], t_stack *stack)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (i < (size_t)argc)
	{
		ptr = argv[i];
		if (fill_stack_arg(ptr, stack, &j))
			return (1);
		i++;
	}
	return (0);
}

size_t	count_stack_size(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	init_stacks(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
	size_t		stack_size;

	stack_size = count_stack_size(argc, argv);
	stack_a->array = (int *)malloc(sizeof(int) * stack_size);
	stack_b->array = (int *)malloc(sizeof(int) * stack_size);
	if (!(stack_a->array))
		return (write(STDERR_FILENO, "Error\n", 6));
	if (!(stack_b->array))
	{
		free(stack_a->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	stack_a->max_size = stack_size;
	stack_b->max_size = stack_size;
	stack_a->size = 0;
	stack_b->size = 0;
	if (fill_stack(argc, argv, stack_a))
	{
		free(stack_a->array);
		free(stack_b->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
