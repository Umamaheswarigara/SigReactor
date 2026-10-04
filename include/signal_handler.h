#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

int signal_handler_init(int write_fd);

int signal_handler_register(int signal_number);

#endif

