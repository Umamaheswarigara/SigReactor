#ifndef REACTOR_H
#define REACTOR_H

typedef struct
{
    int pipe_fd[2];
    int running;
} reactor_t;

int reactor_init(reactor_t *reactor);

int reactor_run(reactor_t *reactor);

void reactor_destroy(reactor_t *reactor);

int reactor_get_write_fd(reactor_t *reactor);

#endif

