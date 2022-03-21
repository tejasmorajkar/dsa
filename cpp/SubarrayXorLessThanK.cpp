#include <bits/stdc++.h>

using namespace std;

struct Node{
    int one, zero;
    Node *left, *right;
    Node(){
        one = zero = 0;
        left = NULL;
        right = NULL;
    }
};

void add(Node *root, int num ){
    for( int i = 20; i >= 0; i-- ){
        int bit = (num>>i)&1;
        if( bit ){
            if( root->right == NULL )
                root->right = new Node();
            
            root->one++;
            root = root->right;
        }
        else{
            if( root->left == NULL )
                root->left = new Node();
            root->zero++;
            root = root->left;
        }
    }
}

int query( Node *root, int num, int k ){
    int sum = 0;
    for( int i = 20; i >= 0; i-- ){
        if( root == NULL )return sum;
        int have = (num>>i)&1;
        int req = (k>>i)&1;
        //cout << "(" << req << "," << have << ") ";
        if( req == 1){
            if( have == 1 ){ // 1 all 1 add
                sum += root->one;
                root = root->left;
            }
            else{ // 0 all 0 add 
                sum += root->zero;
                root = root->right;
            }
        }
        else{
            if( have == 1 ) root = root->right;
            else root = root->left;
        }
    }
    return sum;
}

int solve(vector<int> &A, int B) {
    int pre = 0;
    Node *root = new Node();  
    add(root, 0);
    long long sum = 0;
    for( auto num : A ){
        pre ^= num;
        sum += query(root, pre, B);
        add(root, pre);
        sum %= 1000000007;
    }
    return sum;
}

int main() {
	vector<int> A = {8, 3, 10, 2, 6, 7, 6, 9, 3};
	int B = 3;
	int ans = solve(A, B);
	cout << ans << "\n";
	return 0;
}