#include <stdio.h>
#include "../header/cgi.h"

void MainCGI() {
    printf("<font color=red size=6>"
        "これは最初の CGI サンプルプログラムです．"
        "</font>"
    );
}

int main() {
    StartCGI();
    MainCGI();
    EndCGI();

    return 0;
}
