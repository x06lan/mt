# 郭老題目
# 1
:::spoiler
某一學生修國文Chinese、計算機概論CS、計算機程式設計PD三科，使用者輸入名字（一個string）、學號（int）、三科成績(int)。
(1) 計算學生總成績、平均。
(2) 印出名字、學號、總成績、平均。
(3) 輸出的數字如為整數，不需含有小數點。

Input:
Tom
905067
100
100
100

Output:
Name:Tom
ID:905067
Average:100
Total:300


:::
# 2
:::spoiler
一元二次方程式，ax^2 + bx + c = 0，輸入a, b, c, 求 方程式的兩個實根。

---------------
輸入說明

第一個數(int) a
第二個數(int) b
第三個數(int) c

---------------
輸出說明

第一個實根 x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a)
第二個實根 x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a)

x1, x2 輸出到小數點第一位
print("%.1f" %x1);

---------------
Input
1
-2
1

Output
1.0
1.0
:::
# 3
:::spoiler
分別輸入 num1 num2 求出兩數的 Sum,Difference,Product,Quotient。

結果須輸出到小數點第二位
print("%.2f" %x1);

輸入:
25
2

NOTE:Difference為相差，並非25-2，而是兩數之間的差

輸出:
Difference:23.00
Sum:27.00
Quotient:12.50
Product:50.00

:::
# 4
:::spoiler
輸入身高(公尺) 體重(公斤)(皆使用小數)

BMI = 體重(公斤) / (身高*身高)(公尺)

結果須輸出到小數點第一位
print("%.1f" %x1);

輸入:
1.72
60

輸出:
20.3
:::
# 5
::: spoiler

輸入一篇英文文章 ，文章中單字與單字之間以一個空白間隔。另外輸入兩個單字(word) P、Q。
P為文章中所出現的單字，Q為取代或加入的單字
(1) 在文章中把 P 字串以 Q 字串取代，並輸出。
(2) 在文章中把P 字串刪除，並輸出。

輸入範例說明:
第一行，文章
第二行，英文字 P
第三行，英文字 Q

輸出範例說明:
第一行，將文章中的 P 取代成 Q。
第二行，將文章中P單字刪除後印出


Sample Input

This is a book That is a cook
is
was

Sample Output

This was a book That was a cook
This a book That a cook

:::
# 6
:::spoiler
1. 輸入兩個英文句子 A, B，兩個英文單字 x, y
將兩個英文句子A, B 串聯成 句子C
2. 將 句子C 其中的 單字x 取代成 單字y，變成 句子D
3. 輸出 句子C, 句子D 長度的加總
4. 把句子D 前三個字以及最後三個字組合成 句子E，把 句子E重複輸出三次。

Input：
This is a book
That is a cat
is
was

Output：
57
ThwcatThwcatThwcat

:::
# 7
:::spoiler

007.
輸入為一個英文句子以及一個單字，
請print出句子的長度，把句子以輸入的該單字進行分割。

範例輸入說明:
一個英文句子
一個英文句子中有出現的單字

範例輸出說明:
輸出句子的長度
輸出以單字進行分割後的句子

Sample Input:
Those who turn back never reach the summit.
who

Sample Output:
43
['Those ', ' turn back never reach the summit.']


:::
# 8
:::spoiler
008..
請輸入為一個人的全名加上一組生日，
將以上資訊依下列格式輸出，
{FirstName} is born at year {yyyy} month {mm} day {dd} in {LastName} family.

範例輸入說明:
輸入一個人的全名，
順序為FirstName LastName
輸入他的生日，
他的生日年、月、日會以/隔開
yyyy/mm/dd

範例輸出說明:
套用以下格式輸出
{FirstName} is born at year {yyyy} month {mm} day {dd} in {LastName} family.




Sample Input:
kobe Bryant
1978/08/23

Sample Output
kobe is born at year 1978 month 08 day 23 in Bryant family.


:::
# 9
:::spoiler
009.
蘋果、奇異果、鳳梨，三種水果價格及折扣表如下，且老闆為了回饋社會，決定再加碼，購買總顆數(三種水果加起來)達30顆，總金額再打8.7折。
今一顧客欲購買，蘋果:ｘ顆、 奇異果:ｙ顆、鳳梨:ｚ顆（x、y、z 為使用者輸入），
請計算本次購買需花費多少錢？(若總金額有小數,請無條件捨去)



| ------------ | 定價 | 1~10顆 | 11~15顆 | 16~20顆 | 21顆~ |
| ------------ | ---- | ------ | ------- | ------- | ----- |
| 蘋果         | 30   | 原價   | 9.5折   | 9折     | 8折   |
| 奇異果       | 70   | 原價   | 9折     | 8.5折   | 7.5折 |
| 鳳梨         | 40   | 原價   | 8.5折   | 8折     | 8折   |


Sample Input：
10
10
10

Sample Output：
1218


:::
# 10
:::spoiler
010.
撲克牌
A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
A~10 點數為 1~10，J, K, Q 為 0.5。
A, B 兩個人各發三張撲克牌，加總點數越接近 10.5 的贏；超過 10.5 ，爆掉且分數為 0。
程式：
輸入：A, B 兩個人的三張撲克牌。
輸出：兩個人的點數，以及A Win或B Win或Tie。

Sample Input：
A
2
3
2
3
4
Sample Output：
6
9
B Win

Sample Input：
A
2
3
A
2
3
Sample Output：
6
6
Tie

:::
# 11
:::spoiler
011.
檢查三門課程是否衝堂，
依序輸入課程編號(數字)、
上課小時數(1-3小時)、
上課時間(星期1-5, 第1-9節)

輸入說明
1001 (第一門課課程編號)
3 (3小時)
11 (星期1 第1節課)
59 (星期5 第9節課)
25 (星期2 第5節課)
2020 (第二門課課程編號)
2
25
16
2030 (第三門課課程編號)
…

輸出說明 (兩課程編號衝突在哪幾節)
1001 and 2020 conflict on 25

Sample Input：
1001
3
11
12
13
1002
3
21
22
23
1003
3
31
32
13
Sample Output：
1001 and 1003 conflict on 13
:::
# 12
::: spoiler
012..
輸入每月網內、網外、市話、通話時間(sec)及網內、網外 簡訊則數，求最佳資費。
費率如下表：
*月租費也要納入考量
資費類型 183型 383型 983型
月租費 183元 383元 983元
優惠內容 月租費可抵等額通信費
語音    網內 0.08   0.07   0.06
(元/秒) 網外 0.1393 0.1304 0.1087
市話(元/秒)  0.1349 0.1217 0.1018
簡訊    網內 1.1287 1.1127 0.9572
(元/則) 網外 1.4803 1.2458 1.1243

輸入 網內語音(sec)、網外語音(sec)、市話(sec)、網內簡訊數、網外簡訊數 測試資料。
Sample Input：
100
100
100
100
100

Sample Output：
Type 183


:::
# 13 
:::spoiler
013:

輸入m, n 兩個整數，請計算m ~ n 之間等差為2的數列總和、等差為3的乘積，計算方式如下:
1. m ~ n 之間 等差為2的和:
m + (m+2) + (m+4) + (m+6) + ... + n

2. m ~ n 之間 等差為3的積:
m * (m+3) * (m+6) * (m+9) * ... * n

Sample Input
2
10

Sample Output
30
80


:::
# 14
:::spoiler
014
輸入一字串，
1. 印出該字串中的小寫字母 (注意:若沒有字串中沒有小寫字母則輸出'No lowercase letters')
2. 計算該字串有幾個字元?
3. 計算該字串中大寫字元的數量

Sample Input
I have a pen, I have an apple.

Sample Output
haveapenhaveanapple
30
2

:::
# 15
:::spoiler
015
輸入 N ，之後輸入 N 個整數， 例如N=5，5個整數 11, 45, 8, 13, 22。
輸出其中第二大的數
輸出最大的數與最小的數相乘的結果。

Sample Input
3
1
2
3

Sample Output
2
3
:::
# 16
:::spoiler

