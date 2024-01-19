#include "monty.h"

/**
 * cmd_init - initializes cmd object
 * Return: pointer to cmd object (cmd_t *)
 */
cmd_t *cmd_init()
{
    cmd_t *cmd = malloc(sizeof(cmd_t));

    cmd->file = NULL;
    cmd->line = NULL;
    cmd->opcode = NULL;
    cmd->value = NULL;
    cmd->line_number = 0;

    return (cmd);
}
