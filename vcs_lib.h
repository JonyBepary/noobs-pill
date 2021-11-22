#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <stdbool.h>

#ifdef _WIN32
#include "vcs_win.h"
#endif

#ifdef __linux__
#include "vcs_linux.h"
#endif

#ifdef __i386__
#define sys_architechture 1
#elif __x86_64__
#define sys_architechture 2
#elif __aarch64__
#define sys_architechture 4
#elif __arm__
#define sys_architechture 3
// do arm stuff
#endif

void calibrate()
{
    check_compiler();
    check_vscode();
}

int User_command()
{
    return 1;
}
int Start_print()
{
    // Printing OS info
    char os_name[20];
    // int vcs_osname = vcs_osname;
    if (vcs_osname == 1)
    {
        strcpy(os_name, "Windows");
    }
    else if (vcs_osname == 2)
    {
        strcpy(os_name, "Linux");
    }
    else if (vcs_osname == 0)
    {
        strcpy(os_name, "Unable to detected");
    }
    print_os_name();
    // Printing Compiler info
    char compiler_name[30];
    // sys_architechture: 1 for x86, 2 for x64 , 3 for AArch32
    //  and 4 for AArch64
    printf("System Archtitechture: ");
    switch (sys_architechture)
    {
    case 1:
        printf("x86\n");
        break;
    case 2:
        printf("x64\n");
        break;
    case 3:
        printf("AArch32\n");
        break;
    case 4:
        printf("AArch64\n");
        break;
    default:
        printf("Undefined\n");
        break;
    }
    check_compiler();
    for (size_t i = 0; i < 4; i++)
    {
        if (c_compiler[i] == 1)
        {
            printf("%s Installed\n", c_compiler_name[i]);
        }
    }
    if (vscode_editor == 1)
    {
        printf("Visual studio code installed\n");
    }
    if (check_config() == -1)
    {
        printf("Config not found!\n");
        /* code */
    }

    return 0;
}
