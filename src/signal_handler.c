#include <signal.h>
#include <unistd.h>

static int signal_write_fd = -1;

static void signal_handler(int signal_number)
{
    unsigned char signal_byte = signal_number;

    if (signal_write_fd != -1)
    {
        write(signal_write_fd, &signal_byte, 1);
    }
}

int signal_handler_init(int write_fd)
{
    signal_write_fd = write_fd;

    return 0;
}

int signal_handler_register(int signal_number)
{
    struct sigaction action;

    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(signal_number, &action, NULL);
}

