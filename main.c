#include "push_swap.h"

int	ft_print_queue(t_queue *queue)
{
	t_node	*tmp;
	
	tmp = queue->head;
	while(tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("||");
	free(tmp);
	return (1);
}

int main ()
{
	// if (argc != 2)
	// {
	// 	printf("%s\n", argv[1]);
	// 	//write(1, "Error", 6);
	// 	return (0);
	// }
	// else
	// {
	// 	if (ft_check_valid_list(argv[1]) == 0)
	// 		write(1, "Error", 6);
	// 	write(1, "ok", 2);
	// 	return (1);
	// }

	t_queue	queue_a;
	t_queue	queue_b;

	init_queue(&queue_a);
	init_queue(&queue_b);


	// here put the content of list into queue_a
	ft_enqueue(&queue_a, 1);
	ft_enqueue(&queue_a, 2);
	ft_enqueue(&queue_a, 3);
	ft_enqueue(&queue_a, 4);
	
	ft_enqueue(&queue_b, 6);
	ft_enqueue(&queue_b, 7);
	ft_enqueue(&queue_b, 8);
	ft_enqueue(&queue_b, 9);

	ft_print_queue(&queue_a);
	ft_print_queue(&queue_b);

	printf("\n");


	// push b
	//ft_push(&queue_a, &queue_b);
 
	//ft_r_rotate(&queue_a);
	//ft_rr_rotate(&queue_a, &queue_b);
	//ft_rr_reverse_rotate(&queue_b);
	ft_rrr_reverse_rotate(&queue_a, &queue_b);

	ft_print_queue(&queue_a);
	ft_print_queue(&queue_b);
	// printf("queue a head:%d\n", queue_a.head->value);
	// printf("queue a tail:%d\n", queue_a.tail->value);
	// printf("queue b head:%d\n", queue_b.head->value);
	// printf("queue b tail:%d\n", queue_b.tail->value);

	// // push a
	// ft_push(&queue_b, &queue_a);
	// printf("queue a head:%d\n", queue_a.head->value);
	// printf("queue a tail:%d\n", queue_a.tail->value);
	// printf("queue b head:%d\n", queue_b.head->value);
	// printf("queue b tail:%d\n", queue_b.tail->value);

	return (0);
}