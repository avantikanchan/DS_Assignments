#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int choice, token;
    int nextToken = 1;

    do
    {
        cout << "\n--- BANK TOKEN SYSTEM ---\n";
        cout << "1. Issue Token\n";
        cout << "2. Display All Tokens\n";
        cout << "3. Serve Customer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                q.push(nextToken);
                cout << "Token issued: " << nextToken << endl;
                nextToken++;
                break;

            case 2:
                if(q.empty())
                {
                    cout << "No tokens available.\n";
                }
                else
                {
                    queue<int> temp = q;

                    cout << "All tokens: ";
                    while(!temp.empty())
                    {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 3:
                if(q.empty())
                {
                    cout << "No customer to serve.\n";
                }
                else
                {
                    cout << "Serving Token: " << q.front() << endl;
                    q.pop();
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
