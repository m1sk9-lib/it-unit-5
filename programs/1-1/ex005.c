#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/cgi.h"

const char* Prog = "ex005.cgi";

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

void Decode(char* dec, const char* buf) {
    char* p = (char *) buf;
    int code;

    if (!buf || !dec) {
        return;
    }

    while(*p) {
        switch (*p) {
        case '%':
            p++;
            sscanf(p, "%02x", &code);
            *dec = (unsigned char)code;
            dec++;
            p += 2;
            break;
        case '+':
            *dec = ' ';
            dec++;
            p++;
            break;
        default:
            *dec = *p;
            dec++;
            p++;
            break;
        }
    }
    *dec = 0;
}

void GetData(const char* buf) {
    char* tmp = strdup(buf);
    char* p;
    char dec[1024];

    printf("受信データ=[%s]<br><hr size=0>\n", buf);

    if ((p = strtok(tmp, "&")) != NULL) {
        do {
            char* name = p;
            char* value = strchr(p, '=');

            if (value) {
                *value = 0;
                value++;
                Decode(dec, value);
                printf("name=[%s], value=[%s], decoded=[%s]<br>\n", name, value, dec);
            }
        } while ((p = strtok(NULL, "&")) != NULL);
    }
}

void Form() {
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

void MainCGI() {
    char buf[4096];

    Head("CGI サンプル5 (POSTデータ送信)");

    if (Gets(buf)) {
        GetData(buf);
    } else {
        Form();
    }

}

int main() {
    StartCGI();
    MainCGI();
    EndCGI();

    return 0;
}
