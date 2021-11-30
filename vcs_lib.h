#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

// #include <sys/stat.h>
#include <stdbool.h>
// #include <ncurses.h>

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
    check_codeblocks();
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
    printf("] ");         //
}
void print_star()
{
    printf("  [");        //
    printf("\033[0;34m"); //
    printf("*");          //
    printf("\033[0;0m");  //
    printf("] ");         //
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

int check_exec()
{
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
        printf("Codeblocks IDE\n");
    }
    char cmd_command;
    printf("\033[0;33m"); //
    printf("\n\t\t\tE "); //
    printf("\033[0;0m");  //
    printf("exit");       //
    printf("\n");

    printf("  : "); //
    getchar();
    scanf("%c", &cmd_command);
    printf("\n"); //
    if (cmd_command == 'e' || cmd_command == 'E')
    {
        return -1;
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
    print_star();

    printf("USER: %s\n", getlogin());
    print_star();
    printf("OS: ");
    print_os_name();
    // Printing Compiler info
    char compiler_name[30];
    // sys_architechture: 1 for x86, 2 for x64 , 3 for AArch32 and 4 for AArch64
    print_star();
    printf("Arch: ");
    switch (sys_architechture)
    {
    case 1:
        printf("x86\n");
        break;
    case 2:
        printf("x64\n");
        break;
    case 3:
        printf("Arm32\n");
        break;
    case 4:
        printf("Arm64\n");
        break;
    default:
        printf("Undefined\n");
        break;
    }
    if (system("timeout 0.5 ping -c1 -s1 www.google.com >/dev/null 2>/dev/null"))
    {
        print_cross();
        printf("There is no internet connection\n");
    }
    else
    {
        print_sign();
        printf("Internet connection is Working\n");
    }

    return 0;
    // print_sign();
    // print_cross();

    return 0;
}
void check_component()
{

    initscr();
    curs_set(0);
    start_color();

    printw("\n");

    printw("=======================================\n");

    printw("              Task list                \n");

    printw("=======================================\n");

    if (c_compiler[0] == 0)
    {
        // init_pair(1, COLOR_, -1);

        printw("  [x] GNU C Compiler not installed!\n");
    }
    // printing  all installed c compiler
    for (size_t i = 0; i < 4; i++)
    {
        if (c_compiler[i] == 1)
        {

            printw("  [*] %s Installed\n", c_compiler_name[i]);
        }
    }

    if (vscode_editor == 1)
    {

        printw("  [*] Visual studio code installed\n");
    }
    else
    {

        printw("  [x] Visual studio code not installed!\n");
    }

    if (check_config() == -1)
    {

        printw("  [x] System is not configured!\n");
        /* code */
    }
    else
    {

        printw("  [*] System configured!\n");
    }
    printw("\n");   //
    printw("  E "); //
    printw("exit"); //
    printw("\n");   //

    refresh();
    getch();
    endwin(); /* End curses mode		  */
}
int check_command()
{
    command = getchar();
    // getchar();
    // scanf("%c", &command);
    // printf("~%c\n", command);
    if (command == 'C' || command == 'c')
    {
        // clear_screen();
        // check_exec();
        check_component();
    }
    if (command == 'I' || command == 'i')
    {
        if (strcmp(OS_CODE, "Debian"))
        {
            Download_LIST_Through_wget();
            app_exec();
            vscode_plugin_exec();
            config_exec();
        }
    }
    if (command == 'S' || command == 's')
    {
        printf("Still in Devlopment");
    }
    if (command == 'E' || command == 'e')
    {
        return -1;
    }
    return 0;
}

void vscode_plugin_exec()
{
    printf("Installing required plugin for vscode\n");
    system("code --install-extension formulahendry.code-runner");
    system("code --install-extension streetsidesoftware.code-spell-checker");
    system("code --install-extension ms-vscode.cpptools");
    system("code --install-extension CoenraadS.bracket-pair-colorizer-2");
    system("code --install-extension Equinusocio.vsc-community-material-theme");
    system("code --install-extension vscode-icons-team.vscode-icons");
}
void config_exec()
{
    printf("Configuring vscode\n");
}

int start_ui()
{
    clear_screen();
    // PRINTING ./ART THROUGH LOLCAT COLORIZER
    printbaner();
    // info like user, os, architecture, and internet
    print_system_info();
    print_option();
    return 0;
}
