
#define vcs_osname 2
#include <unistd.h>

void clear_screen()
{
    system("clear");
}

int Download_LIST_Through_wget()
{

    if (system("wget --content-disposition -i ./DL_LIST_NIX") == 0)
    {
        printf("Download Success!!!\n");
        return 0;
    }
    else
    {

        return -1;
    }
}

// Added Latest Download links for Windows Packages