設計計算BMI值的Python function
BMI值計算公式: BMI = 體重(公斤) / 身高^2(公尺^2)，例如：一個52公斤的人，身高是155公分，則BMI為 : 52(公斤)/1.55^2 ( 公尺^2 )= 21.6。
正常範圍為BMI=18.5～24。
請設計一個 function，從鍵盤輸入姓名name、身高、體重。
當BMI太大，輸出 Hi name, Your BMI: xxx too HIGH.
當BMI太小，輸出 Hi name, Your BMI: xxx too LOW.
在正常範圍，輸出 Hi name, Your BMI: xxx.
註:BMI輸出，取小數點後六位。

Sample Input
Jeff
155
52

Sample Output
Hi Jeff, Your BMI: 21.644121.
:::
# 17
:::spoiler
```
請使用 while loop或for loop
第一個輸入意義為選擇三種圖形:
1 三角形方尖方面向右邊
2 三角形方尖方面向左邊
3 菱形

第二個輸入意義為畫幾行
(奇數，範圍為 3,5,7,9,....,21)

input
1 (第一種圖形，三角形尖方面向右邊)
9 (共 9 行)
--------------------------
output
*
**
***
****
*****
****
***
**
*
---------------------------
input
2 (第二種圖形，三角形尖方面向左邊)
5 (共 5 行)
---------------------------
output
..*
.**
***
.**
..*
--------------------------
input
3 (第三種圖形: 菱形 )
3 (共 3 行數)

輸出
.*
***
.*
```
:::
# 18
:::spoiler
```
*將每個功能的Code寫成2個function，每一個function使用一層迴圈*
*亦即一個 function 不要有兩個迴圈/巢狀迴圈*
請使用 while loop或for loop
第一個輸入意義為選擇三種圖形:
1 直角三角形
2 正三角形
3 倒三角形

第二個輸入意義為畫幾行
(輸出圖形為數字+底線)

input
1 (第一種圖形：直角三角形)
5 (共 5 行)
--------------------------
output
1
121
12321
1234321
123454321
---------------------------
input
2 (第二種圖形：正三角形)
4 (共 4 行)
---------------------------
output
___1___
__121__
_12321_
1234321
--------------------------
input
3 (第三種圖形：倒三角形 )
3 (共 3 行數)
---------------------------
output
12321
_121_
__1__
```
:::
# 19
:::spoiler
```
n=1
#1
--------
n=2
##21
###1
------------
n=3
###321
####21
#####1
----------
n=4
####4321
#####321
######21
#######1
----------
n=5
#####54321
######4321
#######321
########21
#########1

input
--------------
4

output
-------------
####4321
#####321
######21
#######1
```
:::
# 20
:::spoiler
```
範例輸入說明:
請輸入一個小於等於200的正整數，
並且判斷是否為質數。

範例輸出說明:
印出該整數，並且表示是否為質數

Sample Input:
137

Sample Output:
137 is prime number

Sample Input:
6

Sample Output:
6 is not prime number
```
:::
# 21
:::spoiler


迴圈偶數連加，輸入兩整數a、b，且a 例如輸入 a=1、b=100，則輸出結果為 2550(2+4+6+8+ ... +100 =2550)
simple input:
1
100

simple output:
2550
:::

# 22
:::spoiler

階乘計算，例如5的階乘計為5!，其值為120，最大不超過15!。
例如 5!=5*4*3*2*1

simple input:
5

simple output:
120
:::
# 23
:::spoiler


撲克牌
A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
A~10 點數為 1~10，J, K, Q 為 0.5。

電腦與玩家各隨機發撲克牌，加總點數接近 10.5 則贏。
超過 10.5 爆掉，此時加總點數視為 0 且該方不得繼續要牌。
任一回合並未要牌的一方，失去要牌權利。

發牌順序：
1. 輸入Y或N以決定玩家是否選擇要牌(第一輪必會發牌給玩家，略過此步)
2. 若玩家選擇要牌，輸入任意點數的一張撲克牌給玩家。
3. 電腦判斷是否要牌，若是，則輸入任意點數的一張撲克牌給電腦，若否，則停止要牌。
以下情況電腦才會要牌：1. 總點數比玩家小 或 2. 總點數8點以下(含8點)
4. 重複以上三步驟直到雙方皆停止要牌或失去要牌權力則結束遊戲
5. 遊戲結束後，輸出電腦與玩家的點數，以及電腦贏或玩家贏或平手。
電腦贏輸出：computer wins
玩家贏輸出：player wins
平手輸出：It's a tie

輸入範例註解：
A 先發一張給給玩家(玩家獲得A)
J 再發一張給電腦(電腦獲得J)
Y 玩家選擇要牌
9 發一張給玩家(玩家獲得9)
8 電腦牌面0.5點，未超過8點，再發一張給電腦(電腦獲得8)
N 玩家選擇不要牌
5 電腦牌面8.5，低於玩家的10，因此再抽(獲得5)

輸出範例註解：
10.0 vs. 0.0
player wins

Sample Input：
4
6
Y
A
2
Y
5
J
N
2

Sample Output：
10.0 vs. 10.5
computer wins

Sample Input：
5
5
Y
5
J
Y
K
5
N

Sample Output：
10.5 vs. 10.5
It's a tie
:::
# 24
:::spoiler

階梯數字：數字字串從高位數往低位數看過去，每一位數字只會相等或變大，例如：9、234、777、11222233等數字都有這性質，稱階梯數字(0不是階梯數字)。

給定一正整數 N>0，找出不大於N的階梯數字共有幾個。

輸入說明： 一個正整數N。
輸出說明:：一個不大於N的階梯數字總個數。

Sample Input1：
25
Sample Output1：
22

Sample Input2：
23456
Sample Output2：
1365

Sample Input3：
54321
Sample Output3：
1875

Sample Input4：
88888888
Sample Output4：
24301

Sample Input5：
9999999999999999999999999999
Sample Output5：
124403619

註：執行時間過長會導致測試失敗
:::
# 25
025
:::spoiler


輸入一組五張的撲克牌，判斷並輸出牌型
===================
撲克牌花色及點數：

1. 四種花色黑桃、紅心、磚塊、梅花，分別定義為 S, H, D, C。
2. 花色大小：黑桃>紅心>方塊>梅花。
3. 牌面符號A, 2, ..,, J, Q, K，點數2~10為2~10, A為14，J 為11， Q 為12，K為13，共有52張牌。
===================
牌型種類：

散牌 : 一組撲克牌中沒有任何其餘花色牌型，編號0。
一對 : 兩張數字一樣為 Pair，編號 1。
兩對 : 2 組 Pair 的牌為 Two pair，編號 2。
三條 : 三張一樣數字的為 Three of a Kind，編號 3。
順子 : 數字連續的 5 張牌為 Straight，包括[2, 3, 4, 5, 6],.., [11, 12, 13, 14, 2], [12, 13 ,14, 2, 3], [13 ,14, 2, 3, 4], [14, 2, 3, 4, 5]，編號 4。
同花 : 五張同一花色的牌為 Flush，編號 5。
葫蘆 : Three of a Kind 加一個 Pair為 Full House，編號 6。
四條 : 四張一樣數字為 Four of a Kind，編號 7。
同花順 : 數字連續的 5 張且花色一樣為 Straight Flush，編號 8。
===================
輸入說明：
五張撲克牌，每張牌之間以空格區隔，且無排序順序，
撲克牌的輸入編碼規則為牌面符號+花色，例如 10S 表黑桃 10、7D 表磚塊 7，QC 表梅花 Q

輸出說明：
判斷輸入撲克牌的牌型，並輸出符合的牌型種類中編號最大的值。
===================
Sample input 1：
AH 2H 3H 4H 5H

Sample output 1：
8
===================
Sample input 2：
QC KC 8S 7C AC

Sample output 2：
0
===================
Sample input 3：
10D AD KD QD 8D

Sample output 3：
5
===================
Sample input 4：
KC 4S 9H 4H 4C

Sample output 4：
3
:::
# 26
:::spoiler

026

設計十點半的遊戲賭盤
===================
撲克牌點數

牌面A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
A~10 點數分別為 1~10點，J, K, Q 皆為 0.5點。

