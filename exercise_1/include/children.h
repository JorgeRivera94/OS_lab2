#ifndef CHILDREN_H
#define CHILDREN_H

/**
 * @brief Creates six child processes that call the greetings program.
 *
 * The current process creates three child processes and each child creates two
 * additional children. These children call the greetings program to print a
 * message and their process ID to the terminal. Each process waits for all its
 * child processes to terminate before continuing.
 */
void CreateChildren();

#endif