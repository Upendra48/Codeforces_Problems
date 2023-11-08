/*

Polycarp has spent the entire day preparing problems for you. Now he has to sleep for at least a
 minutes to feel refreshed.

Polycarp can only wake up by hearing the sound of his alarm. So he has just fallen asleep and his first alarm goes off in b
 minutes.

Every time Polycarp wakes up, he decides if he wants to sleep for some more time or not. If he's slept for less than a
 minutes in total, then he sets his alarm to go off in c
 minutes after it is reset and spends d
 minutes to fall asleep again. Otherwise, he gets out of his bed and proceeds with the day.

If the alarm goes off while Polycarp is falling asleep, then he resets his alarm to go off in another c
 minutes and tries to fall asleep for d
 minutes again.

You just want to find out when will Polycarp get out of his bed or report that it will never happen.

Please check out the notes for some explanations of the example.

Input
The first line contains one integer t
 (1≤t≤1000
) — the number of testcases.

The only line of each testcase contains four integers a,b,c,d
 (1≤a,b,c,d≤109
) — the time Polycarp has to sleep for to feel refreshed, the time before the first alarm goes off, 
the time before every succeeding alarm goes off and the time Polycarp spends to fall asleep.

Output
For each test case print one integer. If Polycarp never gets out of his bed then print -1. 
Otherwise, print the time it takes for Polycarp to get out of his bed.

Example
inputCopy
7
10 3 6 4
11 3 6 4
5 9 4 10
6 5 2 3
1 1 1 1
3947465 47342 338129 123123
234123843 13 361451236 361451000
outputCopy
27
27
9
-1
1
6471793
358578060125049
Note
In the first testcase Polycarp wakes up after 3
 minutes. He only rested for 3
 minutes out of 10
 minutes he needed. So after that he sets his alarm to go off in 6
 minutes and spends 4
 minutes falling asleep. Thus, he rests for 2
 more minutes, totaling in 3+2=5
 minutes of sleep. Then he repeats the procedure three more times and ends up with 11
 minutes of sleep. Finally, he gets out of his bed. He spent 3
 minutes before the first alarm and then reset his alarm four times. The answer is 3+4⋅6=27
.

The second example is almost like the first one but Polycarp needs 11
 minutes of sleep instead of 10
. However, that changes nothing because he gets 11
 minutes with these alarm parameters anyway.

In the third testcase Polycarp wakes up rested enough after the first alarm. Thus, the answer is b=9
.

In the fourth testcase Polycarp wakes up after 5
 minutes. Unfortunately, he keeps resetting his alarm infinitely being unable to rest for even a single minute :(

*/

#include <bits/stdc++.h>    // Include all c++ libraries
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a <= b){
            cout << b << endl;
        }
        else if(c <= d){
            cout << -1 << endl;
        }
        else{
            long long time = b;
            a -= b;
            time += (c * ((a + c - d - 1) / (c - d)));
            cout << time << endl;
        }
    }

    return 0;
}