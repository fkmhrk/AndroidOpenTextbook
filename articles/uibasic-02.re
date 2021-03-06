= Graphical LayoutでViewに慣れよう

インターフェースのことを全般的に理解できたら、実際にそれらを作っていけるようにしなければなりません。

慣れてきたら自分でXMLを作成していくのですが、Androidにどんなパーツがあるのかがまだわからないうちは、いきなりXMLを書いていくのは少しむずかしいでしょう。
最初は、ドラッグアンドドロップで簡単にインターフェイスを作ることができる「Graphical Layout」を使って、Androidにはどのようなパーツがあるのかを見ていきます。

Androidアプリのユーザーインターフェイスは、プロジェクトのresフォルダ@<fn>{res}内のXMLファイルに記述していきます。

//footnote[res][Webサイトをつくるときは、HTMLとCSSを使ってユーザーインターフェイスを作っていきますが、Androidプロジェクトでは、それがXMLになります。]

== Graphical Layoutを使ってレイアウトを作ってみよう

この節では、ADTについている「Graphical Layout」を使ってレイアウトを完成させます。
細かい部分に気を取られず、Androidにはどのようなパーツがあり、どんなときに使うのかをざっと把握することが目的です。

=== 新規プロジェクトを作成しGraphical Layoutを表示する

ADTを起動し、新たにAndroidプロジェクトを作成します。

//image[new1][UIBasic1という新規プロジェクトを作成する]{
//}

//image[new2][Empty Activityを選択する]{
//}

そうすると、「MainActivity.java」「activity_main.xml」のふたつのファイルが開かれた状態になります。

上のタブで「activity_main.xml」を選び、下のタブが「Graphical Layout」になっていることを確認します（@<img>{001}）。

//image[001][Graphical Layout画面]{
//}

=== Graphical Layoutの見方を確認しよう

「Graphical Layout」を開くと、Androidの画面が大きくあらわれます。初期状態では、「Hello world!」というテキストがひとつ書かれているのがわかります。
他にもいくつかのパネルがあります。

(A)パレット：各パーツが入っている

(B)プレビュー：現在設定されているものがプレビューされます

(C)プレビューに関する端末の設定：プレビューを表示する端末の種類やバージョンを設定します

(D)パーツのレイアウトに関する設定：パーツのレイアウト設定をします

(E)プレビューに関するビューの設定：プレビューを表示する大きさを設定します

(F)アウトライン：配置したパーツがどういう階層構造になっているのかを設定します

(G)プロパティ：配置したパーツの詳細設定をしていきます

最初からすべてを把握するのは大変です。必要なものはそのときどきで説明していきますので、まずはパーツを配置してみることからはじめていきましょう。



=== パーツを配置してみよう

(A)のパレットから好きなパーツを選んで、(B)のプレビュー領域にドラッグアンドドロップをしてみましょう（@<img>{002}、@<img>{003}）。


//image[002][ドラッグ中]{
//}


//image[003][ドラッグ完了]{
//}

@<img>{002}、@<img>{003}では、(A)パレットの「Form Widgets」の中から「Button」を選んでドラッグアンドドロップし、Buttonを配置しました。

=== プロパティパネルを使ってカスタマイズする

先ほど配置したボタンは、「Button」と書かれています。
このままではいったい何のボタンかわかりませんので、文字を変更します。

プレビュー画面のボタンを選択した状態で、プロパティパネルを見ると、ボタンのプロパティがたくさん出ています（@<img>{004}）。


//image[004][ボタンのプロパティ]{
//}

この中にある「Text」という項目が、ボタンのラベルになっていますので、右の列の「Button」と書かれてあるところをダブルクリックし、「送信」に変えてみましょう（@<img>{005}）。
（Textは2ヶ所ありますが、どちらも同じです）


//image[005][ボタンのラベルを「送信」に変える]{
//}

そうすると、プレビューエリアのボタンのラベルも変わりました（@<img>{006}）。


//image[006][プレビューエリアのボタンのラベルも「送信」に変わる][scale=0.4]{
//}

このように、プロパティパネルにある値をいろいろと変えていくことで、パーツのカスタマイズができます。

=== Graphical Layoutのパーツ一覧

パーツは、パレットエリアにカテゴリごとにフォルダ分けされています。他のフォルダの中も見てみましょう（@<img>{007}～@<img>{014}）。
項目の名前を見てもいまいちピンとこない場合は、実際にプレビュー領域にドラッグアンドドロップをして、パーツを配置してみるとよいでしょう@<fn>{graphical-preview}。

//footnote[graphical-preview][Androidに慣れていない人は、どんどん配置をしてみて、どんなパーツがあるのかをしっかり確認しましょう。配置ができたら、実機でも確認してみましょう。実機に表示して指で触ってみることでわかることもたくさんあります]

中には、@<img>{switch-error}のように右下に小さな赤い「×」印が出るものがあります@<fn>{switch-error}。これは、Eclipseでのエラーを示していますので、このままではビルドできない状態になっています。
ここではあまり気にしなくてもいいので、どんなパーツかがなんとなくわかったら、エラーの出るパーツは削除して、どんどん先に進みましょう。

//footnote[switch-error][「×」印のところにマウスを合わせると、エラー内容がでてきます。このスイッチでは「View requires API level 14 (current min is 8): <switch>」というエラーが出ています。これはどういうことかというと、「スイッチ」というパーツはAPIレベル14以降で使用可能なのですが、このプロジェクトでは「APIレベル8以上」という設定になっている（新規プロジェクト作成時にそう指定していた）ので、エラーとなっているわけです]

//image[switch-error][エラーがある場合、小さなｘ印が表示される][scale=0.7]{
//}

//image[007][Form Widgets]{
//}

