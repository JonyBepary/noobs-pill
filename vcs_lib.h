#include <stdio.h>
#include <string.h>

int vcs_osname()
{
    // not detected = 0, windows = 1, linux = 2;
    return 2;
}

int check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    return 1;
}

int Strat_print()

{
    // Printing OS info
    char os_name[20];
    int os_code = vcs_osname();
    if (os_code == 1)
    {
        strcpy(os_name, "Windows");
    }
    else if (os_code == 2)
    {
        strcpy(os_name, "Linux");
    }
    else if (os_code == 0)
    {
        strcpy(os_name, "Unable to detected");
    }
    printf("OS: %s\n", os_name);
    // Printing Compiler info

    return 0;
}
