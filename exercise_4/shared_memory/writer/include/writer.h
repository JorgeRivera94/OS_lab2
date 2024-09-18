#ifndef WRITER_H
#define WRITER_H

/**
 * @brief Separates a shared memory block and writes the numbers 1 to 1000000 to
 * it.
 *
 * Also takes the time it takes to write the 1000000 numbers to the shared
 * memory block. Detaches from the memory block when it finishes writing.
 */
void Write();

#endif  // WRITER_H