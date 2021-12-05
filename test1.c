#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

    system("sh ./script/echo.sh");
    system("sh ./script/debian.sh");
    return 0;
}
