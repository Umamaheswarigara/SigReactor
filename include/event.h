#ifndef EVENT_H
#define EVENT_H

typedef enum
{
    EVENT_NONE,
    EVENT_SIGINT,
    EVENT_SIGTERM,
    EVENT_SIGUSR1
} event_type_t;

event_type_t event_from_signal(int signal_number);

const char *event_name(event_type_t event);

int event_process(event_type_t event);

#endif