牌面總點數大於10.5點，即為爆牌且該方不得再要牌。
===================
強制停止閒家要牌階段的條件

1. 閒家爆牌，閒家立賠且閒家不得再要牌。
2. 閒家總牌面為一張10搭配一張J、Q或K，莊家立賠且閒家不得再要牌。
3. 閒家總牌面擁有五張牌且未爆牌，莊家立賠且閒家不得再要牌。
===================
遊戲流程 (下列範圍皆包含上限及下限)：
1. 輸入閒家人數，人數介於1~3人。
2. 輸入各閒家下注點數，點數介於1~10點，每個點數之間用一個空格區隔。
3. 閒家各派發一張牌，每張牌之間以一個空格區隔。
4. 輪流進入各閒家要牌階段，輸入Y表示要牌，輸入N表示停牌，接著輸入點數，可持續要牌，直到該位閒家停牌或符合前述強制停止要牌階段的條件後，才會進入下一位閒家的要牌階段。
5. 各閒家皆停牌後，莊家先發一張牌給自己，之後可選擇是否要牌，直到停牌或爆牌。
6. 若莊家爆牌，則須賠點給未爆牌的閒家且遊戲結束。
7. 莊家停牌後遊戲結束，將與未爆牌閒家分別比較點數，點數較大者勝，若點數相同則視為莊家勝。
8. 輸出莊家與各閒家的賠點或勝點，賠點以負號表示，勝點以正號表示。
===================
輸入範例註解：
3 閒家人數為3人
2 10 5 各閒家下注點數
Q 3 10 各閒家獲派的第一張牌
Y 第一位閒家選擇要牌
2 第一位閒家獲得2
Y 第一位閒家選擇要牌
7 第一位閒家獲得7
N 第一位閒家選擇停牌
Y 第二位閒家選擇要牌
8 第二位閒家獲得8，總點數11導致爆牌，閒家立賠且閒家不得再要牌
Y 第三位閒家選擇要牌
Q 第三位閒家獲得Q，總牌面為10和Q，莊家立賠且閒家不得再要牌
8 莊家獲得第一張牌
Y 莊家選擇要牌
2 莊家獲得2
N 莊家停牌

輸出範例註解：
Player1 -2
Player2 -10
Player3 +5
Bank +7
===================
Sample input 1：
2
7 4
9 10
Y
A
Y
K
N
Y
J
6
Y
4
Y
K
N

Sample output 1：
Player1 -7
Player2 +4
Bank +3
===================
Sample input 2：
2
10 10
A 3
Y
4
Y
6
Y
A
Y
Q
Y
Q
Y
2
9
N

Sample output 2：
Player1 -10
Player2 +10
Bank 0
===================
Sample input 3：
3
4 5 6
2 2 2
N
N
N
A
Y
10

Sample output 3：
Player1 +4
Player2 +5
Player3 +6
Bank -15
===================
Sample input 4：
3
2 3 4
5 6 7
Y
6
Y
5
Y
4
6
Y
6

Sample output 4：
Player1 -2
Player2 -3
Player3 -4
Bank +9
:::
# 27
:::spoiler

027
設計密碼的分數計算function
===================
密碼的分數計算規則如下：
1. N個英文字母小寫加N分。
2. X個英文字母大寫加X*2分。
3. Y個數字加Y*3分。
4. M個特殊符號【~!@#$%^&*<>_+=】加M*5分 (不包含【及】這兩個符號)。
5. 有五個以上的數字且任兩個數字在密碼中的位置不相鄰，例如：「1a1a1a1a1」，加10分。
===================
輸入說明：
給定至少兩組分數不同的密碼，每組密碼以隔行區隔，輸入-1以停止。

輸出說明：
計算各組密碼的分數，依序輸出最高及最低分數的兩組密碼及其分數，
兩組密碼以隔行區隔，兩組密碼中的密碼與分數之間以空格區隔。
===================
Sample input 1：
1a1a1a1a1
a1a1a1a1a
1W$fg&9Q9kp32%
1W$fg&9Q9kp3%2
An@Apple!A*Day=Keeps^The#Doctor_Away
PEKOPEKO
-1

Sample output 1：
An@Apple!A*Day=Keeps^The#Doctor_Away 72
PEKOPEKO 16
:::
# 28
:::spoiler

028
《孫子算經》裡有個「物不知其數」的問題：「今有物，不知其數，三三數之賸二，五五數之賸三，七七數之賸二。問物幾何？」。
幫你們翻譯：眼前有一堆物品，不知有多少個。每次取3個，最後剩下2個；每次取5個，最後剩下3個；每次取7個，最後剩下2個。問這堆物品到底有多少個？
===================
輸入說明：
假設有未知數量的物品，若每次取x1個，最後剩下y1個；若每次取x2個，最後剩下y2個；若每次取x3個，最後剩下y3個。
輸入字串為 x1 y1 x2 y2 x3 y3，各正整數之間以一個空格區隔。

輸出說明：
最少的物品可能總數
===================
Sample Input 1：
3 2 5 3 7 2

Sample Output 1：
23
===================
Sample Input 2：
9 5 8 4 7 3

Sample Output 2：
500
===================
Sample Input 3：
97 49 103 41 107 91

Sample Output 3：
566335
:::

# 29
:::spoiler

029數字排序

給定一串數字，將這一連串數字分為奇數在左，偶數在右，
並且奇數按照由小到大排序，偶數按照由大到小排序。
===================
Sample Input 1：
1 2 3 4 5 6 7 8 9

Sample Output 1：
[1, 3, 5, 7, 9, 8, 6, 4, 2]
===================
Sample Input 2：
999 104 99 103 9 567 43

Sample Output 2：
[9, 43, 99, 103, 567, 999, 104]
===================
Sample Input 3：
888 222 666 444

Sample Output 3：
[888, 666, 444, 222]
:::
# 30
:::spoiler

030
給定一行英文字串，以空格區隔出數個單字，
而後輸入一行數字字串，
該數字字串決定英文字串中各單字的前後排序，
===================
範例輸入說明:
參考以下Input，
每個數字將對應到一個單字，
按照對應數字的大小，由小到大排序單字，並輸出為一行字串。
（各單字間無須以空格區隔）

範例輸出說明:
輸出排序後的字串。
===================
Sample Input 1：
A B C D E F G
7 6 5 3 1 2 4

Sample Output 1：
EFDGCBA
===================
Sample Input 2：
qrqe qwer wrqe eqrw qqrf
5 9 3 2 7

Sample Output 2：
eqrwwrqeqrqeqqrfqwer
:::
# 31
:::spoiler

031 數位電路模擬

數位IC輸入m 是二進位 8 位元，輸出是二進位 4 位元。
輸入範圍從 00000000 到 11111111 (十進位 0~255)。
輸出範圍從 0000 到 1111 (十進位 0~15)
=================
數位IC內有一個回饋電路接收輸入m，視為一個函數C(m)，其回饋方式如下：
1. 若m為偶數(十進位)，則C(m) = C(m/2)
2. 若m為奇數(十進位)，則C(m) = C((m+1)/2)
3. 若m = 1，則回饋電路結束

數位IC內有一個紀錄器，會記錄回饋電路的回饋次數。
R(m) = [C(m)的回饋次數]，例如：R(10) = 4。

數位IC的輸出為紀錄器所記錄之回饋電路的回饋次數。
=================
數位IC範例說明：
1. 00001010 輸入二進位8位元m (十進位為10)
2. 進入回饋電路C(10)
3. 10為偶數，因此第一輪回饋為C(10) = C(5)
4. 5為奇數，因此第二輪回饋為C(5) = C(3)
5. 3為奇數，因此第三輪回饋為C(3) = C(2)
6. 2為奇數，因此第四輪回饋為C(2) = C(1)
7. m=1，因此回饋電路結束
8. 總計回饋4次，因此輸出0100(十進位為4)
=================
題目要求：
1. 設計數位IC的function
2. 主程式中可接受多組輸入，並經過數位IC後，一次輸出所有數位IC的輸出結果
=================
輸入說明：
可接受多組二進位8位元的輸入m，每組輸入以隔行區隔，直到輸入-1後停止輸入。

