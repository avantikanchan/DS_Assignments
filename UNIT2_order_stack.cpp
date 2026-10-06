#include <iostream>
#include <stack>
#include <string>

int main() {
    // Create a stack to store order numbers
    std::stack<std::string> cancelledOrders;

    // Simulate storing 5 cancelled orders (oldest to newest)
    cancelledOrders.push("ORD1001");
    cancelledOrders.push("ORD1002");
    cancelledOrders.push("ORD1003");
    cancelledOrders.push("ORD1004");
    cancelledOrders.push("ORD1005"); // Most recently cancelled

    std::cout << "--- Cancelled Orders (Most Recent First) ---\n";

    // Process and display orders until the stack is empty
    while (!cancelledOrders.empty()) {
        // Display the top element (most recent)
        std::cout << "Order Number: " << cancelledOrders.top() << "\n";
        
        // Remove the top element to access the next one
        cancelledOrders.pop();
    }

    return 0;
}
