#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int counter = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ++counter;
            }
        }
    }   
    // cout << counter;
}
 
int main()
{
    int arr[5] = { 5,4,3,1,2 };
    int counter = 0;
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ++counter;
            }
        }
    } 
    for(int i =0 ; i < 5; i++){
    	cout << arr[i] << endl;
    }
    return 0;
}