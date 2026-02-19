#include "ft_list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*ft_createnode(int data)
{
	t_list	*current = (t_list *) malloc(sizeof(t_list));
	if(!current)
		return (NULL);
	current->data = data;
	current->next = NULL;
	return(current);
}

void	swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*cur;
	while(lst)
	{
		cur = lst;
		while(cur)
		{
			if ((*cmp)(lst->data, cur->data) == 0)
			{
				swap(&lst->data, &cur->data);
			}
			cur = cur->next;
		}
		lst = lst->next;
	}
	return(lst);
}

void	print(t_list *current)
{
	while(current)
	{
		printf("%d", current->data);
		current = current->next;
	}
}

int main(void)
{
	int a= 1, b = 3, c=2;
	// void *p1 = &a, *p2 = &b, *p3 = &c, *data = &d;
	t_list *list = (t_list *)malloc(sizeof(t_list));

	list = ft_createnode(a);
	list->next = ft_createnode(b);
	list->next->next = ft_createnode(c);
	sort_list(list, ascending);
	print(list);
	free(list);
}