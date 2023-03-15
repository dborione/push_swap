#include "../includes/push_swap.h"
#include "../includes/libft.h"

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
    t_node	*tmp;
    int new_min;
    int size;
    int i;

    size = ft_queue_size(queue);
	tmp = queue->head;
    new_min = min + 1;
    i = 0;
	while(tmp)
	{
        if (tmp->value < new_min && tmp->value > min)
            new_min = tmp->value;
		tmp = tmp->next;
	}
	free(tmp);
	return (new_min);
}

void ft_index(t_queue *queue)
{
    int     index;
    int     min;
    int     size;
    int     i;
    t_node	*tmp;

    size = ft_queue_size(queue);
    i = 0;
    index = 1;
	tmp = queue->head;
    //min = ft_get_min(queue);
    min = ft_get_index_min(queue, 3);
    printf("%d", min);
	while(i <= 5)
	{
        //printf("%d", min);
        if (tmp->value == min)
        {
           // tmp->index = index;
           // min = ft_get_index_min(queue, min);
           // index++;
           // tmp = queue->head;
            i++;
        }
        else
            tmp = tmp->next;

        // if (tmp->value != min)
        //     tmp = tmp->next;
    //     else
    //     {
    //         tmp->index = index;
    //         tmp = queue->head;  
    //         index++;
    //         min = ft_get_index_min(queue, min);
    //         //printf("%d", min);

    //    }
        //i++;
	}
   // ft_print_queue(queue);
    printf("\n");
    //ft_print_index(queue);
}

int ft_get_max_bits(t_queue *queue)
{
    int max_bits;
    int size;
    t_node	*tmp;

    tmp = queue->head;
    size = ft_queue_size(queue);
    max_bits = 0;

    while (size > 0)
    {
        while ((tmp->index >> max_bits) != 0)
            max_bits++;    
        tmp = tmp->next;
        size--;
    }
    free(tmp);
    return (max_bits);
}


void ft_radix(t_queue *queue_a, t_queue *queue_b)
{
    int max_bits;
    int size;
    t_node	*tmp;
    int i;

    tmp = queue_a->head;
    size = ft_queue_size(queue_a);
    max_bits = ft_get_max_bits(queue_a) - 1; // 3->2
    
    i = 0;
    //printf("%d/", ((tmp->index >> max_bits)&1));
    while (tmp)
    {
        printf("%d/", tmp->index);
        // if (((tmp->index >> max_bits)&1) == 1)
        //     ft_r_rotate(queue_a);
        // else
        //     ft_push(queue_a, queue_b);
        tmp = tmp->next;
        //i++;
        //size--;
    }
}

void ft_sort_big(t_queue *queue_a, t_queue *queue_b)
{
    ft_index(queue_a);
    //ft_radix(queue_a, queue_b);
}