輸出說明：
輸出每組二進位8位元的輸入m進入數位IC後的輸出結果，每組輸出以隔行區隔。
Note：切勿輸入一組m後就印出數位IC結果，請於輸入-1後才一次印出所有結果
=================
Sample Input 1：
00000000
11111111
00000001
10000000
00111111
-1

Sample Output 1：
0000
1000
0000
0111
0110
=================
Sample Input 2：
11001100
10100101
00001111
01011010
01110110
11111100
00011000
01101111
00011110
01110000
-1

Sample Output 2：
1000
1000
0100
0111
0111
1000
0101
0111
0101
0111
:::
# 32
:::spoiler

032
費氏數列 Fibonacci number

請用遞迴撰寫。
輸入一個整數n，輸出 Fibonacci number。

F(1) = 1 ; F(2) = 1;
F( n ) = F(n-1) + F(n-2) ;n > 2

輸入說明：

每一組一個正整數，輸入-1結束所有輸入。
數字代表第幾個數列的數字 1~100

輸出說明：

費氏數列的值。

---------------------

Sample Input:

1
2
5
50
10
-1

Sample Output:

1
1
5
12586269025
55
:::

# 33
:::spoiler

033
計算最大公因數 GCD
給予三個整數，請計算出三個整數的最大公因數。

輸入說明:
一行三個整數以空格隔開，直到-1結束

輸出說明:
輸出三個整數的最大公因數。

Sample Input
18 9 6
21 42 63
17 23 33
3529 2333 421
5 5 5
-1

Sample Output
3
21
1
1
5
:::

# 34
:::spoiler

034
假設一個數列K(n) 的前兩項是
K(0) = 0 ; K(1) = 1，
而之後的每一項為K(n)=2*K(n-1)+3*K(n-2)，n>=2
https://imgur.com/Q8FbZZB (如網址圖片所示)
使用【遞迴函式】計算K(n)，
輸入說明:
由使用者輸入一個正整數n，n>=2
若輸入錯誤請顯示Error
輸出說明:
印出該數列的第n項。


範例說明:
Input:
5
Output:
61
--------------------
Input:
-999999
Output:
Error
--------------------
Input:
1
Output:
Error
--------------------
Input:
2
Output:
2
--------------------
Input:
15
Output:
3587227
--------------------
Input:
1.3
Output:
Error
:::

# 35
:::spoiler
```
035
請對字串做乘法運算
並輸出其乘開後的內容

Sample

Input1:
3[a]2[bc]

Output1:
aaabcbc


Input2:
3[a2[c]]

Output2:
accaccacc


Input3:
2[abc]3[cd]ef

Output3:
abcabccdcdcdef


Input4:
2[3[pe]2[ko]]

Output4:
pepepekokopepepekoko

Input5:
2[d2[e2[f]]]

Output5:
deffeffdeffeff
```
:::

# 36
:::spoiler

```
036.
平面上的 n 條直線最多可將平面劃分成幾個區域？
**需用遞迴a(n+1) = an+n+1**

輸入說明：
輸入一個正整數 n ，代表有 n 條直線。

輸出說明 :
輸出一個正整數表示有n條直線時，最多能將平面切割成幾個區域。

結尾不須換行。

Input:
-------------------------
1
Output:
------------------------
2

Input:
-------------------------
2
Output:
------------------------
4

Input:
-------------------------
5
Output:
------------------------
16
```
:::
# 37
:::spoiler
```
037.
請先輸入一個數n，
該數n決定後面要輸入幾個區間，
將第n個區間插入第1~n-1個區間，
並輸出最後結果。

範例輸入說明:
假設輸入n = 3
後面接著輸入三個區間，
1,3
6,9
2,5

範例輸出說明:
因2~5與6~9沒有交集，所以6,9不變
但1~3與2~5有交集，所以把2,5插入1~3中
則結果為1,5
所以最後輸出為:
1,5
6,9

sample input:
3
1,3
6,9
2,5

sample output:
1,5
6,9

------------------------------------
sample input2:
6
1,2
3,5
6,7
8,10
12,16
4,8

sample output2:
1,2
3,10
12,16

3,5 與 6,7 與8,10 它們與4,8皆有交集
但因6,7已在4,8中，所以它可忽略
且4,8剛好在3,5與8,10之間，
所以合併為3,10

------------------------------------
sample input3:
2
5,8
5,8

sample output3:
5,8

------------------------------------
sample input4:
3
1,3
8,10
3,5

sample output4:
1,5
8,10
```
# 38
:::spoiler

```
38.
回文子字串(Palindromic Substring):
輸入一個字串(不得有空格)，找出所有不重複的回文子字串，且依字典順序排序後，將這些回文子字串以”#”相隔印出。
==============
Sample input1:
abbabcc

Sample output1:
a#abba#b#bab#bb#c#cc
==============
Sample input2:
a
Sample output2:
a
==============
Sample input3:
wandnaVision

Sample output3:
V#a#andna#d#i#isi#n#ndn#o#s#w
==============
Sample input4:
89811086

Sample output4:
0#1#11#6#8#898#9

==============
Sample input5:
2020XX0221hahah

Sample output5:
0#020#0XX0#1#2#202#20XX02#22#X#XX#a#aha#h#hah#hahah
```
:::

# 39
:::spoiler
```
39.
輸入說明：
輸入一個大小寫英文字串和一個數字n，以一個空格間隔，且n需小於等於字串的長度，字串中不得有空格且字元不得重複，字串長度不得超過8字元

輸出說明：
計算出對字串取n個字元的所有組合可能，組合內依原字串中字元順序排序，再對所有組合可能依字典順序排序後，依序以一個空格間隔輸出。
==============
Sample input 1:
ABCD 2

Sample output 1:
AB AC AD BC BD CD
==============
Sample input 2:
pekoPEKO 8

Sample output 2:
pekoPEKO
==============
Sample input 3:
pelican 3

Sample output 3:
can ean eca ecn eia eic ein ela elc eli eln ian ica icn lan lca lcn lia lic lin pan pca pcn pea pec pei pel pen pia pic pin pla plc pli pln
==============
Sample input 4:
Guavb 4

Sample output 4:
Gavb Guab Guav Guvb uavb
==============
Sample input 5:
DinoSaur 5

Sample output 5:
DSaur DiSar DiSau DiSur Diaur DinSa DinSr DinSu Dinar Dinau DinoS Dinoa Dinor Dinou Dinur DioSa DioSr DioSu Dioar Dioau Diour DnSar DnSau DnSur Dnaur DnoSa DnoSr DnoSu Dnoar Dnoau Dnour DoSar DoSau DoSur Doaur iSaur inSar inSau inSur inaur inoSa inoSr inoSu inoar inoau inour ioSar ioSau ioSur ioaur nSaur noSar noSau noSur noaur oSaur
```
:::

# 40
:::spoiler
```
40.
(1)首先，輸入一串不超過50字元的字串(不得有空格)及一正整數K，兩者以一個空格為間隔
(2)去除字串間非英文字母的字元，例如the$sky@iS!soBlue 應轉換成theskyiSsoBlue
(3)再對字串做大小寫的互相轉換，例如theskyiSsoBlue 應轉換成 THESKYIsSObLUE
(4)對字串以每隔K個字元進行切割，最後一組若字元數不足K則無視
例如：當K=3時，THESKYIsSObLUE 應切割成THE、SKY、IsS、ObL、UE共計5組字串
(5)將每組切割好的字串進行順序反轉後，並以【/】作為間隔輸出。
例如：THE、SKY、IsS、ObL、UE應轉換並輸出UE/ObL/IsS/SKY/THE
==============
Sample input 1:
abcda 1

Sample output 1:
A/D/C/B/A
==============
Sample input 2:
abcDefgHiaaA 2

Sample output 2:
Aa/IA/Gh/EF/Cd/AB
==============
Sample input 3:
mynameisBig5666hehe 10

Sample output 3:
GHEHE/MYNAMEISbI
==============
Sample input 4:
iHaveAnApple 15

Sample output 4:
IhAVEaNaPPLE
==============
Sample input 5:
@H#hHhhhh12*4%H287 3

Sample output 5:
Hh/HHH/hHh
```
:::

