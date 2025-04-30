#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string arr;
    int ascii[127]={0,};
    char test[127]={0};

    getline(cin, arr, '\n');

    for(int i=0; i<arr.length(); i++) {
            if(isalpha(arr[i])!=0) {
                arr[i] = tolower(arr[i]);
            }
    }

    for(int i=0; i<arr.length(); i++) {
            ascii[arr[i]]++;
    }

    for(int i=0; i<arr.length(); i++) {
        for (int j=i+1; arr.length(); j++){
            if(arr[i]>arr[j]) {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    int count1 = 0;

    for(int i=0; i<127; i++) {
            if(ascii[i] >=1 ) {
                test[count1] = i;
                count1 ++;
            }
    }

    for(int i=0; i<count1; i++) {
        for (int j=i+1; count1; j++){
            if(ascii[test[i]]<ascii[test[j]]) {
                char temp = test[i];
                test[i]=test[j];
                test[j]=temp; //ascii & test
            }
        }
    }

    for(int i=0; test[i]!='\0'; i++) {
        cout << arr[i] << test[i] << endl;
    }

    return 0;
}
