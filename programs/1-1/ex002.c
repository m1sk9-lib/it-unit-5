#include <stdio.h>
#include "../header/cgi.h"

const char* Prog = "ex002.cgi";

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

void MainCGI() {
    Head("CGI サンプル2 (動的フォーム生成)");
    printf(
        "<body>"
        "<form action=%s>"
        "ユーザー名: <input name=user size=20><br>"
        "パスワード: <input name=pass type=password size=20><br>"
        "メッセージ: <textarea name=msg rows=5 cols=40></textarea><br>"
        "送信ボタン: <input type=submit name=send value=\"送信する\"><br>"
        "</form>"
        "</body>"
        , Prog
    );
}

int main() {
    StartCGI();
    MainCGI();
    EndCGI();

    return 0;
}
