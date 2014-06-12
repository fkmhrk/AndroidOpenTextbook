# Android Open Textbook
Android Open Textbook は「Androidの教科書」をつくるオープンソースプロジェクトです。GitHubと書籍制作ツールRe:VIEWを利用して、開発者が欲しい技術情報を集約する試みです。

## マイルストーン
成果はオープンソースプロジェクトとしてGitHub上で公開していくほか、2014年夏のコミックマーケットで書籍として頒布予定です（７月前後が初期版のマイルストーンです）。また本プロジェクトの成果の一部はアプリ開発人材育成プログラム「Tech Institute」で利用され、フィードバックを得ます。

## 関連する外部のプレスリリース
サムスン電子、早稲田大学EXセンタ、角川アスキー総研がアプリ開発人材育成プログラム「Tech Institute」の募集を開始！[http://mobileascii.jp/elem/000/000/102/102939/](http://mobileascii.jp/elem/000/000/102/102939/)

## 連絡窓口
[@mhidaka](https://twitter.com/mhidaka)　（コラボレーターに個別に連絡すると混乱するので代表窓口として）

## コラボレーター
（編集中かつ募集中）

## ビルド方法
本節では、Android Open Textbookを各種環境でビルドする方法を解説します。

### Windows向け
TODO

### Mac向け
#### npmをインストールする
Android Open Textbookのビルド等の操作は[grunt](http://gruntjs.com/)を用いて行います。[grunt](http://gruntjs.com/)はnpmが必要です。


```
brew install npm
npm install -g grunt-cli
```

#### Re:VIEWをインストールする
Re:VIEWはGithub上のソースをcloneしてパスを通せば利用できます。


```
git clone https://github.com/kmuto/review.git
export PATH=$PATH:/path/to/review
```

#### セットアップ
Android Open Textbookをクローンし、必要なライブラリ等をインストールします。


```
git clone https://github.com/TechBooster/AndroidOpenTextbook.git
cd AndroidOpenTextbook.git
npm install
```

#### Readmeをビルドする
まずはREADME.mdをビルドしてみましょう。README.mdは実はREADME.reから生成しています。以下のコマンドでREADME.mdの生成が行えます。


```
grunt readme
```

本ページ(README.md)を更新する場合は、README.reを編集し、上記コマンドでREADME.mdを生成して下さい。

#### 原稿をビルドし、HTMLを出力する
以下のコマンドを実行すると、articlesディレクトリ内の原稿をコンパイルしてHTMLファイルを出力します。


```
grunt html
```

#### タスクの種類を確認する
gruntのタスクのバリエーションはGruntfile.jsに定義されています。以下のコマンドで、gruntでどのような事ができるか確認できます。


```
grunt --help
```
