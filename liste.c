#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
	int val;
	struct elem* next;
} elem_t;

void add_back(elem_t** chain, int val)
{
	elem_t* new_elem = malloc(sizeof(elem_t));
	new_elem->val = val;
	new_elem->next = NULL;

	elem_t* elm = *chain;
	if (*chain == NULL)
	{
		*chain = new_elem;
	}
	else
	{
		while (elm->next)
		{
			elm = elm->next;
		}
		elm->next = new_elem;
	}
}

void add_top(elem_t** chain, int val)
{
	elem_t* new_elem = malloc(sizeof(elem_t));
	new_elem->val = val;
	new_elem->next = *chain;
	*chain = new_elem;
}

void del_back(elem_t** chain)
{
	if (*chain == NULL)
		return;

	elem_t* elm = *chain;
	elem_t* elm_pec = elm;
	while (elm->next)
	{
		elm_pec = elm;
		elm = elm->next;
	}
	free(elm);
	elm_pec->next = NULL;
}

void del_top(elem_t** chain)
{
	if (*chain == NULL)
		return;

	elem_t* elm = *chain;
	free(*chain);
	*chain = elm->next;
}

void del_all(elem_t** chain)
{
	while (*chain)
	{
		del_top(chain);
	}
}

void read_chain(elem_t* chain)
{
	if (chain)
	{
		printf(" %i", chain->val);
		read_chain(chain->next);
	}
	else
	{
		printf("\n");
	}
}

void reverse_list(elem_t** chain)
{
	elem_t* elm = *chain;
	elem_t* res = NULL;
	elem_t* suiv = NULL;

	while (elm != NULL)
	{
		suiv = elm->next;
		elm->next = res;
		res = elm;
		elm = suiv;
			read_chain(res);
	}
	*chain = res;
}

int main()
{
	elem_t* chain = NULL;
	del_top(&chain);
	del_back(&chain);
	add_back(&chain, 2);
	add_top(&chain, 1);
	add_top(&chain, 0);
	add_back(&chain, 32);
	del_back(&chain);
	add_back(&chain, 3);
	del_top(&chain);
	add_back(&chain, 4);
	add_back(&chain, 5);

	read_chain(chain);

	reverse_list(&chain);

	read_chain(chain);

	del_all(&chain);

	return 0;
}
