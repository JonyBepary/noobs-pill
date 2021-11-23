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

char command;
void calibrate()
{
    check_compiler();
    check_vscode();
    check_wget();
}
void print_sign()
{
    printf("  [");        //
    printf("\033[0;32m"); //
    printf("✓");          //
    printf("\033[0;0m");  //
    printf("] ");         //
}
void print_cross()
{
    printf("  [");        //
    printf("\033[0;31m"); //
    printf("x");          //
    printf("\033[0;0m");  //
    printf("]");          //
}
int print_option()
{
    printf("\n  ");       //
    printf("\033[0;33m"); //
    printf("C ");         //
    printf("\033[0;0m");  //
    printf("Check\t");    //
    printf("\033[0;33m"); //
    printf("I ");         //
    printf("\033[0;0m");  //
    printf("Install\t");  //
    printf("\033[0;33m"); //
    printf("S ");         //
    printf("\033[0;0m");  //
    printf("Set\t");      //
    printf("\033[0;33m"); //
    printf("E ");         //
    printf("\033[0;0m");  //
    printf("exit");       //
    printf("\n");         //

    return 1;
}

void check_command()
{
    scanf("%c", &command);
    // printf("~%c\n", command);
    if (command == 'C' || command == 'c')
    {
        clear_screen();
        check_exec();
    }
}

void check_exec()
{
    printf("=====================================\n");
    printf("            Task list               \n");
    printf("=====================================\n");
    if (c_compiler[0] == 0)
    {
        print_cross();
        printf("%s\n", c_compiler_name[0]);
    }
    if (vscode_editor == 0)
    {
        print_cross();
        printf("Visual studio code\n");
    }
    if (codeblocks == 0)
    {
        print_cross();
        printf("Codeblock IDE\n");
    }
    if (codeblocks == 0)
    {
        print_cross();
        printf("Codeblock IDE\n");
    }
}

int print_system_info()
{
    // printf("==========================================\n");
    // // printf("             NOOBS PILL                       \n");
    // printf("             NOOBS ");
    // printf("\033[0;35m"); // Set the text to the color red
    // printf("PILL                       \n");
    // printf("\033[0;0m"); // Set the text to the color red

    // printf("==========================================\n");
    // // Printing OS info
    printbaner();
    print_sign();
    print_os_name();
    // Printing Compiler info
    char compiler_name[30];
    // sys_architechture: 1 for x86, 2 for x64 , 3 for AArch32 and 4 for AArch64

    print_sign();
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

    if (c_compiler[0] == 0)
    {
        print_cross();
        printf("GNU C Compiler not installed!\n");
    }
    // printing  all installed c compiler
    for (size_t i = 0; i < 4; i++)
    {
        if (c_compiler[i] == 1)
        {
            print_sign();
            printf("%s Installed\n", c_compiler_name[i]);
        }
    }

    // print_sign();
    if (vscode_editor == 1)
    {
        print_sign();
        printf("Visual studio code installed\n");
    }
    else
    {
        print_cross();
        printf("Visual studio code not installed!\n");
    }

    if (check_config() == -1)
    {
        print_cross();
        printf("System is not configured!\n");
        /* code */
    }
    else
    {
        print_sign();
        printf("System configured!\n");
    }

    // print_cross();
    // print_sign();
    return 0;
}
