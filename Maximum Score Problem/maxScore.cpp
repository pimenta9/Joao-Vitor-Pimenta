/*
Problem:
    - You are taking a test with "n" questions.
    - Each question i (1 <= i <= n) is worth p[i] points
    - After answering a question i correctly, you get so tired 
that you have to skip the next f[i] questions.
    - What is the greatest score you can possibly get?
*/

#include <bits/stdc++.h>
using namespace std;

#define one_indexed -1

// EXAMPLE (you may change this example as you want)
int n = 5;
int p[] = {one_indexed, 1, 2, 3, 4, 5};
int f[] = {one_indexed, 2, 1, 0, 2, 1};

//      Returns the maximum score you can get
//  starting from the i-th question
int greatestScore(int i)
{
    // If i > n, that means there are no more
    // questions to be answered, thus, no more
    // points to be earned
    if (i > n) return 0;

    //  If the question i is one of the
    // questions you have to answer:
    int score1 = p[i] + greatestScore(i + f[i] + 1);
                        // skip f[i] questions

    //  If the question i is NOT one of the
    // questions you have to answer:
    int score2 = greatestScore(i + 1);

    // Return the path that gives us the greater score
    return max(score1, score2);
}

int main ()
{
    cout << greatestScore(1) << endl;

    return 0;
}
