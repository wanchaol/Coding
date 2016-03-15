#include "utils.h"

//array-based mininal binary heap implementation

class MinHeap
{
private:
    vector<int> vals;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void MakeHeap();

public:
    MinHeap(const vector<int>& vector);
    MinHeap() = default;

    void Insert(int newValue);
    int GetMin();
    void DeleteMin();
};

MinHeap::MinHeap(const vector<int>& inputvec) : vals(inputvec)
{
	MakeHeap();
}

void MinHeap::MakeHeap()
{
    int length = vals.size();

    for(int i = length-1; i >= 0; -- i)
    {
        BubbleDown(i);
    }
}

void MinHeap::BubbleDown(int index)
{
    int length = vals.size();

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

	//current index is a leaf
    if(leftChildIndex >= length)
        return; 

    int minIndex = index;

    if(vals[index] > vals[leftChildIndex])
    {
        minIndex = leftChildIndex;
    }
    
    if((rightChildIndex < length) && (vals[minIndex] > vals[rightChildIndex]))
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
		swap(vals[index], vals[minIndex]);
        BubbleDown(minIndex);
    }
}

void MinHeap::BubbleUp(int index)
{
    if(index == 0)
        return;

    int parentIndex = (index-1)/2;

    if(vals[parentIndex] > vals[index])
    {
        //int temp = vals[parentIndex];
        //vals[parentIndex] = vals[index];
        //vals[index] = temp;
		swap(vals[parentIndex], vals[index]);
        BubbleUp(parentIndex);
    }
}

void MinHeap::Insert(int newValue)
{
    int length = vals.size();
	vals.push_back(newValue);

    BubbleUp(length);
}

int MinHeap::GetMin()
{
    return vals[0];
}
    
void MinHeap::DeleteMin()
{
    int length = vals.size();

    if(length == 0)
    {
        return;
    }
    
    vals[0] = vals[length-1];
    vals.pop_back();

    BubbleDown(0);
}

int main(int argc, char *argv[])
{
    MinHeap minHeap;

	minHeap.Insert(5);
	minHeap.Insert(8);
	minHeap.Insert(2);
	minHeap.Insert(6);

	for (int i = 0; i < 4; ++i) {
		cout<<minHeap.GetMin()<<" "<<endl;
		minHeap.DeleteMin();
	}
	

    return 0;
}


