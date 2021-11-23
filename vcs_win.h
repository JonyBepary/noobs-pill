#include <windows.h>
#include <tchar.h>
#include <Urlmon.h>
#define vcs_osname 1

// For listing of C Compiler
// 1. gcc
// 2. clang
// 3. mcc
int c_compiler[4] = {0};
char c_compiler_name[4][30];

int vscode_editor = 0;
int wget_av = 0;
char OS_CODE[4096] = "Windows";

void clear_screen()
{

    system("cls");
}

int Download_Wget()
{
    const char *url = "https://eternallybored.org/misc/wget/1.21.2/64/wget.exe";
    const char *fdir = "wget.exe";
    if (S_OK == URLDownloadToFile(NULL, url, fdir, 0, NULL))
    {

        printf("Wget Downloaded!!!\n");
    }
    return 0;
}

int Download_LIST_Through_wget()
{

    if (system(".\\wget.exe --content-disposition -i .\\DL_LIST_WIN") == 0)
    {
        printf("Download Success!!!\n");
        /* code */
    }
}

void check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    if (system("gcc -v > nul") == 0)
    {

        strcpy(c_compiler_name[0], "Gnu C Compiler");
        c_compiler[0] = 1;
    }
    if (system("clang -v > nul") == 0)
    {

        strcpy(c_compiler_name[1], "clang");
        c_compiler[1] = 1;
    }
    if (system("mcc -v > nul") == 0)
    {

        strcpy(c_compiler_name[2], "Microsoft C Compiler");
        c_compiler[2] = 1;
    }
    if (system("icc -v > nul") == 0)
    {

        strcpy(c_compiler_name[3], "Intel C Compiler");
        c_compiler[3] = 1;
    }
}
void check_vscode()
{
    if (system("code -v > nul") == 0)
    {
        vscode_editor = 1;
    }
}
void check_wget()
{
    if (system("wget -V > nul") == 0)
    {
        wget_av = 1;
    }
}

int check_config()
{
    return -1;
}
