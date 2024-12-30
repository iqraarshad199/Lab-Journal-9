//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//class TNode {
//public:
//    char data;
//    TNode* left;
//    TNode* right;
//
//    TNode(char val) {
//        data = val;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//TNode* constructTree(string postfix) {
//    stack<TNode*> s;
//
//    for (char symbol : postfix) {
//        TNode* curr = new TNode(symbol);
//
//        if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
//            TNode* t2 = s.top(); s.pop();
//            TNode* t1 = s.top(); s.pop();
//
//            curr->left = t1;
//            curr->right = t2;
//        }
//
//        s.push(curr);
//    }
//
//    return s.top();
//}
//
//void postorder(TNode* root) {
//    if (root == nullptr) return;
//
//    postorder(root->left);
//    postorder(root->right);
//    cout << root->data;
//}
//
//int main() {
//    string postfix = "ab+ef*g*-";
//
//    TNode* root = constructTree(postfix);
//
//    cout << "\n\nPostorder traversal of the constructed tree: ";
//    postorder(root);
//    cout << endl;
//
//    return 0;
//}
