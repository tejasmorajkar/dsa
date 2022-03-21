#include <bits/stdc++.h>
using namespace std;

class DiscountTag {
public:
    int type;
    double amt;
};

int findLowestPrice(vector<vector<string>> products, vector<vector<string>> discounts) {
    unordered_map<string, DiscountTag> discount_map;
    for (int i = 0; i < discounts.size(); i++) {
        DiscountTag dt;
        dt.type = stoi(discounts[i][1]);
        dt.amt = stod(discounts[i][2]);
        discount_map[discounts[i][0]] = dt;
    }
    int ans = 0;
    for (int i = 0; i < products.size(); i++) {
        double price = stod(products[i][0]);
        double dis_price = price;
        for (int j = 1; j < products[i].size(); j++) {
            string tag = products[i][j];
            if (discount_map.find(tag) != discount_map.end()) {
                int type = discount_map[tag].type;
                if (type == 0) {
                    dis_price = min(discount_map[tag].amt, dis_price);
                } else if (type == 1) {
                    double discount_percent = discount_map[tag].amt/100;
                    dis_price = min(dis_price, price - (price * discount_percent));
                } else if (type == 2) {
                    dis_price = min(dis_price, price - discount_map[tag].amt);
                }
            }
        }
        ans += (int)dis_price;
    }
    return ans;
}

int main() {
    vector<vector<string>> products = {{"10", "d0", "d1"}, {"15", "EMPTY", "EMPTY"}, {"20", "d1", "EMPTY"}};
    vector<vector<string>> discounts = {{"d0", "1", "27"}, {"d1", "2", "5"}};
    int ans = findLowestPrice(products, discounts);
    cout << ans << endl;
    return 0;
}