#include "utils.h"

class HashTable {
private:
	unordered_map<string, string> map;
	unordered_map<string, int> inds;

	vector<string> keys;

public:
	string get(string key) {
		return map[key];
	}

	void set(string key, string value) {
		keys.push_back(key);
		inds[key] = keys.size() - 1;

		map[key] = value;
	}

	void deleteentry(string key) {
		int index = inds[key];
		inds.erase(key);
		map.erase(key);
		swap(keys[index], keys.back());
		keys.pop_back();
	}

	string getRandomKey() {
		string key;
        int numsize = keys.size(); 

        //srand(time(NULL));
        
        //int randinx = rand() % numsize;
		//
		uniform_int_distribution<unsigned> u(0, numsize - 1);
		default_random_engine e;

        key = keys[u(e)];
        
        return key;

	}

};

int main(int argc, char *argv[])
{

	HashTable table; 

	table.set("fff", "fvalue");
	table.set("eee", "evalue");
	table.set("ddd", "dvalue");

	table.deleteentry("ddd");
	
	cout<<table.get("fff")<<endl;
	cout<<table.getRandomKey()<<endl;

	return 0;
}
