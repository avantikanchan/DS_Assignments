#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int token;

    cout << "Enter 5 customer token numbers:\n";

    for(int i = 0; i < 5; i++)
    {
        cin >> token;
        q.push(token);
    }

    cout << "\nCustomers served in order:\n";

    while(!q.empty())
    {
        cout << "Serving Token: " << q.front() << endl;
        q.pop();
    }

    return 0;
}
