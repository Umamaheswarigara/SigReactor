#include <stdio.h>
#include "event.h"

int main()
{
    printf("Testing SigReactor Event Module\n");

    printf("SIGINT -> %s\n", event_name(EVENT_SIGINT));
    printf("SIGTERM -> %s\n", event_name(EVENT_SIGTERM));
    printf("SIGUSR1 -> %s\n", event_name(EVENT_SIGUSR1));

    printf("Event module test completed.\n");

    return 0;
}

