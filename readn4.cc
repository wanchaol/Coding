#include "utils.h"
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[4];
        int index = 0;
        
        while(true) {
            int readnum = read4(buffer);
            int cpnum = min(readnum, n - index);
            
            for(int i = 0; i < cpnum; ++ i) {
                buf[index + i] = buffer[i];
            }
            index += cpnum;
            
            if(readnum != 4 || index == n)
                return index;
            
        }
        
    
    }
};
