#include <stdio.h>
#include "cgi.h"

void StartCGI() {
    printf("Content-Type: text/html; charset=UTF-8\n\n"
        "<html>\n"
    );
}

void EndCGI() {
    printf("</html>\n");
}
