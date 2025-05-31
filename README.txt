・WSL上で作るならGitHubのリポジトリを作るなら
_git remote add origin <url>：作成したリポジトリの<url>を更新

・git config pull.rebase true
_ローカルとリモートでコミット履歴が分岐している場合に，順番を，
 1. リモート上での変更
 2. WSL上での変更
 という順で統合する形に設定できる．

 ・git rm --cached <file>
 _<file>をバージョン管理から除外する