#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// Tên chương trình
const string NAME = "tem";
const string MAIN = "main.exe";
const string TEST = "test.exe";
// Số test kiểm tra
const int NTEST = 10;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
	return uniform_int_distribution<long long>(l, h)(rng);
}
typedef long long ll;
int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= 10000; iTest++)
    {
        ofstream inp((NAME  + ".inp").c_str());	

		inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
		//
        system((MAIN).c_str());
		system((TEST).c_str());
        //system((TEST).c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }

        cout << "Test " << iTest << ": " << "ACCEPTED" << "\n";
    }
    return 0;
}
