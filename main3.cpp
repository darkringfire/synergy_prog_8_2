#include <iostream>
#include <regex>

using namespace std;

int parse(const string& str) {
    const regex r(R"(\s*(-?\d+)\s*([-+*/])\s*(-?\d+)\s*)");
    smatch m;

    if (regex_match(str, m, r)) {
        int x = stoi(m[1]), y = stoi(m[3]);
        string op = m[2];
        if (op == "+") {
            return x + y;
        } else if (op == "-") {
            return x - y;
        } else if (op == "*") {
            return x * y;
        } else if (op == "/") {
            if (y == 0) {
                throw invalid_argument("dividing by zero");
            }
            return x / y;
        } else {
            throw invalid_argument("Unknown operator");
        }
    } else {
        throw invalid_argument("Incorrect input");
    }
    return 0;
}

int main() {
    string in_str;
    cout << "Enter expression \"X ? Y\" or empty line to exit" << endl;
    cout << "X and Y are numbers, ? is operator +, -, * or /" << endl;
    do {
        cout << "expr>" << flush;
        getline(cin, in_str);
        try {
            int res = parse(in_str);
            cout << "=" << res << endl;
        } catch (const invalid_argument &e) {
            cout << "Error! " << e.what() << endl;
        }

    } while (!in_str.empty());
    cout << "Good bye!";
}
