#!/bin/bash

set -e

if [ -d /var/www/html/cgi-bin ]; then
    find /var/www/html/cgi-bin -type f -name "*.c" | while read -r cfile; do
        if [[ "$cfile" == */header/cgi.c ]]; then
            continue
        fi
        dir=$(dirname "$cfile")
        base=$(basename "$cfile" .c)
        gcc "$cfile" /var/www/html/cgi-bin/header/cgi.c -I/var/www/html/cgi-bin/header -o "$dir/$base.cgi"
        chmod 755 "$dir/$base.cgi"
    done
fi

apachectl -D FOREGROUND
