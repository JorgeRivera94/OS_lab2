#ifndef TERMINAL_H
#define TERMINAL_H

/**
 * @brief Takes a tokenized string of user inputed commands and arguments and
 * executes them.
 *
 * Iterates through the arguments and passes them into child processes that use
 * execvp() to execute them.
 * @param commands A string tokenized by spaces of user given commands and
 * arguments.
 */
void HandleCommands(char *commands);

#endif