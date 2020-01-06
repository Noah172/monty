#include "monty.h"
/**
 * func_push - function that insert node in the stack
 * @h: head
 * @c: line number
 * Return: nothing
 */
void func_push(stack_t **h, unsigned int c)
{
	stack_t *neo;

	(void) c;

	neo = malloc(sizeof(stack_t));
	if (neo == NULL)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		frees(neo);
		exit(EXIT_FAILURE);
	}

	if (!b.num && b.num != 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", c);
		frees((*h));
		free(neo);
		exit(EXIT_FAILURE);
	}

	if (b.num)
	{
		neo->n = atoi(b.num);
		neo->next = *h;
		neo->prev = NULL;
		if (*h)
			(*h)->prev = neo;
		*h = neo;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", c);
		frees((*h));
		free(neo);
		exit(EXIT_FAILURE);
	}
}
/**
 * func_pall - function that prints all the elements of a dlist
 * @h : const - list_t
 * @c: count.
 * Return: the number of notes.
 */
void func_pall(stack_t **h, unsigned int c)
{
	stack_t *tmp;
	(void) c;

	tmp = *h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * func_pint - function that prints the last element of a list
 * @h : const - list_t
 * @c: count.
 * Return: the number of notes.
 */
void func_pint(stack_t **h, unsigned int c)
{
	stack_t *tmp;

	tmp = *h;
	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", c);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
/**
 * func_pop - Funtionces of the opcode pop.
 * @h: Stack.
 * @c: count of the line where the opcode is taken.
 */
void func_pop(stack_t **h, unsigned int c)
{
	stack_t *tmp;

	tmp = *h;
	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", c);
		exit(EXIT_FAILURE);
	}
	*h = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
/**
 * func_swap - Funtion that swap the last values.
 * @h: Stack.
 * @c: count of the line where the opcode is taken.
 */
void func_swap(stack_t **h, unsigned int c)
{
	stack_t *twist;
	int i = 0, tmp;

	twist = (*h);

	while (twist)
	{
		i++;
		twist = twist->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		exit(EXIT_FAILURE);
	}

	tmp = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = tmp;
}
