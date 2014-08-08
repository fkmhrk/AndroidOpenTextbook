= センサー（番外編）

//lead{
本章ではセンサーの番外編として、実際のセンサーをArduinoという
プロトタイピングツールを使って体験し、ハードウェアについても理解を
深めてみようという特別編です。
//}

== Arduinoとは

Arduino@<fn>{arduino}は今までハードルの高かったハードウェアの開発を、
非常に簡単に行えるようにしたツールです。ちょっとしたセンサーなどの
ハードウェアを制御するのに使われ、プロトタイピングツールと呼ばれています。
開発用のIDE環境が用意されており、C言語ライクな記述でプログラムを書くことが
でき、これを@<b>{スケッチ}と呼びます。

//footnote[arduino][@<href>{http://www.arduino.cc/}]

=== Arduinoの種類

Arduinoは「商標」のようなもので、現在多くの種類が発売されています。
例としてはArduinoという機能は同じですが、

 * 使用可能なピン数を増やしたもの
 * サイズをコンパクトにしたもの
 * ロボット向けのもの
 * イーサネットに対応したもの

 などがあります。次の図はArduinoのページから一部を切り取ったものです。

//image[boards][Arduinoの種類]{
//}

=== Arduino Uno

これは一番スタンダードなArduino Unoです。Arduinoに関する書籍やネット
の情報はたいていこのArduino Unoを前提としていることが多いです。本章も
Arduino Unoをベースとして進めていきます。
//image[uno][Arduino uno]{
//}

Unoの仕様は

 * AVRマイコン 16MHz
 * 5v電源・5v入出力
 * USBでの書き込み・デバッグ
 * デジタル I/O 14本
 * アナログ Input 6本

Unoのピン配置を書き出してみます。
//image[pin][ピン配置]{
//}

0番と1番はシリアル用に使われています。基板に"~"の印が付いているピンは
PWM(Pulse Wave Modulation)と言い、実際にはアナログ出力っぽいこと
が可能です。Arduinoはこの各ピンにセンサーなどを接続し、マイコンのプ
ログラムを動作させることでセンサーの情報を取得したり、外部のLEDを点灯
させたり、アクチェータを動かしたりできます。

===[column] デジタルとアナログ
一般的にデジタルは数値化された整数値で表され、
アナログは数値化されていない値となります。Arduinoではデジタルと
アナログがありますが、デジタルは0 or 1ですが、アナログは0〜1023
の値を取ります。アナログといっても内部ではデジタル化された整数値と
して扱われます。これはアナログ入力をA/Dコンバータで処理している
ためです。

===[/column]

== Arduino IDEのインストール

