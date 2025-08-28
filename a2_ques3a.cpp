#include <iostream>
using namespace std;

int main() {
    int arr[100], n, sum=0;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter " << n-1 << " numbers from 1 to " << n << ":\n";
    for(int i=0;i<n-1;i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    int total=n*(n+1)/2;
    cout << "Missing number = " << total-sum << endl;
    return 0;
}
