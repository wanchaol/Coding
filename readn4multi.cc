#include "utils.h"
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
   private:
    char temp[4];
    int tempsize = 0;
    int start = 0;

   public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int index = 0;

        while (index < n) {
            if (start == 0) {
                tempsize = read4(temp);
            }

            if (tempsize == 0) break;

            while (index < n && start < tempsize) {
                buf[index++] = temp[start++];
            }

            if (start >= tempsize) {
                start = 0;
            }
        }

        return index;
    }
};
