Question1 : Sheldon is alone in the apartment as the other boys have left for Antarctica for a research project. He is feeling lonely and is not doing well. Penny notices it and asks Sheldon if he is willing to have a break and go to the amusement park. Sheldon agrees to it and is overjoyed.
As they enter the amusement park, they see there are multiple rides and games on their left and right-hand side. The price for each of them is placed next to them. They also notice that some of the games are complimentary. Sheldon has M amount of money with him. Sheldon looks at Penny and smirks and they have the below conversation.
Sheldon: If you can show the basic elements of intelligence, you can continue using our free Wi-Fi.

Penny: What?

Sheldon: You see there are rides and games on both sides. They all have prices placed next to them and are in a sequential manner. Do you see it?

Penny: Yes, Sheldon. What's the point?

Sheldon: I have M amount of money with me. If you can give me the maximum number of rides and games we can go to, you can continue using our Wi-Fi which you are already using. Oh, but it is not going to be so easy. Since the rides are in a sequential manner, you have to follow that on both sides. 

Penny: I am confused.

Sheldon: Of course, you are! I would have been amused if you would have got it. Here is an example to help you.


Example:

Amount of money with Sheldon, M = 20

Price of Rides on the left side = { 5, 3, 6, 8, 10, 20} 

Price of Rides on the right side = { 4, 4, 4, 6, 7, 10, 4, 8 }


Pick the first three rides from the right side, Price = 4 + 4 + 4 = 12

Pick the first two rides from the left side, Price = 5 + 3 = 8


Total money = 12 + 8 = 20


This is the money we have. The maximum number of rides we can take is 5.

Do you get it now, Penny?


Penny: (*Still not clear) YES! Do you think only you are a genius?

Sheldon: Great. Prove me wrong.


Penny does not like being humiliated by Sheldon but is still confused about what Sheldon said. To top it off, she is bad at calculations. She wants to get the correct answer so she can keep enjoying the free Wi-Fi and get back at Sheldon. Can you help Penny get the right answer?

Solution in C++ :

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRides(vector<int>& left, vector<int>& right, int M) {
    int n = left.size();
    int m = right.size();

    // Compute prefix sums
    vector<long long> leftPrefix(n + 1, 0);
    vector<long long> rightPrefix(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        leftPrefix[i] = leftPrefix[i - 1] + left[i - 1];
    }
    for (int j = 1; j <= m; j++) {
        rightPrefix[j] = rightPrefix[j - 1] + right[j - 1];
    }

    // Initialize the maximum number of rides
    int maxRides = 0;
    int j = m;

    // Iterate over the left prefix sums
    for (int i = 0; i <= n; i++) {
        if (leftPrefix[i] > M) break;
        while (j > 0 && leftPrefix[i] + rightPrefix[j] > M) {
            j--;
        }
        maxRides = max(maxRides, i + j);
    }

    return maxRides;
}

int main() {
    ios::sync_with_stdio(false); // For faster I/O
    cin.tie(nullptr); // For faster I/O

    int T;
    cin >> T;

    while (T--) {
        int L, R, M;
        cin >> L;
        vector<int> left(L);
        for (int i = 0; i < L; i++) {
            cin >> left[i];
        }

        cin >> R;
        vector<int> right(R);
        for (int i = 0; i < R; i++) {
            cin >> right[i];
        }

        cin >> M;

        cout << maxRides(left, right, M) << endl;
    }

    return 0;
}

