#include "monty.h"
/**
 * func_add - adds the top two elements of the stack
 * @h: head
 * @c: line number
 */
void func_add(stack_t **h, unsigned int c)
{
	stack_t *addition;
	int i = 0;

	addition = (*h);

	while (addition)
	{
		i++;
		addition = addition->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", c);
		exit(EXIT_FAILURE);
	}
	addition = (*h)->next;
	(*h)->next->n += (*h)->n;
	free(*h);
	addition->prev = NULL;
	(*h) = addition;
}
/**
 *func_nop - this does nothing
 *@h: the head
 *@c: counter
 */
void func_nop(stack_t **h, unsigned int c)
{
	(void) h;
	(void) c;
}

void func_sub(stack_t **h, unsigned int c)
{
	stack_t *subs;
	int i = 0;

	subs = (*h);

	while (subs)
	{
		i++;
		subs = subs->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		exit(EXIT_FAILURE);
	}
	subs = (*h)->next;
	(*h)->next->n -= (*h)->n;
	free(*h);
	subs->prev = NULL;
	(*h) = subs;
}
