#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void insertText(const string& newText) {
        undoStack.push(text);
        text += newText;
        redoStack = stack<string>(); // Clear redo stack after new action
    }

    void deleteLastCharacter() {
        if (!text.empty()) {
            undoStack.push(text);
            text.erase(text.size() - 1);
            redoStack = stack<string>(); // Clear redo stack after new action
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();
        }
    }

    const string& getText() const {
        return text;
    }
};

int main() {
    TextEditor editor;

    editor.insertText("Hello, ");
    cout << "Text: " << editor.getText() << endl;

    editor.insertText("World!");
    cout << "Text: " << editor.getText() << endl;

    editor.deleteLastCharacter();
    cout << "Text: " << editor.getText() << endl;

    editor.undo();
    cout << "Text (after undo): " << editor.getText() << endl;

    editor.redo();
    cout << "Text (after redo): " << editor.getText() << endl;

    return 0;
}
