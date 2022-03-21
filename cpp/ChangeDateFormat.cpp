#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string solve(string A)
{
    string result;
    istringstream iss(A);
    int date;
    string month;
    int year;
    int i = 0;
    string word;
    while(iss >> word)
    {
        if (i == 0) {       
            date = stoi(word);
        } else if (i == 1) {
            month = word;
        } else if (i == 2) {
            year = stoi(word);
        }
        i++;
    }
    unordered_map<string, string> month_map = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };
    string dd;
    if (date < 10) {
        dd = "0" + to_string(date);
    } else {
        dd = to_string(date);
    }
    result = to_string(year) + "-" + month_map[month] + "-" + dd;
    return result;
}

int main()
{
    string result = solve("1st Mar 2068");
    cout << result << endl;
    return 0;
}