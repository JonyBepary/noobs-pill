// -lurlmon
#include "vcs_lib.h"

int main(int argc, char const *argv[])
{

    calibrate();
    clear_screen();
    print_system_info();
    // show_command();
    // if (wget_av == 0)
    // {
    // }
    // // Download_LIST_Through_wget();
    check_oscode();
    construct_download_list();
    // printf("%s", OS_CODE);

    // Download_LIST_Through_wget();

    return 0;
}