Arduino IDEは、Windows, MacOS, Linuxに対応しています。IDEの
ダウンロードは@<href>{http://arduino.cc/en/Main/Software}から行います。

== デバイスドライバのインストール

MacOSとLinuxではドライバは必要ありませんが、WindowsではUSBシリアル
ドライバが必要です。Windows用ドライバは@<href>{http://www.ftdichip.com/Drivers/VCP.htm}
からダウンロードしてインストールします。ドライバをインストールしたら、
ArduinoとPCをUSBケーブルで接続します。コントロールパネルが次の
ようになれば、Arduinoがシリアルポートとして正常に認識しています。この場合は
"COM11"としてArduinoが見えるようになっています。

//image[driver][ドライバーのインストール]{
//}

== Arduinoで"Hello World"

それではArduinoで"Hello World"を実行してみましょう。とは言ってもArduinoは
表示機能を標準では持っていませんので、どこにも表示できません。

Arduinoのようなハードウェアで言う"Hello World"は"Lチカ"と言う動作が
それに当たります。"Lチカ"とは"LEDチカチカ"の略です。

Arduino IDEを起動してみましょう。起動したら、次のように"スケッチの例>01.Basics>Blink"
を選択すると、サンプルのスケッチが開きます。

//image[blink][Blinkを開く]{
//}

開いたスケッチに日本語の注釈を付けておきます。

//list[blink][Lチカのスケッチ]{
// 13番ピンはほとんどのArduinoボードでLEDに接続されています
int led = 13;

// setupルーチンはリセット後に１度だけ実行されます
void setup() {
  // LEDピンを初期化し、出力とします
  pinMode(led, OUTPUT);
}

// loopルーチンは、基本的に終了せず、永久にループします
void loop() {
  digitalWrite(led, HIGH);   // LEDを点灯します（HIGH は5v出力）
  delay(1000);               // 1000msのウェイト
  digitalWrite(led, LOW);    // LEDを消灯します（LOWは 0v出力）
  delay(1000);               // 1000msのウェイト
}
//}

スケッチのポイントは

 * setupルーチンが実行される（一度だけ。ここで各ピンなどの初期化を行う）
 * loopルーチンはsetup終了後に実行され、永久ループとなる

スケッチの内容としては

 * setupで13番のピンをOUTPUT（出力方向）に設定
 * loop内で、digitalWriteで13番に割り当てたledにHIGHとLOWを1秒置きに出力する

それではこのスケッチを実行する前に、デバイスとの接続設定をしておきます。

//image[select-uno][Arduino Unoの選択]{
//}

"ツール>マイコンボード>Arduino Uno"を選択します。

//image[serial][シリアルポートの選択]{
//}

"ツール>シリアルポート>XXXX"を選択します。Windowsの場合は"COMxx"になります。

デバイスの設定ができたら、このスケッチをArduinoに書き込んで実行します。
Arduinoは書き込みが成功すると、自動的に実行を開始します。

//image[exe][スケッチの書き込み]{
//}

左から2番目のボタンを押すと、コンパイルと書き込みが行われます。一番左のボタンは
コンパイルのみ行います。エラーが無ければコンパイルの後、ボードへの書き込みが行われます。

//image[done][スケッチの書き込み完了]{
//}

書き込みが完了したらArduinoを見てみましょう。Arduinoは自動的にスケッチを
実行します。見るのは次の図の丸で囲まれた付近です。

//image[l][Lチカ]{
//}

"L"と書かれたオレンジ色のLEDがゆっくりと点滅しているのが確認できるはずです。
そしてこの点滅の間隔は約1秒となっています。これがArduinoの"Hello World"です。

== LEDを光らせる

実際のLEDデバイスを使ってみましょう。ブレッドボードとジャンパー
を使って回路を組んでいきます。ブレッドボードは内部で次のような接続がされていて、
表面にジャンパーを差すだけで回路が作れるようになっています。端の方は横方向、
中の方は縦方向に繋がっています。これは端の方には電源やGND（グランド）を接続
することが多いためです。

//image[bread][ブレッドボード結線図]{
//}

ジャンパー線を使って、9番ピンとGNDにブレッドボードで回路を作成します。
ここで注意しなければならないことがあります。LEDには極性（＋とー）があります。
２つのコードのうち、@<b>{長いほうが＋、短いほうがーです}。間違えて接続すると壊れる
ことがあります。

//image[ledview][LEDの極性]{

//}

//image[led][LEDの配線図]{
//}

配線ができたら、さっきのスケッチを修正します。今回は同じようにLEDを9番ピンに接続したので
次のようになります。

//list[blink2][Lチカのスケッチ]{
// 9番ピンにLEDを接続した
int led = 9;

// setupルーチンはリセット後に１度だけ実行されます
void setup() {
  // LEDピンを初期化し、出力とします
  pinMode(led, OUTPUT);
}

// loopルーチンは、基本的に終了せず、永久にループします
void loop() {
  digitalWrite(led, HIGH);   // LEDを点灯します（HIGH は5v出力）
  delay(1000);               // 1000msのウェイト
  digitalWrite(led, LOW);    // LEDを消灯します（LOWは 0v出力）
  delay(1000);               // 1000msのウェイト
}
//}

先のLチカと同じように、LEDが点滅するはずです。

==== LEDの輝度を変化させてみる

今度はLEDの明るさを変化させてみましょう。"~"はPWMというアナログ出力っぽいことができる。
と書きました。Arduinoはアナログの場合、"0 〜 1023"の値を使えます。今のスケッチではHIGH = 1023
ということになります。ただしアナログ出力の場合はanalogWrite関数を使います。

例として、先のスケッチを次のよう書き換えると完全に消灯せず淡く光が残るようになります。

//list[blink3][loopルーチン改良]{
// loopルーチンは、基本的に終了せず、永久にループします
void loop() {
  analoglWrite(led, 1023);   // LEDを点灯します（1023 は最大出力）
  delay(1000);               // 1000msのウェイト
  digitalWrite(led, 50);     // LEDを消灯します（50は 0v出力よりも大きい）
  delay(1000);               // 1000msのウェイト
}
//}

==== @<b>{実は落とし穴が}

さてここまで簡単にLEDを点灯させることができました。ところが、
簡単になっているのは実はカラクリがあります。それはLEDが@<b>{抵抗入り}
だということです@<fn>{led_spec}。

本来のLEDであれば5vの電圧を掛けると電流が流れすぎて壊れます。
これは豆電球をコンセントに挿すと壊れるのと同じようなものです。
壊れないようにするために、電流制限抵抗を入れる必要があり、
抵抗入りLEDというのは内部に予め抵抗が入っているお手軽LEDなのです。
一般的にLEDを使う場合は実際には抵抗値を計算して、回路上に入れるということを覚えておいて下さい。

//image[led-regist][LEDと抵抗の関係]{
//}

//footnote[led_spec][@<href>{http://akizukidenshi.com/catalog/g/gI-06246/}]

===[column] 抵抗の求め方
5vで緑色LEDを点灯させる場合を例にします。よくある緑色LEDでは

 1. VF : 2.0v (IF = 20mAにおける標準値)というカタログ値が書いてあります
 2. 電圧が5vなので、抵抗に掛かる電圧は 5v - 2v = 3vです
 3. 流す電流は0.02AですのでV = IRの公式（覚えてますか？）から、3v = 0.02 × R(抵抗)
 4. よってR = 150Ωとなります
//image[led-calc][LEDの抵抗計算]{
//}
===[/column]

== 照度センサーで明るさを測る

それではいよいよセンサーを使ってみます。今回使うのは照度センサーとして使われる
Cdsセルというデバイスを使います。これは明るさによってCdsセルの抵抗値が変化します。
明るいところでは抵抗が小さくなり、暗いところでは抵抗が大きくなります。

電気回路としての回路図はこんな感じです。

//image[cds-regist][明るさを測る回路図]{
//}

Cdsセルの抵抗は明るい所では小さくなるので、明るい時は測定値は電圧が大きくなります。
暗いところではCdsセルの抵抗が大きくなるので、測定値の電圧は小さくなります。

作成する回路は次のようになります。このCdsセルには極性はありませんので、
どちらに接続しても問題ありません。

//image[cds][明るさを測る配線図]{
//}

それではスケッチを書きましょう。

//list[cds_sketch][setupルーチン]{
#define CDS A0 // Cdsセルの入力ピン
#define LED 13 // LEDピン

void setup() {
  // デバッグシリアルの初期化
  Serial.begin(9600);

  // Cdsセルを入力に設定
  pinMode(CDS, INPUT);
  // LEDを出力に設定
  pinMode(LED, OUTPUT);
}
//}

まずは初期化ですが、CDS(A0)を入力に設定し、LED(13)を出力に設定しています。
Serial.begin(9600)は接続しているUSBをシリアルで使用し、デバッグ表示を行う
ための初期化です。

//list[cds_sketch2][loopルーチン]{
void loop() {
  // Cdsセルからの入力
  int light = analogRead(CDS);
  // デバッグ表示
  Serial.println(light);

  // 明るさによってLEDの点灯を変化させる
  if (light > 600) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }

  delay(1000);
}
//}

lightにアナログ入力でA0からデータを読み込み、それをデバッグシリアルを通して表示
します。取得した値（アナログ値は0〜1023）に応じて、LEDを点灯もしくは消灯にして
います。

Cdsセルの部分を明るくしたり、暗くしたりしてみてください。13番ピンのオレンジ色の
LEDが点灯したり消灯したりします。暗くなると明かりが点く、街灯などは主にこの原理を
利用しています。

=== デバッグシリアルの表示

今回の例では、実際に取得した値を見てみないと、どう制御していいかわかりません。
そのため、デバッグシリアルを使っています。デバッグシリアルの表示はスケッチの
右上のボタンをクリックすることで開きます（ただしボードへの書き込み中は開きません）。

//image[debug_btn][デバッグシリアルを開く]{
//}

//image[debug][デバッグシリアルの表示]{
//}

== 3軸加速度センサーで加速度を測る

最後は加速度センサーの値を取得してみましょう。今回使用するKXR94-2050というデバイス
は３軸の加速度（x軸、y軸、z軸）を測ることができます。それぞれの出力がアナログ出力
で出てくるので、それをArduinoのアナログ入力で受けます。さてこのデバイスは8ピンの構成
になっているので、今までよりも複雑そうですが、仕様書どおりに接続すれば難しくありません。

//image[axis-pin][加速度センサーのピン説明]{
//}

このピンの説明から、1番・2番ピンは電源（5v）、3番・5番ピンはGND、6番から8番が出力
ということになっていることがわかります。

この仕様書を参考に配線図を作成すると次のようになります。x、y、zの各入力は
A0〜A2のアナログ入力に割り当てました。

//image[axis][加速度を測る配線図]{
//}

3軸の方向も仕様書に上面図と側面図が書いてあります。

//image[axis-dir][各軸の方向]{
//}

加速度は、1G = 9.8kgfですね。しかし1GだからといってArduinoで9.8が得られるわけではありません。
Arduinoのアナログ入力は0〜1023の間の整数値しか取りません。そして入出力の最大値は5vですから、
1023 = 5vという計算になります。

実際にArduinoで取得できる値も、仕様書から計算することができます。

//image[axis-offset][1G当たりの出力値]{
//}

仕様書を見ると、1Gあたりのセンサーの出力値は

 * 電源電圧(5v) / 5 = 1v

また5vの入力の場合、1v当たりの入出力の振幅は
 
 * 1024 / 5 = 204

そして0Gの時のオフセット値は電源電圧5vの半分の2.5vとなっています。
つまり0Gの時のArduinoへの入力値は1023の半分の511ということになります。

この値を頭に入れておきながら、スケッチを書いていきます。

//list[3xis_sketch][setupルーチン]{
// 3axis sensor

#define X_AXIS A0 // x軸
#define Y_AXIS A1 // y軸
#define Z_AXIS A2 // z軸

// 1G = 1v
// 0G = 2.5v
// offset = 1023/2

int axis[3]; // 加速度センサー値
char string[64]; // 出力文字列

void setup() {
  Serial.begin(9600);
  
  // 加速度センサーのピンを入力に設定
  pinMode(X_AXIS, INPUT);
  pinMode(Y_AXIS, INPUT);
  pinMode(Z_AXIS, INPUT);
}
//}

A0〜A2を3軸の入力として初期化しています。センサーの値を格納するint型の
配列要素と、デバッグシリアルに出力するための文字列を宣言しておきます。

loopルーチンでは、入力で取得した加速度の値を先のオフセットで補正します。

//list[3axis_sketch2][loopルーチン]{
void loop() {
  // 入力値を取得し、0Gのオフセットを引いておく
  axis[0] = analogRead(X_AXIS) - 511;
  axis[1] = analogRead(Y_AXIS) - 511;
  axis[2] = analogRead(Z_AXIS) - 511;

  sprintf(string, "x= %d, y= %d, z= %d", axis[0], axis[1], axis[2]);
  Serial.println(string);

  delay(500);
}
//}

通常の状態ではz軸方向は1Gが掛かるので、z軸の値は204前後になるはずです。
実際に動作させてみたあと、センサーを色々な方向に傾けてみると値が変化する
のがわかります。

== まとめ

センサー特別編として、実際のセンサーのハードウェアを使った測定を行いました。
センサーはAndroidだけではなく、M2M(Machinne to Machine)やIoT(Internet of Things)
と言われる分野でも非常に重要なデバイスです。Arduinoはそのセンサーを比較的
簡単に扱えるツールとして注目されています。Arduinoにはイーサネットに接続で
きる種類もあるので、今回取得したようなセンサーデータをクラウドにアップロード
することも簡単にできます。Arduinoやハードウェアといった分野についても学習
することで、より広い範囲で応用力を発揮することができるようになります。

===[column] パーツリスト
 * 秋月電子通商
 ** Arduino Uno Rev3（@<href>{http://akizukidenshi.com/catalog/g/gM-07385/}）
 ** 抵抗内蔵５ｍｍ黄緑色LED（５v用）（１０個入）（@<href>{http://akizukidenshi.com/catalog/g/gI-06246/}）
 ** Cdsセル　５ｍｍタイプ（@<href>{http://akizukidenshi.com/catalog/g/gI-00110/}）
 ** ３軸加速度センサモジュール　KXR94-2050（@<href>{http://akizukidenshi.com/catalog/g/gM-05153/}）
 ** ブレッドボード　BB-801（@<href>{http://akizukidenshi.com/catalog/g/gP-05294/}）
 ** ブレッドボード・ジャンパーコード（オス－オス）セット（@<href>{http://akizukidenshi.com/catalog/g/gC-05159/}）
===[/column]