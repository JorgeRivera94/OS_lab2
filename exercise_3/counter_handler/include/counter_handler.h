#ifndef COUNTER_HANDLER_H
#define COUNTER_HANDLER_H

/**
 * @brief Recieves the pids of infinite_counter programs and provides the user
 * with signals that can be sent to these programs.
 *
 * Receives the pids of infinite_counter programs as arguments and the count of
 * how many pids were provided. Shows an user interfase where the user can
 * select what action they can perform and to what infinite_counter program they
 * want to perform it to. Delivers the user selected signals to the processes.
 * If no pid is provided, the program informs the user and terminates.
 * @param pids Process IDs of infinite_counter programs
 * @param count A count of how many process IDs were passed into the program.
 */
void HandleCounters(pid_t* pids, int* count);

#endif