# 41
:::spoiler
```
某社群平台上，A可以加B為朋友，若B同意，則A，B變成朋友。
A可以找尋B的朋友，去認識第二層新的朋友，透過這種方法，可以認識一層又一層新的朋友。
求成員X, Y是否有機會可以互相認識。

輸入說明
第一行N, X, Y，N為朋友關係的資料數量，X, Y是希望透過朋友關係互相認識的成員姓名。
之後N行，每一行X Y，代表X與Y互相為朋友關係。

輸出說明
X, Y是否有機會可以互相認識。
若有機會則輸出 Yes!

若沒有機會則輸出 NO!

注意:
1.因會有資料量較大的測試資料，請嘗試使用BFS(廣度優先搜尋 / Breadth-First Search)+Queue完成。
2.使用窮舉法或遞迴可能導致timeout。

Sample Input:
14 1 8
1 5
2 5
3 2
4 3
5 2
5 4
5 3
6 5
6 4
7 2
7 6
8 4
8 3
8 7

Sample Output:
Yes!

Sample Input:
13 1 10
1 4
1 5
2 4
3 5
3 4
3 2
4 3
5 2
6 3
7 10
8 7
9 7
10 8

Sample Output:
No!

Sample Input:
14 1 15
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15

Sample Output:
Yes!
```
:::

# 42
:::spoiler
```
042. 簡單五則運算

計算五則運算式的結果，包含加、減、乘、除、餘

輸入說明 ：

輸入一個字串，其中包含運算元及運算子，為了方便讀取，所有的運算子及運算元均以空格區隔。
運算元皆為正整數
運算子則包含 + - * / %
運算時請注意”先乘除(餘)後加減”的計算規則

輸出說明 ：

輸出結果。為了避免小數點誤差，所有的運算過程都不會產生小數點，可以放心使用整數進行運算

注意 ：
此題為練習 stack 的應用，請勿使用 eval 函式來進行解題。
若未使用 stack 作答作業，將不予計分。

Sample Input:
3 + 5 - 7 - 4

Sample Output:
-3

Sample Input:
3 + 6 / 2 + 9 / 3 - 4

Sample Output:
5

Sample Input:
3 + 6 / 2 * 3 - 4 % 3

Sample Output:
11

```
:::

# 43
:::spoiler
```
043. 理想的大學

高中職畢業生希望選擇心目中理想的大學。

假設每一大學可以用下列七種屬性表示：

BC(Big Campus)：代表有大校園。
NC(Next to City)：代表鄰近有大城市。
CT(Convenient Transportation)：代表交通方便。
NS(Next to Sea)：代表靠海。
NM(Next to Mountain)：代表依山。
HL(Has Lake)：代表校園有湖。
NL(Near Landscape)：代表附近有風景區。

輸入說明：

1. 第一行輸入一個【正整數】，代表大學個數 n ，請注意 【n<=10 】。
2. 其後 n 行，每一行第一項為大學名稱，接著為大學具備的屬性。
一個大學名稱【最多有 10 個字母】，【各項屬性為 2 個字母】。大學與屬性資料【均為英文字母】，
大學名稱及各屬性間以【一個空白】分隔。

3. 接下來的一行輸入一個查詢
查詢條件為校園屬性組成，每個校園屬性為【2個字元】，
此外，用 + 號區隔的條件代表 "或" 的關係，用空白區隔的條件代表 "且" 的關係，用 ! 號連接屬性代表 “不” 的關係。
屬性之間以及和 + 之間有一空白間隔( ! 號與屬性之間沒有空白間隔)。
以 + 號區隔不同的子條件。

其格式如下:

BC NS + CT HL + NL !NM

意思為屬性條件為: 三種子條件，BC 且 NS ，或是 CT 且 HL ，或是 NL 且不要 NM。
代表需找出有大校園且靠海，或 交通方便且校園有湖的所有大學名稱，或 附近有風景區且不要依山。


輸出說明：

所有符合之大學名稱與符合子條件個數(比如: NTUT,3)。
若有多個大學符合一個查詢，各大學間以一個空白分隔。
每行查詢的輸出順序，請根據大學符合的子條件個數進行排序，
若條件個數相同，則根據輸入大學的順序來排序。

Sample Input:
2                   # 兩間學校
A BC NC CT NS NM HL # A學校 符合BC、NC、CT、NS、NM、HL
B CT NS NM          # B學校 符合CT、NS、NM
CT NS + !NL + NM HL # 三種子條件，CT 且 NS 或 不NL 或 NM且HL

Sample Output:
A,3 B,2             # A學校三種子條件皆符合，B學校僅符合CT NS、!NL 兩種子條件

--------------------------------------------------------------------

Sample Input:
2
A BC NC CT NS NM HL
B CT NS NM
CT + HL + !BC

Sample Output:
A,2 B,2

--------------------------------------------------------------------

Sample Input:

5
NSYSU NC CT NS NM
NTU BC NC CT NS
NCCU BC NL HL
Providence BC NC
NTHU BC NS
!BC + !NS + NL

Sample Output:

NCCU,2 NSYSU,1 Providence,1

--------------------------------------------------------------------

Sample Input:

10
NCCU BC NL HL
Providence BC NC
NTU BC NC CT NS
NTUT CT NL NC
NCHU BC NM NC
NCKU BC CT NL
NCU BC NM
NTPU BC CT
NCTU NS NM
NTOU BC NS
!BC + NS + NC + CT + !NL

Sample Output:

NTU,4 NTUT,3 NCTU,3 Providence,2 NCHU,2 NTPU,2 NTOU,2 NCKU,1 NCU,1
```
:::
# 44
:::spoiler
```
044.對發票
阿翔是一個很喜歡對發票的男孩，所以他存了很多張發票準備對獎，
如果要人工對發票，搞不好會漏掉千萬獎金，所以他想要寫一個
對發票的程式，請你們幫幫他吧!!!

發票對獎規則、獎金:
獎項-------------------條件-------------------金額

特別獎---------發票全號與特別獎號碼相同---------1000萬

特獎-----------發票全號與特獎號碼相同-----------200萬

頭獎-----------發票全號與頭獎號碼相同-----------20萬

二獎-----發票末7位號碼與頭獎號碼末7位號碼相同-----4萬

三獎-----發票末6位號碼與頭獎號碼末6位號碼相同-----1萬

四獎-----發票末5位號碼與頭獎號碼末5位號碼相同-----4千

五獎-----發票末4位號碼與頭獎號碼末4位號碼相同-----1千

六獎-----發票末3位號碼與頭獎號碼末3位號碼相同-----2百

增開六獎---發票末三位號碼與增開六獎號碼完全一樣----2百

輸入說明:
1.第一行，為特別獎號碼(1組)
2.第二行，為特獎號碼(1組)
3.第三行，為頭獎號碼(3組)
4.第四行，為增開六獎號碼(3組)
5.上述對獎號碼輸入後，輸入核對發票的【筆數】N，
6.輸入N筆核對發票的【號碼】。

輸出說明:
輸出總累積獲得的【獎金】(【一律寫數字】，不能寫1百、千、萬....)
若都無中獎，請輸出 0


注意:以【得獎金數最高】為獎金，不能累計!
例如:得二獎(末7碼)，代表三(末6碼)、四(末5碼)、五(末4碼)、六(末3碼)獎都有中，
但是只能得二獎，以下的金額不能累計在內!


Sample Input1
45698621
19614436
96182420 47464012 62781818
928 899 118
5
45698621
96182420
33364012
12341818
76588928

Sample Output
10205200


Sample Input2
41482012
58837976
20379435 47430762 36193504
693 043 425
5
85698694
76182425
33364012
12341818
76588929

Sample Output
200
```
:::


