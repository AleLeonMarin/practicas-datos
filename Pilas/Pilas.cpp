#include <iostream>
#include <stack>

using namespace std;

stack<int> longToStack(int n) {
    stack<int> s;

    while (n > 0) {
        s.push(n % 10);
        n = n / 10;
    }

    return s;
}

stack<int> reverseStack(stack<int>& originalStack) {
    stack<int> reversedStack;

    while (!originalStack.empty()) {
        reversedStack.push(originalStack.top());
        originalStack.pop();
    }

    return reversedStack;
}

void show(stack<int> s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

void sum(int n, int m) {
    stack<int> s1 = longToStack(n);
    stack<int> s2 = longToStack(m);
    stack<int> result;
    int sum;
    int carry = 0;

    // Sumar los dígitos mientras ambas pilas tengan elementos
    while (!s1.empty() || !s2.empty() || carry) {
        sum = carry;
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        carry = sum / 10;
        sum = sum % 10;

        result.push(sum);
    }

    // Invertir la pila resultante antes de mostrarla
    stack<int> reversedResult = reverseStack(result);

    // Mostrar la suma
    cout << "The sum is: ";
    show(reversedResult);
}

int main() {
    int n = 12345678910; int m = 11121314156;

  
   sum(n, m);

    return 0;
}
