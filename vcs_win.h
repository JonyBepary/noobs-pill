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
int gcc_download_ok = 0;
int codeblocks_download_ok = 0;
int msys2_download_ok = 0;
int msys2 = 0;
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
    // Print >> OS Name: OS Version: Registered Owner: System Type:
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
    system("type .\\script\\art2w");
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
    printf("Downloading Wget Please Wait Patiently...\n");
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

int check_config()
{
    char path[4096];

    strcpy(path, getenv("APPDATA"));
    strcat(path, "\\Code\\User\\config.ok");
    if (isFileExists(path))
    {
        return 1;
    }
    else
    {
        return -1;
    }
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
// string literal

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
    msys2 = isFileExists("C:\\msys64\\msys2.exe");
}

void check_codeblocks()
{
    codeblocks = isFileExists("C:\\Program Files\\CodeBlocks\\codeblocks.exe");
}

void press_Y_to_continue_exe()
{
    char ch;
    while (1)
    {
        printf("Proceed with installation....\n");
        printf("If complete enter 'Y' to continue....\n");
        ch = getchar();
        if (ch == 'Y' || ch == 'y')
            break;
        system("cls");
    }
}
void press_Y_to_continue_script()
{
    char ch;
    while (1)
    {
        printf("1. Proceed with installation....\n");
        printf("2. Accept all the permission....\n");
        printf("3. No need to run the program....\n");
        printf("If complete enter 'Y' to continue....\n");
        ch = getchar();
        if (ch == 'Y' || ch == 'y')
            break;
        system("cls");
    }
}

void construct_download_list()
{
    FILE *fp;
    fp = fopen("./packages/DL_LIST_WIN", "a+");
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

int print_system_info()
{
    system("systeminfo | findstr /B /C:\"Registered Owner\" /C:\"OS Name\" /C:\"OS Version\" /C:\"System Type\"");
    return 0;
}
void Download_file_wget()
{
    // system(".\\wget.exe \"https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/x86_64-8.1.0-release-posix-seh-rt_v6-rev0.7z\" -O gcc-latest.7z");
    if (!isFileExists(".\\msys2-latest.exe\"") && !msys2)
        system(".\\wget.exe \"https://github.com/msys2/msys2-installer/releases/download/2021-11-30/msys2-x86_64-20211130.exe \" -O msys2-latest.exe");
    if (!isFileExists(".\\vscode-latest.exe") && !vscode_editor)
        system(".\\wget.exe \"https://code.visualstudio.com/sha/download?build=stable&os=win32-x64\" -O vscode-latest.exe");
    if (!isFileExists(".\\codeblocks-latest.exe") && !codeblocks)
        system(".\\wget.exe \"https://sourceforge.net/projects/codeblocks/files/Binaries/20.03/Windows/codeblocks-20.03mingw-setup.exe/download\" -O codeblocks-latest.exe");
}

void app_exec()
{
    printf("Do you download want to install codeblock?(y/N): ");
    char coand;
    scanf("%c", &command);
    if (!(coand == 'y' || coand == 'Y'))
    {
        codeblocks = 1;
    }

    Download_Wget();
    Download_file_wget();
    if (isFileExists(".\\msys2-latest.exe\"") && !msys2)
        msys2_download_ok = 1;
    if (isFileExists(".\\vscode-latest.exe") && !vscode_editor)
        vscode_editor_download_ok = 1;
    if (isFileExists(".\\codeblocks-latest.exe") && !codeblocks)
        codeblocks_download_ok = 1;

    if (vscode_editor_download_ok == 1 && !vscode_editor)
    {
        // run exe as admin
        // HANDLER, OPERATION, FILE LOCATION, PARAMETER.
        // FOLDER LOCATION,SHOWCOMMAND
        ShellExecute(NULL, "runas", "\".\\vscode-latest.exe \"", NULL, NULL, SW_SHOWNORMAL);
        press_Y_to_continue_exe();
    }

    if (codeblocks_download_ok == 1 && !codeblocks)
    {

        ShellExecute(NULL, "runas", "\".\\codeblocks-latest.exe \"", NULL, NULL, SW_SHOWNORMAL);
        check_codeblocks();
        press_Y_to_continue_exe();
    }

    if (msys2_download_ok == 1 && !msys2)
    {

        ShellExecute(NULL, "runas", "\".\\msys2-latest.exe \"", NULL, NULL, SW_SHOWNORMAL);
        press_Y_to_continue_exe();
        ShellExecute(NULL, "runas", "\".\\script\\make.bat \"", NULL, NULL, SW_SHOWNORMAL);
        press_Y_to_continue_script();
        ShellExecute(NULL, "runas", "\".\\script\\install.bat \"", NULL, NULL, SW_SHOWNORMAL);
        if (isFileExists("C:\\msys64\\mingw64\\bin\\gcc.exe"))
        {
            strcpy(c_compiler_name[0], "Gnu C Compiler");
            c_compiler[0] = 1;
        }
        press_Y_to_continue_script();
    }
}
void vscode_plugin_exec()
{
    printf("Installing required plugin for vscode\n");
    ShellExecute(NULL, "runas", "\".\\script\\plugin.bat \"", NULL, NULL, SW_SHOWNORMAL);
}
void config_exec()
{
    system("copy .\\packages\\settings.json  \"%APPDATA%\\Code\\User\\\"");
    system("type nul > \"%APPDATA%\\Code\\User\\config.ok\"");
    check_config();
}