# 45. 外星城市
:::spoiler
```
小白要到納美克星的城市旅遊，某些城市之間有傳輸通道可以走。小白聽說B城市特別好玩，因此到目的地之前一定要經過B城市，但小白又不想走太多路，因此需要同學幫小白找出一條能從A城市到C城市，並且中途一定會經過B城市的最短路徑。

輸入說明
第一行N, X, Y,Z，星球中有N個傳輸通道，X,Y,Z分別代表起始點X城市、特別好玩的城市Y、終點Z城市。
之後N行，每一行X Y，代表X城市與Y城市之間有傳輸通道可以走。

輸出說明
X是否中途可以經過Y城市並且最終可以抵達Z城市。
如果可以則輸出：
X到Y城市過程中走過的最少通道個數以及最短路徑

若不行則輸出 No way!

注意:
1.因會有資料量較大的測試資料，請嘗試使用BFS(廣度優先搜尋 / Breadth-First Search)+Queue完成。

2.使用窮舉法或遞迴可能導致timeout。

Sample Input1:
6 1 3 4
1 2
1 3
2 4
2 5
3 5
5 4

Sample Output1:
3
1-3-5-4

Sample Input2:
13 1 4 10
1 4
1 5
2 4
3 5
3 4
3 2
4 3
5 2
6 3
7 10
8 7
9 7
10 8

Sample Output2:
No way!

Sample Input3:
12 1 4 9
1 2
1 3
2 3
2 4
2 5
3 9
4 6
6 7
6 8
7 9
4 5
5 9
Sample Output3:
4
1-2-4-5-9

Sample input4:
134 1 32 57
1 32
1 4
1 12
2 7
3 6
3 23
3 67
3 68
4 45
4 11
5 70
5 66
6 44
6 28
7 3
7 25
7 89
8 4
8 83
8 12
8 40
9 21
9 41
9 4
9 2
10 99
10 69
11 49
11 10
11 96
12 59
12 2
12 87
12 22
13 2
14 75
14 9
14 90
15 74
16 76
17 74
17 5
18 17
18 95
18 89
18 26
19 99
19 6
20 79
20 81
21 43
21 45
21 74
22 93
22 77
22 39
22 21
23 26
23 74
23 15
23 22
24 30
24 55
25 19
25 32
25 83
26 79
26 38
27 67
27 8
28 20
29 53
30 55
30 92
31 87
31 65
32 57
33 13
33 37
33 53
34 91
34 33
35 13
36 27
36 13
36 29
37 83
38 12
39 41
40 23
40 66
40 11
40 27
41 9
41 8
41 69
41 19
42 67
42 7
42 54
43 98
43 48
43 16
43 63
44 45
44 14
45 21
45 85
46 44
47 84
47 97
47 63
48 53
48 10
49 39
49 43
50 49
50 39
50 48
50 86
51 34
52 97
52 9
52 8
52 64
53 58
53 11
53 84
53 41
54 5
55 30
55 69
56 9
57 33

Sample output4:
2
1-32-57

Sample input5:
6 1 5 10
1 2
2 3
3 5
1 4
4 5
5 10

Sample output5:
3
1-4-5-10

Sample input6:
134 1 4 85
1 32
1 4
1 12
2 7
3 6
3 23
3 67
3 68
4 45
4 11
5 70
5 66
6 44
6 28
7 3
7 25
7 89
8 4
8 83
8 12
8 40
9 21
9 41
9 4
9 2
10 99
10 69
11 49
11 10
11 96
12 59
12 2
12 87
12 22
13 2
14 75
14 9
14 90
15 74
16 76
17 74
17 5
18 17
18 95
18 89
18 26
19 99
19 6
20 79
20 81
21 43
21 45
21 74
22 93
22 77
22 39
22 21
23 26
23 74
23 15
23 22
24 30
24 55
25 19
25 32
25 83
26 79
26 38
27 67
27 8
28 20
29 53
30 55
30 92
31 87
31 65
32 57
33 13
33 37
33 53
34 91
34 33
35 13
36 27
36 13
36 29
37 83
38 12
39 41
40 23
40 66
40 11
40 27
41 9
41 8
41 69
41 19
42 67
42 7
42 54
43 98
43 48
43 16
43 63
44 45
44 14
45 21
46 44
47 84
47 97
47 63
48 53
48 10
49 39
49 43
50 49
50 39
50 48
50 86
51 34
52 97
52 9
52 8
52 64
53 58
53 11
53 84
53 41
54 5
55 30
55 69
56 9
57 33
85 45

Sample output6:
3
1-4-45-85
```
:::
# 46
:::spoiler
```
046 會議安排

某公司有數間會議室，使用會議前需要各單位登記舉辦會議時間，會議室24小時開放，
每個會議有不同的使用時間。由於會議眾多，可能發生時間衝突，總務部門需從這些活動中，
選取時間上不衝突的活動讓他們如願使用會議室。公司希望所有會議室能做最有效的利用。

輸入說明
第一行輸入兩個整數M, N，M是會議室間數(0<=M<=4)，N是申請舉辦會議個數(0<=N<=11)。
其後N行，每一行有三個正整數以空白隔開，代表每一個申請會議的編號、開始時間(0-23)、結束時間(1-24)。
時間以0代表凌晨12點，18代表下午六點，24代表半夜12點。

例如：
1 1 4 #會議1 使用1點到4點
2 3 15 #會議2 使用3點到15點

輸出說明
從所有的申請會議中，計算最長使用總時數，並輸出。

範例輸入：
2 4 # 有2間會議室 4場會議要安排
1 1 3 # 會議1 時間為1-3點
2 1 3 # 會議2 時間為1-3點
3 3 4 # 會議3 時間為3-4點
4 1 5 # 會議4 時間為1-5點

此時可安排會議 1, 2, 3，總時長為 2 + 2 + 1 = 5；
但也可安排會議 1, 3, 4，會議總時長為 2 + 1 + 4 = 7；
或是可安排會議 2, 3, 4，會議總時長為 2 + 1 + 4 = 7；
故最長會議時數為應該為7

範例輸出：
7
Sample input 1
2 5
1 1 4
2 4 10
3 3 9
4 6 15
5 2 10

Sample output 1
20

Sample input 2
4 3
1 1 10
2 5 9
3 2 8

Sample output 2
19

Sample input 3
2 5
1 8 12
2 9 13
3 10 14
4 11 15
5 10 16

Sample output 3
10

Sample input 4
0 1
1 1 2

Sample output 4
0

Sample input 5
1 0

Sample output 5
0

Sample input 6
2 2
1 0 1
2 1 24

Sample output 6
24

Sample input 7
2 4
1 0 5
2 1 5
3 6 15
4 0 1

Sample output 7
19

Sample input 8
1 11
1 0 1
2 1 2
3 2 3
4 3 4
5 4 5
6 5 6
7 6 7
8 7 8
9 8 9
10 9 10
11 10 11

Sample output 8
11

Sample input 9
1 5
1 1 5
2 1 6
3 1 9
4 1 8
5 1 7

Sample output 9
8

Sample input 10
2 8
1 0 6
2 1 6
3 6 15
4 0 1
5 2 6
6 3 6
7 4 6
8 5 6

Sample output 10
21

Sample input 11
2 11
1 0 6
2 3 5
3 5 7
4 2 3
5 6 10
6 12 14
7 5 9
8 1 4
9 8 12
10 8 11
11 3 8

Sample output 11
22
```
:::
# 47
:::spoiler
```
047. 文字編輯器
輸入說明
第一行輸入一個整數M, N， M是原始文章行數，N是編輯指令數
其後M行，每一行為原始句子，以空白隔開每個字
其後N行，每一行的第一個字串為編輯指令，隨後為對應的控制字串，以空白隔開
文章不會包含標點符號，第幾行、第幾個字都是從1開始算
編輯指令說明：

ADD_W_FRONT i n word	# 在第i行中，第n個字前面加上word
ADD_W_AFTER i n word	# 在第i行中，第n個字後面加上word
ADD_S_FRONT i sentence	# 在第i行前面加入一句sentence
ADD_S_AFTER i sentence	# 在第i行後面加入一句sentence
INSERT_FRONT key word	# 在文章中所有key前面加上word
INSERT_AFTER key word	# 在文章中所有key的後面加上word
DEL_W i n	# 刪除第i行中，第n個字
DEL_L i	# 刪除第i行 (請注意其他行的行數，可能被此指令影響)
REPLACE old new	# 將文章中所有old替換為new (區分大小寫)
COUNT	# 輸出目前文章總計字數

輸出說明
輸出編輯完成之文章

範例：
輸入:
5 6
Morning mom	# 第1行
Morning dear	# 第2行
What is for breakfast	# 第3行
Here are your eggs and milk	# 第4行
Looks good	# 第5行
INSERT_FRONT Morning Good	# 1 -> Good Morning mom 2 -> Good Morning dear
REPLACE Morning night	# 1 -> Good night mom 2 -> Good night dear
DEL_L 1	# 刪除第一行，其他行數-1
DEL_W 1 3	# 刪除 dear 1 -> Good night
ADD_S_AFTER 4 thanks mom	# 4 -> Looks good thanks mom
COUNT	# 輸出當前總字數



輸出：
16
Good night
What is for breakfast
Here are your eggs and milk
Looks good thanks mom

Sample input 1
4 5
Loving can hurt
Loving can hurt sometimes
It is the only thing makes us feel alive
we keep this love in a photograph
DEL_L 1
DEL_L 2
ADD_S_FRONT 2 Maybe
INSERT_FRONT hurt not
COUNT

Sample output 1
13
Loving can not hurt sometimes
Maybe we keep this love in a photograph

Sample input 2
3 3
Once I was seven years old
my mama told me
mama love me
REPLACE mama daddy
INSERT_AFTER daddy and
INSERT_AFTER and mama

Sample output 2
Once I was seven years old
my daddy and mama told me
daddy and mama love me

Sample input 3
3 5
Who lives in a pineapple in the sea
Absorbent yellow and porous is he
Nautical nonsense be something you wish
DEL_W 1 6
ADD_W_FRONT 3 1 Who
ADD_W_AFTER 1 5 under
REPLACE Who You
ADD_S_AFTER 3 it
Sample output 3
You lives in a pineapple under the sea
Absorbent yellow and porous is he
You Nautical nonsense be something you wish it

Sample input 4
1 2
you your your
REPLACE your you
INSERT_FRONT you are

Sample output 4
are you are you are you

Sample input 5
1 1
Do you wanna build a snow man
ADD_W_AFTER 1 5 fat

Sample output 5
Do you wanna build a fat snow man
```
:::
# 48
:::spoiler

