#ifndef INFINITE_COUNTER_H
#define INFINITE_COUNTER_H

/**
 * @brief Signal handler for the infinite counter.
 *
 * Resets the counter to 0 if SIGUSR1 signal is received. Changes counting
 * direction if SIGUSR2 signal is received.
 * @param signal Signal to be received by counter_handler
 */
void Handler(int signal);

/**
 * @brief A counter function that counts infinitely.
 *
 * Start counting in the positive direction from 0. Direction can be changed by
 * the Handler() function. Handler() function can also reset the counter to 0.
 * This funtion advances the counter in the current direction, then sleeps for
 * one second.
 */
void Count();

#endif