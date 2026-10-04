#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <errno.h>

#include "reactor.h"
#include "event.h"
#include "signal_handler.h"

int reactor_init(reactor_t *reactor)
{
    if (pipe(reactor->pipe_fd) == -1)
    {
        perror("pipe");
        return -1;
    }

    reactor->running = 1;

    return 0;
}

int reactor_get_write_fd(reactor_t *reactor)
{
    return reactor->pipe_fd[1];
}

int reactor_run(reactor_t *reactor)
{
    struct pollfd pfd;
    unsigned char signal_byte;

    pfd.fd = reactor->pipe_fd[0];
    pfd.events = POLLIN;

    printf("SigReactor started...\n");
    printf("Event loop running...\n");
    printf("PID: %d\n\n", getpid());

    while (reactor->running)
    {
        int result = poll(&pfd, 1, -1);

        if (result == -1)
        {
            if (errno == EINTR)
            {
                continue;
            }

            perror("poll");
            return -1;
        }

        if (pfd.revents & POLLIN)
        {
            ssize_t n = read(
                reactor->pipe_fd[0],
                &signal_byte,
                1
            );

            if (n > 0)
            {
                event_type_t event;

                event = event_from_signal(signal_byte);

                if (event_process(event))
                {
                    reactor->running = 0;
                }
            }
        }
    }

    return 0;
}

void reactor_destroy(reactor_t *reactor)
{
    close(reactor->pipe_fd[0]);
    close(reactor->pipe_fd[1]);

    printf("\nSigReactor stopped.\n");
}


