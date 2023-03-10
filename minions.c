// import libraries 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <string.h>

void* minion_task(void* key)
{
    int k = *(int*)key;
    fprintf(stdout, "Hello!, I am minion %d!\n", k);
    free(key); // free memory allocated for index
    return NULL;
}

void* overlord_task(void* nothing)
{
    fprintf(stdout, "Hello Minions! I am the Overlord!\n");
    return NULL;
}

int main(int argc, char* argv[])
{
    // declare my variables
    pthread_t minion_threads[1000];
    pthread_attr_t thread_attr;
    int num_minions;

    // first test
    if (argc < 2 || !isdigit(*argv[1]) || strcmp(argv[0], "./minions") != 0)
    {
        fprintf(stdout, "Usage: %s <num_minions>, no alphanumeric input.\n", argv[0]);
        return 0;
    }
    num_minions = atoi(argv[1]);

    // spawn minion threads
    for (int i = 0; i < num_minions; i++)
    {
        int* index = malloc(sizeof(int));
        *index = i;
        pthread_attr_init(&thread_attr);
        int rc = pthread_create(&minion_threads[i], &thread_attr, minion_task, index);
        // second test
        if (rc)
        {
            fprintf(stderr, "pthread creation failed, error %d\n", rc);
        }
        pthread_attr_destroy(&thread_attr);
    }

    // wait for all minion threads to finish
    for (int i = 0; i < num_minions; i++)
    {
        pthread_join(minion_threads[i], NULL);
    }

    // spawn overlord thread
    pthread_attr_init(&thread_attr);
    pthread_create(&minion_threads[num_minions], &thread_attr, overlord_task, NULL);
    pthread_attr_destroy(&thread_attr);

    // wait for the overlord thread to finish
    pthread_join(minion_threads[num_minions], NULL);

    return 0;
}
