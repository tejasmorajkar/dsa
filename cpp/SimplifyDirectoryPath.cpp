#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string simplifyPath(string A) {
    string ans = "/";
    vector<string> s;
    string word;
    istringstream stream(A);
    while(getline(stream,word,'/')){
        if(word == "." || word == ""){
            continue;
        }
        else if( word == ".." ){
            if(s.size() > 0) s.pop_back();
        }
        else s.push_back(word);
    }
    int i=0;
    while(i<s.size()){
        ans += s[i++];
        if(i < s.size()) ans.push_back('/');
    }
    return ans;
}

int main() {
    string A = "/./../../giq/xns/zvk/../vkd/qhp/pyf/wie/atv/thv/./kqs/seq/fzw/cav/./../.././rjn/elx/gyn/lla/gkd/zig/qud/vyx/./eqd/ple/vst/loc/./../uak/wvz/vxe/ibc/../bns/psb/./kjo/bky/oks/./cjg/yyh/spf/abt";
    string ans = simplifyPath(A);
    cout << ans << "\n";
    return 0;
}