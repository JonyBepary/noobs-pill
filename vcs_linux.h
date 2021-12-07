// since it's a linux  system
// unistd provide linux os related function
// here used for getlogin(), and access() function
#include <unistd.h>

// For listing of C Compiler
// 1. gcc, 2. clang, 3. mcc

int c_compiler[4] = {0};
char c_compiler_name[4][4096];
int vscode_editor = 0;
int codeblocks = 0;
int wget_av = 0;
int vscode_editor_download_ok = 0;
int codeblocks__download_ok = 0;
int wget_av_download_ok = 0;

// OS_CODE set from check_oscode() function
// and store Distro name and version
char OS_CODE[4096];
char OS_NAME[4096];

// OS_CODE set from check_oscode() function
// format: /home/{user}/.config/Code/User/
char vscode_user_path[4096];
char config_ok_path[4096];

void check_oscode()
{
    FILE *fp;

    /* Open the  command for reading OSCODE. */
    // popen
    fp = popen("lsb_release -is", "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }

    // Read the output a line at a time - output it
    fgets(OS_CODE, sizeof(OS_CODE), fp);

    /* close */
    pclose(fp);
}
void set_vscode_user_path()
{
    strcpy(vscode_user_path, getenv("HOME"));
    strcat(vscode_user_path, "/.config/Code/User/");
}
void set_config_path()
{
    strcpy(config_ok_path, vscode_user_path);
    strcat(config_ok_path, "config.ok");
}

void clear_screen()
{

    system("clear");
}

void construct_download_list()
{
    FILE *fp;
    fp = fopen("./packages/DL_LIST_NIX", "a+");
    if (fp == NULL)
    {
        printf("Could not open file");
    }
    if (strstr(OS_CODE, "Debian") != NULL)
    {

        if (vscode_editor == 0)
            fprintf(fp, "https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64");
    }
    if (strstr(OS_CODE, "Manjaro") != NULL)
    {
        if (vscode_editor == 0)
            fprintf(fp, "https://code.visualstudio.com/sha/download?build=stable&os=linux-x64");

        if (codeblocks == 0)
            fprintf(fp, "https://sourceforge.net/projects/codeblocks/files/latest/download");
    }
    fclose(fp);
}

// Download file from text file via wget
// for windows and manual installation for linux
int Download_LIST_Through_wget()
{

    if (system("wget  --content-disposition --directory-prefix=./packages -i ./packagesDL_LIST_NIX") == 0)
    {
        printf("Download Success!!!\n");
        return 0;
    }
    else
    {
        return -1;
    }
}
// Execute shell to install vscode
// depending on distro.
void app_exec()
{
    printf("Installing required program\n");

    if (strstr(OS_CODE, "Debian") != NULL && vscode_editor == 0)
    {
        printf("============= DEBIAN ==============\n");
        printf("%s script executing", OS_CODE);
        system("sh ./script/debian.sh");

        vscode_editor = 1;
        if (codeblocks == 0)
        {
            system("sudo apt install codeblocks");
            codeblocks = 1;
        }
    }
    else if (strstr(OS_CODE, "Linuxmint") != NULL && vscode_editor == 0)
    {
        printf("============= Linux Mint ==============\n");
        printf("%s script executing", OS_CODE);
        system("sh ./script/debian.sh");
        vscode_editor = 1;
        if (codeblocks == 0)
        {
            system("sudo apt install codeblocks");
            codeblocks = 1;
        }
    }
    else if (strstr(OS_CODE, "Ubuntu") != NULL && vscode_editor == 0)
    {
        printf("============= Ubuntu ==============\n");
        printf("%s script executing", OS_CODE);
        system("sh ./script/debian.sh");
        vscode_editor = 1;
        if (codeblocks == 0)
        {
            system("sudo apt install codeblocks");
            codeblocks = 1;
        }
    }
    printf("All program installed\n");
}

void print_os_name()
{

    FILE *fp;
    /* Open the  command for reading OSCODE. */
    fp = popen("lsb_release -ds", "r");
    if (fp == NULL)
    {

        printf("\033[0;31m"); // Set the text to the color red
        printf("Failed to Get os Name\n");
        printf("\033[0;0m");
        exit(1);
    }
    fgets(OS_NAME, 4096, fp);

    pclose(fp);
}
// welcome banner
void printbaner()
{
    system("./packages/lolcat -r ./script/art ");
}
// task banner
void printbaner2()
{
    system("./packages/lolcat -r ./script/art2");
}
// last banner
void printbaner3()
{
    system("./packages/lolcat -r ./script/art3");
}
// check all compiler by running system command
void check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    if (system("gcc -v >/dev/null 2>/dev/null") == 0)
    {
        // storing compile rname
        strcpy(c_compiler_name[0], "Gnu C Compiler");
        // marking if a compiler is installed
        c_compiler[0] = 1;
    }
    if (system("clang -v >/dev/null 2>/dev/null") == 0)
    {
        // storing compile rname
        strcpy(c_compiler_name[1], "Clang C Compiler");
        // marking if a compiler is installed
        c_compiler[1] = 1;
    }
    if (system("mcc -v >/dev/null 2>/dev/null") == 0)
    {
        // storing compile rname
        strcpy(c_compiler_name[2], "Microsoft C Compiler");
        // marking if a compiler is installed
        c_compiler[2] = 1;
    }
    if (system("icc -v >/dev/null 2>/dev/null") == 0)
    {

        strcpy(c_compiler_name[3], "Intel C Compiler");
        c_compiler[3] = 1;
    }
}
void check_vscode()
{
    // >/dev/null 2>/dev/null out supressor
    // sob out /dev/null redirect
    if (system("code -v >/dev/null 2>/dev/null") == 0)
    {
        vscode_editor = 1;
    }
}

//
void check_codeblocks()
{

    /* Open the  command for reading strinu*/
    FILE *fp;
    char striny[4096];
    fp = popen("which codeblocks", "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }
    // Read the output a line at a time - output it
    fgets(striny, 4096, fp);
    puts(striny);
    if (strstr(striny, "codeblocks") != NULL)
    {
        codeblocks = 1;
    }
    printf("%d %s", codeblocks, striny);
    pclose(fp);
}

void check_wget()
{
    if (system("wget -V >/dev/null 2>/dev/null") == 0)
    {
        wget_av = 1;
    }
}
int check_config()
{

    if (access(config_ok_path, F_OK) == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
// Added Latest Download links for Windows Packages
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
    printf("R ");         //
    printf("\033[0;0m");  //
    printf("Refresh\t");  //
    printf("\033[0;33m"); //
    printf("E ");         //
    printf("\033[0;0m");  //
    printf("exit");       //
    printf("\n");         //

    return 1;
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
