#include <stdio.h>
#include <stdlib.h>
#include "../header/cgi.h"

const char* Prog = "ex004.cgi";

void Style() {
    printf(
        "<style>\n"
        " BODY { font-size: 9pt; }\n"
        " #ct { background: navy; color: white; }\n"
        " #cn { background: white; color: navy; }\n"
        "</style>\n"
    );
}

void Head(const char* title) {
    printf(
        "<head>\n"
        "<title>%s</title>\n"
        "<meta http-equiv=\"content-type\" content=\"text/html\" charset=\"UTF-8\">\n"
        , title
    );
    Style();
    printf(
        "</head>\n"
    );
}

char* Gets(char* buf) {
    char* p = getenv("CONTENT_LENGTH");
    int n = p && *p ? atoi(p) : 0;

    if (!buf) {
        return NULL;
    }

    if (!n) {
        buf[0] = 0;
        return NULL;
    }

    n = fread(buf, sizeof(char), n, stdin);
    buf[n] = 0;
    return buf;
}

void MainCGI() {
    char buf[4096];

    Head("CGI サンプル4 (POSTデータ送信)");

    if (Gets(buf)) {
        printf("送信データ=[%s]<br>\n", buf);
    } else {
        printf(
            "<body>"
            "<form action=%s method=post>"
            "ユーザー名: <input name=user size=20><br>"
            "パスワード: <input name=pass type=password size=20><br>"
            "メッセージ: <textarea name=msg rows=5 cols=40>(メッセージ)</textarea><br>"
            "送信ボタン: <input type=submit name=send value=\"送信する\"><br>"
            "</form>"
            "</body>"
            , Prog
        );
    }

}

int main() {
    StartCGI();
    MainCGI();
    EndCGI();

    return 0;
}
