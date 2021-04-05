#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

void LogError(const char * msg);

int main()
{
    int a = 7;
    pid_t child_id = fork();

    // fake
    // child_id = -1;
    //  errno = 5;

    if(-1 == child_id)
    {
        LogError("Can't fork : ");
        return 1;
    }
    
    if(child_id == 0)
    {
        a = 8;
        int c = 9;
        std::cout << getpid() << "c=" << c << "\t&c" << &c << std::endl;
    } 
    else 
    {
        int d = 10;
        std::cout << getpid() << "d=" << d << "\t&d" << &d << std::endl;
    }
    std::cout << getpid() <<  "a=" << a << "\t&a=" << &a << std::endl;

    return 0;
}


void LogError(const char * msg)
{
    std::cerr << time(0) << " : " << getpid() << " : " << "Error : " << msg << strerror(errno) << std::endl;
}
