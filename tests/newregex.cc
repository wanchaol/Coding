#include "../utils.h"

int main(void)
{
	string haystack = "This regex matches topcoder and also codertop";
	regex rgx("(top|coder)+");
	smatch match;

	//while (regex_search(haystack, match, rgx)) {
		
		//cout<<"find match "<<match[0]<<endl;

		//haystack = match.suffix().str();
	//}
	
	regex_search(haystack, match, rgx);
		
	for (auto m : match) {
		cout<<m<<endl;
	}

	return 0;
}
