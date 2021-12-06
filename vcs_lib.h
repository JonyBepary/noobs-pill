// input output
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// if it's
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
int Manual_Download = 0;
void calibrate()
{
    check_oscode();
    print_os_name();
    // koyta compiler installed ache ta ache check kora
    check_compiler();
    // vscode installed ache kina ta check kora
    check_vscode();
    // dependt on SYSTEM VSCODE cofiguration path set kora
    set_vscode_user_path();
    // dependt on SYSTEM VSCODE cofig.ok path set kora.
    set_config_path();
    // codeblock installed ache kina ta check kora
    check_codeblocks();
    // Wget installed ache kina ta check kora
    check_wget();
}
// print sign in colour
void print_sign()
{
    printf("  ["); //
    // green color scii code
    printf("\033[0;32m"); //
    printf("✓");
    // normal color ascii code         //
    printf("\033[0;0m"); //
    printf("] ");        //
}

// print cross in colour
void print_cross()
{
    printf("  ["); //
    // red color scii code
    printf("\033[0;31m"); //
    printf("x");
    // normal color ascii code          //
    printf("\033[0;0m"); //
    printf("] ");        //
}
// print star in colour
void print_star()
{
    printf("  [");        //
    printf("\033[0;34m"); //
    printf("*");          //
    printf("\033[0;0m");  //
    printf("] ");         //
}
// print option menu with asci colouring
int print_option()
{
    printf("\n  ");       //
    printf("\033[0;33m"); // orange colouring
    printf("C ");         //
    printf("\033[0;0m");  // normal colouring
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
int print_system_info()
{
    // // Printing OS info
    print_star();
    printf("USER: %s\n", getlogin());
    print_star();
    printf("OS: %s", OS_NAME);

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
    char tmp[4096];
    strcpy(tmp, "cat ");
    strcat(tmp, vscode_user_path);
    strcat(tmp, "settings.json >/dev/null 2>/dev/null");

    printf("%s\n", tmp);
    if (system(tmp) == 0)
    {

        // backup existing code settings.json
        // cp -vf settings.json settings.json.ba
        char tmp2[4096];
        strcpy(tmp2, "cp -vf ");
        strcat(tmp2, vscode_user_path);
        strcat(tmp2, "settings.json ");
        strcat(tmp2, vscode_user_path);
        strcat(tmp2, "settings.json.bak");
        system(tmp2);
    }
    char cmd[4096];
    strcpy(cmd, "cp -vf ./packages/settings.json ");
    strcat(cmd, vscode_user_path);
    if (system(cmd) != 0)
    {
        printf("config exec failed");
    }
    else
    {
        char cmdon[4096];
        strcpy(cmdon, "sudo touch ");
        strcat(cmdon, vscode_user_path);
        strcat(cmdon, "config.ok");
        // puts(cmdon);
        system(cmdon);
    }
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
