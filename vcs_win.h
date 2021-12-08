// -lurlmon

#include <windows.h>

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
    strcpy(OS_CODE, "Windows");
    system("systeminfo | findstr /B /C:\"Registered Owner\" /C:\"OS Name\" /C:\"OS Version\" /C:\"System Type\" > psi");
}
void print_os_name()
{
    system("type .\\psi");
}

void set_vscode_user_path()
{
    strcpy(vscode_user_path, "%APPDATA%\\Code\\User\\");
}
void set_config_path()
{
    strcpy(config_ok_path, "%APPDATA%\\Code\\User\\config.ok");
}
void printbaner()
{
    system("type .\\script\\artw");
}

void printbaner2()
{
    system("type .\\script\\art2");
}

void printbaner3()
{
    system("type .\\script\\art3");
}

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

    if (system(".\\wget.exe --content-disposition -i .\\packages\\DL_LIST_WIN") == 0)
    {
        printf("Download Success!!!\n");
    }
}

void check_compiler()
{
    // no_comiler = 0, gcc = 1, clang = 2, mcc = 3
    if (system("gcc -v >nul 2>nul") == 0)
    {

        strcpy(c_compiler_name[0], "Gnu C Compiler");
        c_compiler[0] = 1;
    }
    if (system("clang -v >nul 2>nul") == 0)
    {

        strcpy(c_compiler_name[1], "clang");
        c_compiler[1] = 1;
    }
    if (system("mcc -v >nul 2>nul") == 0)
    {

        strcpy(c_compiler_name[2], "Microsoft C Compiler");
        c_compiler[2] = 1;
    }
    if (system("icc -v >nul 2>nul") == 0)
    {

        strcpy(c_compiler_name[3], "Intel C Compiler");
        c_compiler[3] = 1;
    }
}
void check_vscode()
{
    if (system("code -v >nul 2>nul") == 0)
    {
        vscode_editor = 1;
    }
}

void check_wget()
{
    if (system("wget -V >nul 2>nul") == 0)
    {
        wget_av = 1;
    }
}

int check_config()
{
    return -1;
}

void print_sign()
{
    printf("  ["); //
    // green color scii code
    printf("\033[0;32m"); //
    printf("*");
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

int isFileExists(TCHAR *PATH)
{

    WIN32_FIND_DATA FindFileData;
    HANDLE handle = FindFirstFile(PATH, &FindFileData);
    int found = handle != INVALID_HANDLE_VALUE;
    if (found)
    {
        FindClose(handle);
    }
    return found;
}

void check_codeblocks()
{

    codeblocks = isFileExists("C:\\Program Files\\CodeBlocks\\codeblocks.exe");
}

int print_system_info()
{
    system("systeminfo | findstr /B /C:\"Registered Owner\" /C:\"OS Name\" /C:\"OS Version\" /C:\"System Type\"");
    return 0;
}

void app_exec()
{
    Download_Wget();
}
