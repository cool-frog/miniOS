/*
 * user/user_program.c  —  miniOS
 *
 * A sample user-space program.  This is representative of
 * the code that runs in the user space and calls the
 * library (wrapper) functions to access miniOS functionality.
 *
 * Run via:  make run-demo
 */

#include <string.h>
#include "syscall_wrappers.h"

void *processBody(void *pokemonName) {
    lib_lockinit();
    for (int i = 0; i < 25; i++)
    {
        lib_yield();
        lib_lock();
        lib_puts("I choose you, ");
        lib_puts((char *)pokemonName);
        lib_puts("!\n");
        lib_unlock();
        lib_sleep(250);
    }
    lib_done();
}

int main(void)
{
    lib_puts("=== miniOS user-space demo ===\n\n");

    lib_spawn(processBody, "Pikachu");
    lib_spawn(processBody, "Charizard");
    lib_process();


    lib_puts("\nAll done. Exiting.\n");
    lib_exit(0);
}
