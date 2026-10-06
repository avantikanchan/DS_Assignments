#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int token;

    cout << "Enter 5 customer token numbers:\n";

    for(int i = 0; i < 5; i++)
    {
        cin >> token;
        s.push(token);
    }

    cout << "\nService history (most recent first):\n";

    while(!s.empty())
    {
        cout << "Token: " << s.top() << endl;
        s.pop();
    }

    return 0;
}
