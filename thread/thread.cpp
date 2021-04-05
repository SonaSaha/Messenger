#include <iostream>
#include <pthread.h>

// the size of array
const int N = 100000000;
// the count of threads
const int M = 50;
int global_sum = 0;
int arr[N];

void * thread_func(void *);

int main()
{
//     for(int i = 0; i < N; ++i)
//     {
//         arr[i] = 1;
//     }

    pthread_t thread;
    for(int i = 0; i < M; ++i)
    {
        if(pthread_create(&thread, NULL, thread_func, (void*)&i) != 0)
        {
            std::cerr << "Can't create thread" << std::endl;
            return 1;
        }
    }
    
    std::cout << "Global sum = " << global_sum << std::endl;
    return 0;
}

void * thread_func(void * arg)
{
    // thread's number
   int index = *(int*)arg;

   for(int i = index*N/M; i < (index+1)*N/M; ++i)
   {
       global_sum += arr[i];
   }
   return 0;
}
