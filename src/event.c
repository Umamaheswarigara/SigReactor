#include <stdio.h>
#include "event.h"

event_type_t event_from_signal(int signal_number)
{
    switch (signal_number)
    {
        case 2:
            return EVENT_SIGINT;

        case 15:
            return EVENT_SIGTERM;

        case 10:
            return EVENT_SIGUSR1;

        default:
            return EVENT_NONE;
    }
}

const char *event_name(event_type_t event)
{
    switch (event)
    {
        case EVENT_SIGINT:
            return "SIGINT";

        case EVENT_SIGTERM:
            return "SIGTERM";

        case EVENT_SIGUSR1:
            return "SIGUSR1";

        default:
            return "UNKNOWN";
    }
}

int event_process(event_type_t event)
{
    printf("Event received: %s\n", event_name(event));

    if (event == EVENT_SIGINT)
    {
        printf("SIGINT handled safely.\n");
    }
    else if (event == EVENT_SIGUSR1)
    {
        printf("User event processed.\n");
    }
    else if (event == EVENT_SIGTERM)
    {
        printf("Termination event received.\n");
        return 1;
    }

    return 0;
}