@<img>{007}はForm Widgetsです。テキストビューやボタン、トグルボタン（ON/OFFの切り替えをするもの）、チェックボックス、ラジオボタン、プログレスバー（円形にぐるぐる回るものや水平線状のもの）、シークバー（スライドバーともいう）、レーティングバーやスイッチなどが入っています。

//image[008][Text Fields]{
//}
@<img>{008}には、いろいろな形式のテキストフィールドが入っています。

//image[009][Layouts]{
//}

@<img>{009}は、レイアウトに関するパーツが入っていますが、「Graphical Layout」だけではちょっと使いづらいもの、もしくは使えないものですので、XMLといっしょに学習していきましょう。

//image[010][Composite]{
//}

@<img>{010}は、Compositeです。レイアウトに関するパーツが入っていますが、プログラムと連携しなければならないものが多いです。

//image[011][Images & Media]{
//}
@<img>{011}のImages & Mediaは、画像の表示や、音声や動画を表示するものが入っています。

//image[012][Time & Date]{
//}
@<img>{012}には、時計やカレンダー、また日時を指定するピッカーが入っています。

//image[013][Transitions]{
//}
@<img>{013}は、動きに関するパーツが入っていますが、プログラムと連携しなければならないものが多いです。

//image[014][Advanced]{
//}
@<img>{014}には、その他のパーツが入っていますが、「Graphical Layout」単独では動かないものばかりです。「ZoomControls」などはそのまま貼り付けることができますが、このままだと触っても何も起こりません。

パレットの中に入っているパーツは、配置するだけで、アプリ内でそのまま使えるものもあります。たとえば、テキストや画像などはパーツを表示するためですので、配置するだけで十分、役目を果たします。
しかし多くの場合はそうではなく、たとえば、テキストを入力してボタンを押したらどうなるか、というところをプログラミングしなければ、アプリとして成立しません。

配置するだけでも「レイアウトデザイン」として見せかけの画面はできあがりますが、アプリとして何か使えるようになるわけではないのです。

また、プログラミングによって意味付けをしなければ、レイアウトデザインとしても使えないパーツがたくさんあります。
「Composite」フォルダの中などはそういったものばかりです。

ここでは、ボタンを押しても何も起こらないような、見せかけだけのレイアウトを作っているんだ、ということを念頭にすすめていきましょう。

=== 実習1：Graphical Layoutを使ってインターフェイスを作成する
「Graphical Layout」を使って、次のインターフェイスを作成してみよう（@<img>{016}）。

//image[016][プロフィール画面][scale=0.2]{
//}

基本的には、あてはまるパーツをパレットからドラッグアンドドロップして配置することで、完成します。
ただし、いくつかの注意点があります。

==== 1. Text Fieldsの種類

このサンプルには、

 * お名前
 * Email
 * お電話番号
 * パスワード

の4つのテキストフィールドがあり、それぞれ「Text Fields」フォルダの中から選んで配置しますが、それぞれの「Input Type」が異なるものを選んでくるのが最適です（@<img>{017}、@<img>{018-021}）。


//image[017][E-mailでは、Input Typeの値が「textEmailAddress」になっている][scale=0.6]{
//}

//image[018-021][それぞれの特徴にあったText Fieldsを選ぶ]{
//}

こうすることで、Android OSが最適なIME（日本語入力）キーボード@<fn>{ime}を自動で表示することができます。

//footnote[ime][ここではSimejiを使っています。自動で表示させるためには、IME側にも制御する仕組みが必要となります]

たとえば、「Plain Text」のときは通常の日本語入力キーボードですが、「E-mail」にしたときは英数字キーボードで、しかも「@」も表示されているのがわかります@<fn>{edittextemail}。

//footnote[edittextemail][通常の英数字キーボードには、「@」は出ておらず、Shiftキーなどを押して切り替えると出てくる場合が多いが、Emailを入力するときには「@」が必須なため、あらかじめ表示されているほうが親切です]

また、電話番号は「Phone」にすれば数字キーボードになります。パスワードも、「Password」にすると、入力済みの文字が「●」で表示され、見えなくなるようになっています。

すべて同じ「Plain Text」にしても間違いではないのですが、もし自分が入力する立場になったときのことを考えると、メールアドレスを入力したいときに、日本語キーボードが表示されていたら、英数字キーボードに切り替えるのは手間ですよね。
Input Typeで表示させるキーボードを切り分けることによって、@<b>{よりユーザーが使いやすいインターフェイスを表現できる}のです。

==== 2. ラジオグループ

ラジオボタンは、ひとまとまりのグループにおいて、ひとつの項目しか選択できない状態でなければなりません。

そうするためには、「Form Widgets」の中の「RadioGroup」を選ぶべきです。「RadioButton」を選んでしまうと、それぞれが単独で選べることになってしまいますので、注意しましょう（@<img>{022}）。


//image[022][ラジオボタンをそれぞれ単独で選ぶことができる状態。こうならないようにしよう][scale=0.2]{
//}

==== 3. 「登録する」というボタン

普通にボタンを置いた状態では、ボタンの横幅が文字数に応じたものになってしまいます（@<img>{023}）。

//image[023][ボタンの横幅が、「登録する」の4文字分しかない][scale=0.2]{
//}

これでは、ボタンが小さくて押しづらくなってしまいます。
このボタンは、すべての項目を入力したあとの「入力完了」という意味も含めて押すものですので、横幅いっぱいに大きく配置しましょう。

まずはボタンを配置し、「登録する」というラベルに変更したあとに、マウスをうまく使って横幅いっぱいに伸ばします（@<img>{024}）。


//image[024][ボタンの横幅を調整する]{
//}

ここまで完成したら、次はXMLでインターフェイスを作っていきます。
