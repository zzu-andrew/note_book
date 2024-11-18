#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <vector>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:

    /* Write Code Here */
    int calculate(vector < string > tokens) {
        std::stack<int> stack;



        for (const auto& token : tokens) {

            std::cout << "=======" << token[0] << std::endl;
            // 正数或者负数两种情况
            if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {

                stack.push(std::stoi(token));
            } else {
                std::cout << "------"<< std::endl;
                int rOp = stack.top();
                stack.pop();
                int lOp = stack.top();
                stack.pop();

                switch (token[0]) {
                    case '+':
                        stack.push(rOp + lOp);
                        break;
                    case '-':
                        stack.push(rOp - lOp);
                        break;
                    case '*':
                        stack.push(rOp * lOp);
                        break;
                    case '/':
                        stack.push(rOp / lOp);
                        break;
                    default:
                        std::cerr << "Unexpected error" << std::endl;
                }
            }
        }
        return stack.top();
    }
};

int main() {
    int res;

    int tokens_size = 0;
    cin >> tokens_size;
    vector<string> tokens;
    string tokens_item;
    for(int tokens_i=0; tokens_i<tokens_size; tokens_i++) {
        getline(cin, tokens_item);
        tokens.push_back(tokens_item);
    }
    for (const auto& token : tokens) {
        std::cout << "======" << token << std::endl;
    }

    Solution *s = new Solution();
    res = s->calculate(tokens);
    cout << res << endl;

    return 0;

}
