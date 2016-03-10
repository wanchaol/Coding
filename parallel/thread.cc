#include "../utils.h"
#include <thread>
#include <mutex>

static const int num_threads = 10;


mutex m;


void call_from_thread(int tid) {

	m.lock();
	cout<< "Launched by thread "<< tid <<endl;
	m.unlock();
}


int main(int argc, char *argv[])
{

	thread t[num_threads];

	for (int i = 0; i < num_threads; ++i) {
		t[i] = thread(call_from_thread, i);
	}

	m.lock();
	cout<<"Launched from the main"<<endl;
	m.unlock();
	
	for (int i = 0; i < num_threads; ++i) {
		t[i].join();
	}
	

	return 0;

}