```
048. 圈叉遊戲

Player與Computer下棋，未下處標0 ，Player標 1，Computer標 2。
依序輪流下，直到有一方在棋盤上的橫縱軸或斜線，達成三個1或三個2的連線或平手時，遊戲結束。

九宮格位置以九個數字表示如下。
1 | 2 | 3
————
4 | 5 | 6
————
7 | 8 | 9

輸入說明：
第一行輸入一個正整數M， 1 <= M <= 2。
M = 1 代表 Player先下，2代表Computer先下。
第二行代表Player和Computer輪流下的位置，以空白隔開。
若有錯誤輸入，需忽略，如：重複位置

輸出說明：
第一行，若輸入有錯誤，請輸出Error，否則輸出OK
第二、三、四行，輸出目前棋盤狀況，格式如下：
1 2 1
2 1 2
1 0 0
* 若其中一方先行勝利，則棋盤不必顯示後續的步數狀況
第五行，輸出遊戲結果
若Player獲勝，輸出Player win
若Computer獲勝，輸出Computer win
若雙方平手(已下滿9格且沒有任何一方獲勝)，輸出Tie
若未分勝負，輸出Undecided

第六行，若未分勝負，則輸出Computer應該下在哪個位置最有利，以數字 1-9 表示。

注意:
* 最有利點：可以達成自己連線、可以阻擋對手連線、可以幫助自己連線。
* 分出勝負後的錯誤無需考慮

範例：

Input:
1 #玩家先下
1 4 2 8 2 3 6 7 # 步數

Output：
Error # 第5步，2已下過，忽略並輸出Error
1 1 1
2 0 0
0 2 0
Player win # Player在第5步完成連線(1 2 3)，
後續步數(6, 7)無須顯示在棋盤上


Sample Input 1：
2
8 5 2 1 7 9

Sample Output 1：
OK
1 2 0
0 1 0
2 2 1
Player win

Sample Input 2：
2
9 3 4 7 6 5

Sample Output 2：
OK
0 0 1
2 1 2
1 0 2
Player win

Sample Input 3：
1
3 5 1 2 8 6 4 9 7

Sample Output 3：
OK
1 2 1
1 2 2
1 1 2
Player win

Sample Input 4：
1
2 1 4 3 6 5 7 8 9

Sample Output 4：
OK
2 1 2
1 2 1
1 2 1
Tie

Sample Input 5：
2
5 1 7 3 2 8 6 9 4

Sample Output 5：
OK
1 2 1
2 2 2
2 1 1
Computer win

Sample Input 6 ：
1
7 5 9 8 1 2


Sample Output 6：
OK
1 2 0
0 2 0
1 2 1
Computer win

Sample Input 7：
1
2 5 1 3 8 7

Sample Output 7：
OK
1 1 2
0 2 0
2 1 0
Computer win

Sample Input 8 :
2
5 2 9 3 1

Sample Output 8：
OK
2 1 1
0 2 0
0 0 2
Computer win

Sample Input 9：
2
5 6 2 8 7 3 9 1 4

Sample Output 9：
OK
1 2 1
2 2 1
2 1 2
Tie

Sample Input 10：
1
5 8 1 9 3

Sample Output 10：
OK
1 0 1
0 1 0
0 2 2
Undecided
7

Sample Input 11：
2
6 5 9 7

Sample Output 11：
OK
1 0 0
0 1 2
1 0 2
Undecided
3

Sample Input 12：
1
2 3 4 7 8

Sample Output 12：
OK
0 1 2
1 0 0
2 1 0
Undecided
5

Sample Input 13：
2
5 2 1 4

Sample Output 13：
OK
2 1 0
1 2 0
0 0 0
Undecided
9

Sample Input 14：
1
7 5 8

Sample Output 14：
OK
0 0 0
0 2 0
1 1 0
Undecided
9

Sample Input 15：
2
5 3 7 9

Sample Output 15：
OK
0 0 1
0 2 0
2 0 1
Undecided
6

Sample Input 16：
1
3 4 7

Sample Output 16：
OK
0 0 1
2 0 0
1 0 0
Undecided
5

Sample Input 17：
2
2 5 4 9

Sample Output 17：
OK
0 2 0
2 1 0
0 0 1
Undecided
1
```
:::

