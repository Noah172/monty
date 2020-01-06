#include <stdlib.h>
#include "monty.h"
gv b = {NULL, NULL, NULL};
/**
 * main - main function
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	unsigned int i = 0;
	ssize_t chars;
	size_t size = 0;
	stack_t *head = NULL;

	validation(argc, argv);

	while ((chars = getline(&b.buffer, &size, b.file)) != EOF)
	{
		i++;
		tokens(b.buffer, &head, i);
	}
	frees(head);
	exit(EXIT_SUCCESS);
}
/**
 * validation - valid arguments
 * @argcnt: number of arguments
 * @argvar: arguments
 *
 * Return: 0 success
 */
void validation(int argcnt, char **argvar)
{
	if (argcnt != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	b.file = fopen(argvar[1], "r");
	if (b.file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argvar[1]);
		exit(EXIT_FAILURE);
	}
}
/**
 * tokens - pharser to the buffer the comes from opcode-file.
 * @buffer: The buffer with the imformation.
 * @h: The stack
 * @i: Count of the line where the opcode is taken.
 * Return: Void.
 */
void tokens(char *buffer, stack_t **h, unsigned int i)
{
	char *str, *token;

	str = strtok(buffer, " \n\t");
	token = strtok(NULL, " \n\t");
	b.num = token;
	if (str && str[0] != '#')
		get_func(h, i, str);
}
/**
 * get_func - Funtion that look for the command..
 * @command: command.
 * @h: h.
 * @i: count.
 */
void get_func(stack_t **h, unsigned int i, char *command)
{
	int j = 0;
	instruction_t op_fn[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pop", func_pop},
		{"pint", func_pint},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{NULL, NULL}
	};

	while (op_fn[i].opcode)
	{
		if ((strcmp(op_fn[i].opcode, command)) == 0)
		{
			op_fn[i].f(h, i);
			break;
		}
		j++;
	}
	if (op_fn[i].f == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", i, command);
		frees((*h));
		exit(EXIT_FAILURE);
	}
}
/**
 * frees - Funtion that frees a list.
 * @h: Head of the list.
 */
void frees(stack_t *h)
{
	stack_t *head;

	while (h != NULL)
	{
		head = h->next;
		free(h);
		h = head;
	}
	fclose(b.file);
	free(b.buffer);
}
