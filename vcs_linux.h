// unistd provide linux os related function
// here used for getlogin() function
#include <unistd.h>

// since it's a linux  system
// vcs_osname has been set 2
#define vcs_osname 2

// For listing of C Compiler
// 1. gcc, 2. clang, 3. mcc

int c_compiler[4] = {0};
char c_compiler_name[4][30];
int vscode_editor = 0;
int codeblocks = 0;
int wget_av = 0;
int vscode_editor_download_ok = 0;
int codeblocks__download_ok = 0;
int wget_av_download_ok = 0;

// OS_CODE set from check_oscode() function
// and store Distro name and version
char OS_CODE[4096];

// OS_CODE set from check_oscode() function
char vscode_user_path[4096];

void check_oscode()
{
    FILE *fp;

    /* Open the  command for reading OSCODE. */
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

void clear_screen()
{
    system("clear");
}

void construct_download_list()
{
    FILE *fp;
    fp = fopen("./DL_LIST_NIX", "a+");
    if (fp == NULL)
    {
        printf("Could not open file");
    }
    if (strcmp(OS_CODE, "Debian"))
    {

        if (vscode_editor == 0)
            fprintf(fp, "https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64");
    }
    if (strcmp(OS_CODE, "Manjaro"))
    {
        if (vscode_editor == 0)
            fprintf(fp, "https://code.visualstudio.com/sha/download?build=stable&os=linux-x64");

        if (codeblocks == 0)
            fprintf(fp, "https://sourceforge.net/projects/codeblocks/files/latest/download");
    }
    fclose(fp);
}

int Download_LIST_Through_wget()
{

    if (system("wget  --content-disposition --directory-prefix=./packages -i ./DL_LIST_NIX") == 0)
    {
        printf("Download Success!!!\n");
        return 0;
    }
    else
    {
        return -1;
    }
}

void app_exec()
{
    printf("Installing required program\n");

    if (strcmp(OS_CODE, "Debian") && vscode_editor == 0)
    {
        system("sudo sh ./script/debian.sh");
        vscode_editor = 1;
    }
    if (strcmp(OS_CODE, "Debian") && codeblocks == 0)
    {
        system("sudo apt install codeblocks");
        codeblocks = 1;
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
    char OS_INFO[4096];

    fgets(OS_INFO, sizeof(OS_INFO), fp);
    printf("%s", OS_INFO);
    fclose(fp);
}

void printbaner()
{
    system("./lolcat -r ./script/art");
}

void printbaner2()
{
    system("./lolcat -r ./script/art2");
}
void printbaner3()
{
    system("./lolcat -r ./script/art3");
}
void check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    if (system("gcc -v >/dev/null 2>/dev/null") == 0)
    {

        strcpy(c_compiler_name[0], "Gnu C Compiler");
        c_compiler[0] = 1;
    }
    if (system("clang -v >/dev/null 2>/dev/null") == 0)
    {

        strcpy(c_compiler_name[1], "Clang C Compiler");
        c_compiler[1] = 1;
    }
    if (system("mcc -v >/dev/null 2>/dev/null") == 0)
    {

        strcpy(c_compiler_name[2], "Microsoft C Compiler");
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
    if (system("code -v >/dev/null 2>/dev/null") == 0)
    {
        vscode_editor = 1;
    }
}
void check_codeblocks()
{
    FILE *fp;
    /* Open the  command for reading OSCODE. */
    fp = popen("which /bin/codeblocks", "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }
    // Read the output a line at a time - output it
    fgets(OS_CODE, sizeof(OS_CODE), fp);
    /* close */
    if (strcmp(OS_CODE, "/bin/codeblocks"))
    {
        codeblocks = 1;
    }
    fclose(fp);
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
    // if (access(fname, F_OK) == 0)
    // {
    //     // file exists
    // }
    // else
    // {
    //     // file doesn't exist
    // }
    return -1;
}
// Added Latest Download links for Windows Packages