# 49 文字編輯器 II
:::spoiler
```
輸入說明
第一行輸入一個整數M, N， M是原始文章行數，N是編輯指令數。
其後M行，每一行為原始句子，以空白隔開每個字
其後N行，每一行的第一個字串為編輯指令，
隨後為對應的控制字串，以空白隔開：

Note:
文章不會包含標點符號，
第幾行、第幾個字都是從1開始算；
COPY_L和COPY共用同一個剪貼簿，兩種COPY指令都會將原先剪貼簿中的資料覆蓋；
PASTE必會在COPY後使用，無需考慮直接PASTE的情形；
INSERT，REPLACE 請注意要插入/替換文章中所有符合的字

ADD_W_FRONT i n word # 在第i行中，第n個字前面加上word
ADD_W_AFTER i n word # 在第i行中，第n個字後面加上word
ADD_S_FRONT i sentence # 在第i行前面加入一句sentence (多個word以空白隔開)
ADD_S_AFTER i sentence # 在第i行後面加入一句sentence (多個word以空白隔開)
INSERT_FRONT key word # 在文章中所有key前面加上word
INSERT_AFTER key word # 在文章中所有key的後面加上word
DEL_W i n # 刪除第i行中，第n個字
DEL_L i # 刪除第i行 (請注意其他行的行數，可能被此指令影響)
REPLACE old new # 將文章中所有old替換為new (區分大小寫)
COPY_L i # 複製第i行，並將原先在剪貼簿中的資料覆蓋
COPY i n # 複製第i行的第n個字，並將原先在剪貼簿中的資料覆蓋
PASTE_FRONT i n # 貼上於第i行，第n個字前
PASTE_AFTER i n # 貼上於第i行，第n個字後
COUNT # 統計，並輸出文章總單字數

輸出說明
輸出編輯完成之文章

範例：

輸入：
5 10
Morning mom # 第1行
Morning dear # 第2行
What is for breakfast # 第3行
Here are your eggs and milk # 第4行
Looks good # 第5行
INSERT_FRONT Morning Good # 1 -> Good Morning mom 2 -> Good Morning dear
REPLACE Morning night # 1 -> Good night mom 2 -> Good night dear
DEL_L 1 # 刪除第一行，其他行數-1
DEL_W 1 3 # 刪除 dear 1 -> Good night
ADD_S_AFTER 4 thanks mom # 4 -> Looks good thanks mom
COPY_L 1 # copy “Good night”
PASTE_AFTER 4 4 # 4-> Looks good thanks mom Good night
COPY 4 4 # copy “mom”
PASTE_FRONT 2 1 # 2 -> mom What is for breakfast
COUNT # 輸出文章單字數

輸出：
19
Good night
mom What is for breakfast
Here are your eggs and milk
Looks good thanks mom Good night

Sample Input 1
4 7
Loving can hurt
Loving can hurt sometimes
It is the only thing makes us feel alive
we keep this love in a photograph
DEL_L 1
DEL_L 2
ADD_S_FRONT 2 Maybe
INSERT_FRONT hurt not
COPY 1 2
PASTE_AFTER 2 2
COUNT

Sample Output 1
14
Loving can not hurt sometimes
Maybe we can keep this love in a photograph

Sample Input 2
5 6
I have a
pen
apple
Ugh
apple
COPY_L 1
DEL_L 1
PASTE_FRONT 1 1
PASTE_FRONT 2 1
COPY 1 4
PASTE_AFTER 4 1

Sample Output 2
I have a pen
I have a apple
Ugh
apple pen

Sample Input 3
5 15
Once I was seven years old
my mama told me
mama love me
my
and my
COPY_L 3
REPLACE mama daddy
INSERT_AFTER daddy and
INSERT_AFTER and mama
PASTE_AFTER 4 1
PASTE_AFTER 5 3
DEL_W 4 2
DEL_W 5 2
DEL_W 5 3
ADD_W_AFTER 4 1 sister
ADD_W_AFTER 5 2 grandma
ADD_W_AFTER 5 5 ha
COPY 5 6
PASTE_FRONT 5 6
PASTE_AFTER 5 6

Sample Output 3
Once I was seven years old
my daddy and mama told me
daddy and mama love me
my sister love me
and my grandma love me ha ha ha

Sample Input 4
6 15
You lives in a pineapple in the sea
Who
Absorbent and yellow and porous is he
Spongebob
nautical nonsense be something
Squarepants
DEL_W 1 6
ADD_W_FRONT 5 1 If
ADD_W_AFTER 1 5 under
COPY 6 1
PASTE_AFTER 4 1
COPY 4 1
PASTE_FRONT 6 1
COPY 6 2
PASTE_AFTER 2 1
DEL_W 2 1
COPY 4 1
PASTE_FRONT 2 1
REPLACE You Who
ADD_S_AFTER 5 you wish
COUNT

Sample Output 4
28
Who lives in a pineapple under the sea
Spongebob Squarepants
Absorbent and yellow and porous is he
Spongebob Squarepants
If nautical nonsense be something you wish
Spongebob Squarepants

Sample Input 5
4 3
i my me
you your your
he his him
she her her
COPY 2 3
COPY_L 1
PASTE_FRONT 3 1

Sample Output 5
i my me
you your your
i my me he his him
she her her
```
:::
# 50
:::spoiler
```
050 會議安排

某公司有數間大小不同的會議室，可容納的人數不同，使用會議前需要各單位登記舉辦會議時間，會議室24小時開放，每個會議有不同的使用時間。由於會議眾多，可能發生時間衝突或會議人數超過會議室可容納人數上限，總務部門需從這些會議中，選取時間上不衝突，且可以容納會議人數的會議室，讓他們能夠如願使用會議室。公司希望所有會議室能做最有效的利用。

另外公司政策表明，為避免與會來賓需頻繁更換會議室，
每一場會議要安排在能容納會議人數的會議室，且一定要在同一個會議室
(詳細說明請看範例2)

輸入說明：
第一行輸入兩個整數M, N，M是會議室間數，N是申請舉辦會議個數。
其中 1 <= M <= 4 ， 1 <= N <= 10 。
其後M行，每一行有兩個正整數以空白隔開，代表會議室編號、可容納人數；
其後N 行，每一行有四個正整數以空白隔開，代表每一個申請會議的編號、會議人數、開始時間(0-23)、結束時間(1-24)。

時間以0代表凌晨12點，18代表下午六點，24代表半夜12點
例如：
101 90 1 4 # 會議101 有90人，使用1點到4點
202 60 3 15 # 會議202 有60人，使用3點到15點

輸出說明：
從所有的會議中，計算出總時長最高，
且人數可被容納的會議安排，並輸出會議總時長。
(注意：時長最長之安排，會議人數不一定合法)


範例輸入 1：
2 4 # 有2間會議室，4場會議要安排
1101 90 # 會議室 1101 可容納90人
2102 60 # 會議室 2102 可容納60人
101 90 1 4 # 會議101 90人 時間為1-4點
102 60 1 3 # 會議102 60人 時間為1-3點
103 60 4 5 # 會議103 60人 時間為4-5點
104 90 1 5 # 會議104 90人 時間為1-5點

此時可安排會議 101, 102, 103
101 安排至 1101，102 安排至 2102，103 安排至 1101，
會議總時長為 3 + 2 + 1 = 6；
或是可安排會議 102, 103, 104；
102 安排至 2102，103 安排至 2102，104 安排至 1101，
會議總時長為 2 + 1 + 4 = 7
時間上也可安排會議 101, 103, 104，會議總時長為 3 + 1 + 4 = 8；
但會議101, 104都必須使用90人的1101會議室，
導致時間衝突(101: 1-4, 104: 1-5)，
故無法安排因此最長會議時數為應該為 7

範例輸出 1：
7

範例輸入 2：
3 6
1101 90
2101 60
3101 30
101 60 1 4
102 60 1 6
103 30 4 9
104 90 6 9
105 60 7 9
106 30 3 7

若每一場會議，不同小時可以被安排在能容納會議人數，不同的會議室，
那就可透過安排103會議的不同小時在不同會議室舉行，來最大化會議時數；
此時會議總時長為22，但103會議的與會者，就需要跑1101, 2101, 3101，3間會議室，為避免讓與會者留下不好的印象，因此公司不希望如此安排。

https://i.imgur.com/lCG7ANN.jpg

因此依照公司政策：每一場會議要安排在能容納會議人數的會議室，且一定要在同一個會議室，最長會議總時為20，安排如下：

https://i.imgur.com/a6LoeDr.jpg


範例輸出 2：
20

Sample Input 1
1 4
2101 60
104 60 1 5
102 90 1 8
101 60 3 6
103 60 1 6

Sample Output 1
5

Sample Input 2
3 6
1101 50
2101 80
3101 40
102 80 1 5
104 60 1 3
103 50 1 3
105 40 5 9
106 60 1 19
101 70 3 4

Sample Output 2
24

Sample Input 3
4 4
2103 50
1102 80
3104 60
4105 100
104 50 1 9
103 70 3 7
102 30 2 8
101 60 4 6

Sample Output 3
20

Sample Input 4
0 2
101 5 0 2
102 3 22 24

Sample Output 4
0

Sample Input 5
2 0
1101 50
2101 80

Sample Output 5
0

Sample Input 6
4 4
1101 10
2101 5
3101 15
4101 20
101 30 1 5
103 50 1 5
104 100 3 5
102 25 8 10

Sample Output 6
0

Sample Input 7
2 5
2103 50
1102 60
104 50 1 2
102 50 3 4
103 50 5 6
101 50 7 8
106 60 0 23

Sample Output 7
27

Sample Input 8
4 6
1101 70
2101 60
3102 80
4103 90
104 50 1 2
102 90 3 4
101 70 7 8
105 80 15 24
109 60 0 5
108 70 19 24

Sample Output 8
22
```
:::
