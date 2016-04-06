#include "utils.h"

class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
            
        int num = 0;
        stack<int> st;
        char op = '+';
        for(int i = 0; i < s.size(); i++) {

			//cout<<s[i]<<endl;
            
            if(isdigit(s[i])) {
                int si = s[i] - '0';
                num = num*10 + si;
            }

            if((!isdigit(s[i]) && s[i] != ' ')||i == s.size() -1) {
                if(op == '+') {
					//cout<<num<<endl;
                    st.push(num);
                }
                if(op == '-') {
					cout<<s[6]<<endl;
					cout<<i<<" "<<num<<endl;
                    st.push(-num);
                }
                if(op == '*') {
                    int pushval = st.top() * num;
					//cout<<st.top() <<"*"<<num<<endl;
                    st.pop();
                    st.push(pushval);
					//cout<<pushval<<endl;
                }
                if(op == '/') {
                    int pushval = st.top() / num;
					//cout<<st.top() <<"/"<<num<<endl;
                    st.pop();
                    st.push(pushval);
					//cout<<pushval<<endl;
                }
                
                op = s[i];
                num = 0;
                    
            }
        
        }
        
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
        
    }
}; 

int main(void)
{
	Solution sol;

	string evstr = "3 - 2 * 2";

	cout<<sol.calculate(evstr);

	return 0;
}

