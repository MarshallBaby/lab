#include <iostream>
#include <string.h>
// #include <iomanip>

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

Reader_type arr[0];

int menu_echo() {
    std::cout << "\tMenu: " << std::endl;
    std::cout << "1. Input struct array " << std::endl;
    std::cout << "2. Show struct array " << std::endl;
    std::cout << "3. Sort struct array " << std::endl;
    std::cout << "4. Search struct array " << std::endl;
    std::cout << "5. Delete struct" << std::endl;
    std::cout << "6. Exit " << std::endl;
    std::cout << "\nInput: " << std::endl;

    int statement = 0;

    std::cin >> statement;
    return statement;
}

void confirm_by_enter() {
    std::cout << "Press ENTER to countinue" << std::endl;
    std::cin >> temp;
}

int main()
{
    system("clear");
    int alert = 0, statement = 0, arr_size = 0, arr_exist_state = 0;
    while (statement != 6) {
        statement = menu_echo();
        std::cout << arr_size;
        switch (statement) {
        case 1: {
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
            arr_exist_state = 1;
            confirm_by_enter();
        }
        break;
        case 2: {
            if (arr_exist_state) {
                system("clear");
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "----- Object No." << i + 1 << "-----" << std::endl;
                    std::cout << "Name: " << arr[i].name << std::endl;
                    temp_int = arr[i].id;
                    std::cout << "ID: " << temp_int << std::endl;
                    std::cout << "Book name: " << arr[i].book_name << std::endl;
                    std::cout << "\n";
                }
                confirm_by_enter();
            } else {
                system("clear");
                std::cout << "ERROR: Array does not exist.\n";
                confirm_by_enter();
            }
        }
        break;
        case 3: {

        }
        break;
        case 6: {

        }
        break;
        default: {
            system("clear");
            std::cout << "Invalid input" << std::endl;
            confirm_by_enter();
        }
        }
        system("clear");
        alert++;
        if (alert > 50) {
            std::cout << "Exit due to error" << std::endl;
            break;
        }
    }
    return 0;
}
