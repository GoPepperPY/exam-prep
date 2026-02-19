#include "ft_list.h"

int	nothing(void *n1, void *n2)
{
	return (*(int *)n1 - *(int *)n2);
}

t_list	*ft_createnode(void *data)
{
	t_list	*current = (t_list *) malloc(sizeof(t_list));
	if(!current)
		return (NULL);
	current->data = data;
	current->next = NULL;
	return(current);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *prev = NULL;
	list_ptr = *begin_list;
	while(list_ptr)
	{
        if((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if(!prev)
				prev = list_ptr->next;
			else
				prev->next = list_ptr->next;
			list_ptr->data = NULL;
			free(list_ptr);
			list_ptr = NULL;
		}
		else
		{
			prev = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
}

void	print(t_list *current)
{
	while(current)
	{
		printf("%d", *(int *)current->data);
		current = current->next;
	}
}

int main(void)
{
	int a= 1, b = 2, c=3, d= 2;
	void *p1 = &a, *p2 = &b, *p3 = &c, *data = &d;
	t_list *list = (t_list *)malloc(sizeof(t_list));

	list = ft_createnode(p1);
	list->next = ft_createnode(p2);
	list->next->next = ft_createnode(p3);
	ft_list_remove_if(&list, data, &nothing);
	print(list);
	free(list);
}