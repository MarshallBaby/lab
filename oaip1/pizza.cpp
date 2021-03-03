#include <iostream>
#include <string>
#include <iomanip>

int arr[5] = {1, 2, 3, 4, 5};

int pizza(int arr[], int size){
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << std::endl;
	}
	return 0;
}

int main(){
	pizza(arr, 5);

	return 0;
}