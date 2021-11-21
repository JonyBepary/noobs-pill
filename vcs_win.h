#include <windows.h>
#include <tchar.h>
#include <Urlmon.h>
#define vcs_osname 1

int main(int argc, char const *argv[])
{
    const char url[1000] = "https://eternallybored.org/misc/wget/1.21.2/64/wget.exe";
    const char *fdir = "wget.exe";
    if (S_OK == URLDownloadToFile(NULL, url, fdir, 0, NULL))
    {

        printf("Wget Downloaded!!!\n");
    }
    printf("%d\n", vcs_osname);

    return 0;
}
