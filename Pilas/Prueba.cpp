#include <iostream>
#include <stack>
#include <queue>
#include <string>

std::stack<int> reverseStack(std::stack<int> originalStack)
{
    std::stack<int> reversedStack;

    while (!originalStack.empty())
    {
        reversedStack.push(originalStack.top());
        originalStack.pop();
    }

    return reversedStack;
}

std::stack<int> add(std::stack<int> a, std::stack<int> b) {
    std::stack<int> result;
    int carry = 0; 
    int sum;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;

        if (!a.empty()) {
            sum += a.top();
            a.pop();
        }

        if (!b.empty()) {
            sum += b.top();
            b.pop();
        }

        carry = sum / 10;  
        sum = sum % 10;

        result.push(sum);
    }

    return reverseStack(result);
}

std::stack<int> subtract(std::stack<int> a, std::stack<int> b)
{
    std::stack<int> result;
    int borrow = 0;
    int diff;

    while (!a.empty() || !b.empty() || borrow) {
        diff = borrow;

        if (!a.empty()) {
            diff += a.top();
            a.pop();
        }

        if (!b.empty()) {
            diff -= b.top();
            b.pop();
        }

        if (diff < 0) {
            borrow = -1;
            diff += 10;
        } else {
            borrow = 0;
        }

        result.push(diff);
    }

    return reverseStack(result);
}

std::stack<int> readNumber(std::string number)
{
    std::stack<int> result;
    for (int index = 0; index < number.size(); index++)
    {
        int digit = number[index] - '0';
        result.push(digit);
    }
    return result; 
}

void displayNumber(std::stack<int> stack)
{
    std::stack<int> tempStack = reverseStack(stack);
    while (!tempStack.empty())
    {
        std::cout << tempStack.top();
        tempStack.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::string num1, num2;
    std::cout << "Enter the first long number: ";
    std::cin >> num1;
    std::cout << "Enter the second long number: ";
    std::cin >> num2;

    std::stack<int> stack1 = readNumber(num1);
    std::stack<int> stack2 = readNumber(num2);

    std::cout << "Number 1: ";
    displayNumber(stack1);
    std::cout << "Number 2: ";
    displayNumber(stack2);

    std::stack<int> sum = add(stack1, stack2);
    std::cout << "Sum result: ";
    displayNumber(sum);

    std::stack<int> difference = subtract(stack1, stack2);
    std::cout << "Difference result: ";
    displayNumber(difference);

    return 0;
}