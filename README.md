# it-unit-5

講義の中では XAMPP を使用していたが，macOS 版の XAMPP は Apple Silicon 対応版を銘打って公開しているにも関わらず，実際には Rosetta 2 を介さないと動作しない．

幸い PHP や MariaDB は本講義では使用しないため，ここでは Docker で Apache Web Server を簡易的に構築して実験に使用する．

## 使用方法

1. `programs/` 配下に CGI プログラムを配置する．
2. `docker-compose up` を実行する．
3. ブラウザで `http://localhost:8080/cgi-bin/1-1/<file-name>` にアクセスする．

CGI プログラム側を修正したりした場合は `docker compose up --build --force-recreate` を実行する

本来は `--build` だけでいいが，イメージに変更がないからか CGI プログラムをコンパイルしてくれないため `--force-recreate` でイメージとコンテナごと再作成する．
