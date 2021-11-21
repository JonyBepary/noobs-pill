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
#define OS_architechture 1
#elif __x86_64__
#define OS_architechture 2
#elif __aarch64__
#define OS_architechture 4
#elif __arm__
#define OS_architechture 3
// do arm stuff
#endif

int check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    return 1;
}
int check_vscode()
{
    // 1 for vscode is installed and 0 for vscode not installed
    return 1;
}
int check_os_architechture()
{
    // 0 for x86, 1 for x64 , 3 for AArch32
    // and 4 for AArch64
    return 1;
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
    printf("OS: %s\n", os_name);

    // Printing Compiler info
    char compiler_name[30];
    int compiler_code = check_compiler();
    if (compiler_code == 1)
    {
        strcpy(compiler_name, "gcc");
    }
    else if (compiler_code == 2)
    {
        strcpy(compiler_name, "clang");
    }
    else if (compiler_code == 3)
    {
        strcpy(compiler_name, "mcc");
    }
    else if (compiler_code == 0)
    {
        strcpy(compiler_name, "Unable to be detected");
    }
    printf("Compiler: %s\n", compiler_name);
    return 0;
}
