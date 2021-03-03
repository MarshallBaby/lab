#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

char temp;
int temp_int;


enum Rent_state_type {
    RENT_DISABLED,
    RENT_ACTIVE
};

struct Reader_type
{
    std::string name; //ФИО читателя
    unsigned id: 8; //Номер читательского билета
    std::string book_name;
    union {
        unsigned rent_state: 8; //Состояние аренды

    };
    int lease; //Срок возврата
};

int menu_echo() {
    system("clear");
    std::cout << "\tMenu: " << std::endl;
    // std::cout << "1. Input struct array " << std::endl;
    std::cout << "1. Show struct array " << std::endl;
    std::cout << "2. Sort struct array " << std::endl;
    std::cout << "3. Search struct array " << std::endl;
    std::cout << "4. Delete struct" << std::endl;
    std::cout << "5. Exit " << std::endl;
    std::cout << "\nInput: " << std::endl;

    int statement;

    std::cin >> statement;
    return statement;
}

void confirm_by_enter() {
    std::cout << "Press ENTER to countinue" << std::endl;
    std::cin >> temp;
}


int loop(int alert, int statement, int arr_size, struct Reader_type arr[]) {

    switch (statement = menu_echo()) {
    case 1: {
        system("clear");
        std::cout << statement << std::endl;

        for (int i = 0; i < arr_size; i++) {
            std::cout << "----- Object No." << i + 1 << "-----" << std::endl;
            std::cout << "Name: " << arr[i].name << std::endl;
            temp_int = arr[i].id;
            std::cout << "ID: " << temp_int << std::endl;
            std::cout << "Book name: " << arr[i].book_name << std::endl;
            std::cout << "Lease: " << arr[i].lease << std::endl;
            std::cout << "\n";
        }
        confirm_by_enter();
    }
    break;
    case 2: {
        system("clear");
        int temp_arr[arr_size];
        // for (int i = 0; i < arr_size; i++) {
        //     temp_arr[i] = arr[i].id;
        //     std::cout << temp_arr[i] << std::endl;
        // }
        for (int i = 0; i < arr_size - 1; i++)
        {
            for (int j = 0; j < arr_size - i - 1; j++)
            {
                if (temp_arr[j] > temp_arr[j + 1])
                {
                    std::swap(temp_arr[j], temp_arr[j + 1]);
                }
            }
        }

        for (int i = 0; i < arr_size; i++) {
            // int value = temp_arr[i];
            std::cout << temp_arr[i] << std::endl;
            for (int j = 0; j < arr_size; j++) {
                int pizza = arr[j].id;
                if (temp_arr[i] == pizza) {
                    std::cout << "Name: " << arr[j].name << std::endl;
                    temp_int = arr[j].id;
                    std::cout << "ID: " << temp_int << std::endl;
                    std::cout << "Book name: " << arr[j].book_name << std::endl;
                    std::cout << "Lease: " << arr[j].lease << std::endl;
                    std::cout << "\n";
                }
            }
        }

        confirm_by_enter();
    }
    break;
    case 5: {

    }
    break;
    default: {

        system("clear");


        std::cout << "Invalid input" << std::endl;
        confirm_by_enter();
    }
    break;
    }

    if (statement == 5) {
        return 0;
    } else {
        alert++;
        if (alert > 50) {
            system("clear");
            std::cout << "EXIT due to TypeError" << std::endl;
            return 0;
        }
        loop(alert, statement, arr_size, arr);
    }



    return 0;
}





int main() {
    int alert = 0, statement = 0, arr_size = 0;
    system("clear");
    std::cout << "Input arr size: " << std::endl;
    std::cin >> arr_size;

    Reader_type arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cout << "----- Object No." << i + 1 << "-----" << std::endl;
        std::cout << "Input name: ";
        std::cin >> arr[i].name;

        std::cout << "Input ID: ";
        std::cin >> temp_int;
        arr[i].id = temp_int;

        std::cout << "Input book name: ";
        std::cin >> arr[i].book_name;

        std::cout << "Input lease: ";
        std::cin >> arr[i].lease;

        if (arr[i].lease) {
            arr[i].rent_state = RENT_ACTIVE;
        } else {
            arr[i].rent_state = RENT_DISABLED;
        }

        std::cout << "\n";
    }
    std::cout << "Done!" << std::endl;
    confirm_by_enter();
    loop(alert, statement, arr_size, arr);
    return 0;
}