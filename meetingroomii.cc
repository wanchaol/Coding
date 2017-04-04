#include "utils.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
   private:
    static bool compareStart(const Interval &v1, const Interval &v2) {
        return v1.start < v2.start;
    }
    static bool compareEnd(const Interval &v1, const Interval &v2) {
        return v1.end < v2.end;
    }

   public:
    int minMeetingRooms(vector<Interval> &intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), compareStart);

        priority_queue<int, vector<int>, greater<int>> minheap;

        minheap.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            int intend = minheap.top();
            minheap.pop();

            if (intend <= intervals[i].start) {
                intend = intervals[i].end;
            } else {
                minheap.push(intervals[i].end);
            }

            minheap.push(intend);
        }

        if (minheap.size() == 0) return 1;

        return (int)minheap.size();
    }
};
