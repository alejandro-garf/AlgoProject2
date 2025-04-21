#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Calculates wait times to the next house with more candies.
 * @param houseCandies - A vector representing candies at each house.
 * @return A vector where each element indicates houses to wait for more candies.
 */

vector<int> calculateWaitHouses(const vector<int>& houseCandies) {
    int n = houseCandies.size();
    vector<int> waitHouses(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && houseCandies[i] > houseCandies[st.top()]) {
            int idx = st.top();
            st.pop();
            waitHouses[idx] = i - idx;
        }
        st.push(i);
    }

    return waitHouses;
}

int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> houseCandies(n);
    cout << "Enter candies for each house:\n";
    for (int i = 0; i < n; i++) {
        cin >> houseCandies[i];
    }

    vector<int> result = calculateWaitHouses(houseCandies);

    cout << "Wait times:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
