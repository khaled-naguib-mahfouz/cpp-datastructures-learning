#include <iostream>
#include <stack>
#include <string>

using namespace std;

class WebBrowser {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentUrl;

public:
    WebBrowser() {
        currentUrl = "www.homepage.com";
    }

    void visitPage(const string& url) {
        backStack.push(currentUrl);
        forwardStack = stack<string>(); // Clear forward stack
        currentUrl = url;
    }

    void goBack() {
        if (!backStack.empty()) {
            forwardStack.push(currentUrl);
            currentUrl = backStack.top();
            backStack.pop();
        } else {
            cout << "Cannot go back. Back stack is empty.\n";
        }
    }

    void goForward() {
        if (!forwardStack.empty()) {
            backStack.push(currentUrl);
            currentUrl = forwardStack.top();
            forwardStack.pop();
        } else {
            cout << "Cannot go forward. Forward stack is empty.\n";
        }
    }

    void displayCurrentPage() const {
        cout << "Current Page: " << currentUrl << endl;
    }
};

int main() {
    WebBrowser browser;

    browser.displayCurrentPage();

    browser.visitPage("www.example.com");
    browser.displayCurrentPage();

    browser.visitPage("www.example.com/page1");
    browser.displayCurrentPage();

    browser.visitPage("www.example.com/page2");
    browser.displayCurrentPage();

    browser.goBack();
    browser.displayCurrentPage();

    browser.goForward();
    browser.displayCurrentPage();

    browser.goForward();
    browser.displayCurrentPage();

    return 0;
}
