#include <map>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, char*> fizzbuzz_pair;
typedef map<int, char*> fizzbuzz_map;


class fizzbuzz
{
public:
	vector<string> GetList(int count);
	fizzbuzz(void);
	~fizzbuzz(void);
	fizzbuzz_map specialNumbers;

private:
	string GetSpecialValue(int number);
	int GetSpecialNumber(int number);
};
