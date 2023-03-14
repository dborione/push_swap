#include "push_swap.h"
#include "libft.h"

int ft_sort_big(t_queue *queue_a, t_queue *queue_b)
{
    int i;
    

    if (ft_is_sorted(queue_a) == 1)
        return (1);

    i = 5;
    while (i > 0)
    {
        ft_push(queue_a, queue_b);
        //printf("pb\n");
        i--;
    }
    ft_sort_five(queue_b, queue_a);
    i = 5;
    while (i > 1)
    {
        ft_rr_reverse_rotate(queue_b);
        //printf("rrb\n");
        ft_push(queue_b, queue_a);
        //printf("pa\n");
        i--;
    }
    ft_push(queue_b, queue_a);
    //printf("pa\n");
    if (ft_is_sorted(queue_a) == 1)
        return (1);
    ft_rr_reverse_rotate(queue_a);
    //printf("ra\n");
	ft_print_queue(queue_a);
	ft_print_queue(queue_b);
    // ft_sort_big(queue_a, queue_b);

}

int	ft_print_index(t_queue *queue)
{
	t_node	*tmp;
	
	tmp = queue->head;
	while(tmp)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("||");
	free(tmp);
	return (1);
}


int ft_get_index_min(t_queue *queue, int min)
{
    int new_min;
    t_node	*tmp;

	tmp = queue->head;
    new_min = 0;
	while(tmp)
	{
        if (tmp->value > min)
            new_min = tmp->value;
        tmp = tmp->next;
	}
	free(tmp);
	return (new_min);
}

void ft_index(t_queue *queue)
{
    int index;
    int min;
    int size;

    size = ft_queue_size(queue);
    t_node	*tmp;

    index = 0;
	tmp = queue->head;
    min = ft_get_min(queue);
    printf("%d ", min);
    tmp->index = index;
	while(size > 1)
	{
        min = ft_get_index_min(queue, min);
        printf("%d ", min);
        // if (tmp->value == min)
        //     tmp->index = index;
		// tmp = tmp->next;
        size--;
       // index++;

	}
    //ft_print_queue(queue);
    printf("\n");
    //ft_print_index(queue);
}
