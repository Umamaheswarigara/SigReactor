#include <stdio.h>
#include <signal.h>

#include "reactor.h"
#include "signal_handler.h"

int main()
{
    reactor_t reactor;

    if (reactor_init(&reactor) == -1)
    {
        return 1;
    }

    signal_handler_init(
        reactor_get_write_fd(&reactor)
    );

    signal_handler_register(SIGINT);
    signal_handler_register(SIGTERM);
    signal_handler_register(SIGUSR1);

    reactor_run(&reactor);

    reactor_destroy(&reactor);

    return 0;
}

