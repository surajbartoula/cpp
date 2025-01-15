#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << left << setw(10) << 42 << endl;  // Outputs: "42        "
    cout << right << setw(10) << 42 << endl; // Outputs: "        42"
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setfill('*') << setw(10) << 42 << endl; // Outputs: "********42"
    return 0;
}
