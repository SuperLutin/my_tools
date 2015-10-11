#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int val;
	struct node* minus;
	struct node* plus;
} node_t;


void add_val(node_t** arbre, int val)
{
	node_t* tmp_node;
	node_t* tmp_tree = *arbre;

	node_t* new_node = malloc(sizeof(node_t));
	new_node->val = val;
	new_node->minus = NULL;
	new_node->plus = NULL;

	if (tmp_tree == NULL)
	{
		*arbre = new_node;
		return;
	}

	while (tmp_tree != NULL)
	{
		tmp_node = tmp_tree;
		if (tmp_tree->val > val)
		{
			tmp_tree = tmp_tree->minus;
			if (tmp_tree == NULL)
			{
				tmp_node->minus = new_node;
			}
		}
		else if (tmp_tree->val < val)
		{
			tmp_tree = tmp_tree->plus;
			if (tmp_tree == NULL)
			{
				tmp_node->plus = new_node;
			}
		}
		else // tmp_tree->val == val
		{
			free(new_node);
			return;
		}
	}
}

void is_node(node_t* arbre, int val)
{
	if (arbre == NULL)
	{
		return;
	}

	if (arbre->val == val)
	{
		printf("%i existe.\n", val);
	}

	if (arbre->val > val)
	{
		if (arbre->minus != NULL)
		{
			is_node(arbre->minus, val);
		}
		else
		{
			printf("%i n'existe pas.\n", val);
		}
	}

	if (arbre->val < val)
	{
		if (arbre->plus != NULL)
		{
			is_node(arbre->plus, val);
		}
		else
		{
			printf("%i n'existe pas.\n", val);
		}
	}
}

void del_tree(node_t* arbre)
{
	if (arbre == NULL)
	{
		return;
	}

	if (arbre->minus != NULL)
	{
		del_tree(arbre->minus);
	}
	if (arbre->plus != NULL)
	{
		del_tree(arbre->plus);
	}

	free(arbre);
}

void read_tree(node_t* arbre)
{
	if (arbre == NULL)
	{
		return;
	}

	if (arbre->minus != NULL)
	{
		read_tree(arbre->minus);
	}

	printf(" %i", arbre->val);

	if (arbre->plus != NULL)
	{
		read_tree(arbre->plus);
	}
}

int main()
{
	node_t* arbre = NULL;

	add_val(&arbre, 6);
	add_val(&arbre, 5);
	add_val(&arbre, 5);
	add_val(&arbre, 8);
	add_val(&arbre, 1);
	add_val(&arbre, 9);
	add_val(&arbre, 7);
	add_val(&arbre, 4);
	add_val(&arbre, 3);
	add_val(&arbre, 2);

	is_node(arbre, 6);
	is_node(arbre, 16);
	is_node(arbre, -6);
	is_node(arbre, 5);

	read_tree(arbre);
	printf("\n");

	del_tree(arbre);

	return 0;
}

