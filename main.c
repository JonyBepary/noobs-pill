// -lurlmon
#include "vcs_lib.h"

int main()
{

    // system e various program like compiler vscode, codeblodck
    // install ache kina check kore acorrding to the result
    // variable gula mark kore.
    calibrate();
    // marked variable gula theke  FILE/IO use kore
    // downlond link construct kore
    construct_download_list();
    // landing page
    while (1)
    {
        start_ui();
        if (check_command() == -1)
            break;
        /* code */
    }
    clear_screen();
    printbaner2();

    return 0;
}
