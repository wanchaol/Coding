// "red green blue", "abc" --> true
// "red blue blue", "abc" --> false
// "red blue blue", "abb" --> true
// "red green blue", "abb" -> false
// "red green blue", "acb" --> true
// "red blue blue", "ab" --> false

// "redgreenblue", "abc" --> true
// "redgreenblue", "aaa" --> false
// "redbluered", "aba" --> true
// "redgreenr", "abc" --> true

#include "utils.h"

bool matchcode(string message, string code) {
    
    istringstream iss(message);
    string word;
    
    unordered_map<char, int> cmap;
    unordered_map<string, int> mmap;
    
    int codelength = code.size();
    int index = 1;
    
    while(iss >> word) {
        
        if(mmap[word] != cmap[code[index-1]])
            return false;
        
        mmap[word] = index;
        cmap[code[index-1]] = index;
        
        //mmap[red] = 1
        //cmap[a] = 1
        //mmap[blue] = 2
        //cmap[b] = 2
        //mmap[blue] = 3
        //cmap[c] = 3
        
        
        index ++;    
    }
    
    
    //index == 4, code == 3
    return codelength == index - 1;
    
    
}


bool matchcode_helper(vector<string> &message, string code) {
    
    unordered_map<char, int> cmap;
    unordered_map<string, int> mmap;
    
    int codelength = code.size();
    int index = 1;
    
    for(auto word: message) {
        
        if(mmap[word] != cmap[code[index-1]])
            return false;
        
        mmap[word] = index;
        cmap[code[index-1]] = index;
    
        
        index ++;    
    }
    
    //index == 4, code == 3
    return codelength == index - 1;
    
}




bool backtrack(string message, string code, vector<string> &partitions, int begin) {
    size_t codesize = code.size(); 
    
    if(codesize == partitions.size()) {
        //valid partition
		cout<<partitions<<endl;
		if (matchcode_helper(partitions, code)) {
			return true;
		}
		return false;
    }
    
    for(int i = begin + 1; i < message.size() + 1; ++ i) {
        string part = message.substr(begin, i-begin);
        //string remains = message.substr(i, message.size() - i);
		//cout<<part<<" "<<remains<<endl;
        partitions.push_back(part);
		if (backtrack(message, code, partitions, i)) {
			return true;
		}
        partitions.pop_back();
        
    }
    
	return false;
    
}


bool matchcodeii(string message, string code) {
    vector<string> partitions;

    return backtrack(message, code, partitions, 0);
    

// "redbluered", "aba" --> true

}





int main() {
    // vector<string> messages{"red green blue","red blue blue", "red blue blue", "red green blue",  "red green blue", "red blue blue" };
    // vector<string> codes {"abc", "abc", "abb", "abb", "acb", "ab"};
    
    // int testsize = messages.size();
    
    // for(int i = 0; i < testsize; ++ i) {
    //     string message = messages[i];
    //     string code = codes[i];
        
    //     cout<< matchcode(message, code)<<endl;
        
    // }
    
    // return 0;
    
    
	vector<string> messages{"redgreenblue","redgreenblue", "redbluered", "redgreenr"};
	 
	vector<string> codes {"abc", "aaa", "aba", "abc"};
    //vector<string> messages{"redbluered"};
     
    //vector<string> codes {"aba"};
    
    int testsize = messages.size();
    
    for(int i = 0; i < testsize; ++ i) {
        string message = messages[i];
        string code = codes[i];
        
        cout<< matchcodeii(message, code)<<endl;
        
    }

     
     
}


