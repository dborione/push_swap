/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:30:39 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 12:33:27 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_push(t_queue *queue_a, t_queue *queue_b)
{
	t_node	*tmp;

	tmp = queue_a->head;
	ft_dequeue_head(queue_a);
	if (!ft_enqueue_head(queue_b, tmp->value))
	{
		ft_free_queue(queue_b);
		ft_exit(queue_a, 1);
	}
	free(tmp);
	return (1);
}

int	ft_r_rotate(t_queue *queue)
{
	t_node	*tmp;

	tmp = queue->head;
	ft_dequeue_head(queue);
	if (!ft_enqueue_tail(queue, tmp->value))
		return (0);
	free(tmp);
	return (1);
}

int	ft_swap(t_queue *queue)
{
	t_node	*tmp;

	tmp = ft_dequeue_head(queue);
	tmp->next = queue->head->next;
	queue->head->next = tmp;
	return (1);
}
