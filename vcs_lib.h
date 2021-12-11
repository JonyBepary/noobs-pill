// input output
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// if it's
#ifdef _WIN32
#include "vcs_win.h"
#endif
#ifdef __linux__
#include "vcs_linux.h"
#endif

char command;
int Manual_Download = 0;

void calibrate()
{
    check_oscode();
    print_os_name();
    // koyta compiler installed ache ta ache check kora
    check_compiler();
    // vscode installed ache kina ta check kora
    check_vscode();
    // depent on SYSTEM VSCODE cofiguration path set kora
    set_vscode_user_path();
    // depent on SYSTEM VSCODE cofig.ok path set kora.
    set_config_path();
    // codeblock installed ache kina ta check kora
    check_codeblocks();
    // Wget installed ache kina ta check kora
    check_wget();
}
// print sign in colour
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
    else
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

void check_component()
{

    clear_screen();
    printbaner3();
    if (c_compiler[0] == 0)
    {
        // init_pair(1, COLOR_, -1);

        print_cross();
        printf("  GNU C Compiler not installed!\n");
    }
    // printing  all installed c compiler
    for (size_t i = 0; i < 4; i++)
    {
        if (c_compiler[i] == 1)
        {
            print_sign();
            printf(" %s Installed\n", c_compiler_name[i]);
        }
    }

    if (vscode_editor == 1)
    {
        print_sign();
        printf(" Visual studio code installed\n");
    }
    else
    {

        print_cross();
        printf(" Visual studio code not installed!\n");
    }
    if (codeblocks == 1)
    {
        print_sign();
        printf(" Codeblocks IDE installed!\n");
    }
    else
    {

        print_cross();
        printf(" Codeblocks IDE not installed!\n");
    }

    if (check_config() == -1)
    {

        print_cross();
        printf(" System is not configured!\n");
        /* code */
    }
    else
    {
        print_sign();
        printf(" System configured!\n");
    }
    printf("\n");   //
    printf("  E "); //
    printf("exit"); //
    printf("\n");   //

    getchar();
    getchar();
    /* End curses mode		  */
}
int check_command()
{
    command = getchar();
    // getchar();
    // scanf("%c", &command);
    // printf("~%c\n", command);
    if (command == 'C' || command == 'c')
    {
        clear_screen();
        // check_exec();
        check_component();
    }
    if (command == 'I' || command == 'i')
    {
        if (Manual_Download == 1)
        {
            Download_LIST_Through_wget();
            app_exec();
            if (check_config() != -1)
            {
                printf("System has already been Configured\n");
            }
            else
            {
                vscode_plugin_exec();
                config_exec();
                /* code */
            }
        }

        else
        {
            app_exec();
            if (check_config() != -1)
            {
                printf("System has already been Configured\n");
            }
            else
            {
                vscode_plugin_exec();
                config_exec();
                /* code */
            }
        }
    }
    if (command == 'R' || command == 'r')
    {
        calibrate();
    }
    if (command == 'E' || command == 'e')
    {
        return -1;
    }
    return 0;
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
