#include <windows.h>
#include <tchar.h>
#include <Urlmon.h>
#define vcs_osname 1

void clear_screen(){
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
