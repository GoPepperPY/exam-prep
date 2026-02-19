#include "ft_list.h"

void nothiing(void *data)
{
	printf("%d\n", *(int *)data);
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

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *current = (t_list *)malloc(sizeof(t_list));

	if(!current)
		return ;
	current = begin_list;
	while(current)
	{
		(*f)(current->data);
		current = current->next;
	}
}

int main(void)
{
	int a= 1, b = 2, c=3;
	void *p1 = &a, *p2 = &b, *p3 = &c;
	t_list *list = (t_list *)malloc(sizeof(t_list));

	list = ft_createnode(p1);
	list->next = ft_createnode(p2);
	list->next->next = ft_createnode(p3);
	ft_list_foreach(list, &nothiing);
}