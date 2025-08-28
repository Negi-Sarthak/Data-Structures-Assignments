#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key, low, high, mid;
    bool found = false;

    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements (sorted):\n";
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "Enter key to search: ";
    cin >> key;

    low=0; high=n-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==key) {
            cout << "Found at position " << mid << endl;
            found = true;
            break;
        }
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    if(!found) cout << "Not found\n";
    return 0;
}
