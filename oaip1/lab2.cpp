#include <iostream>
#include <string>
#include <iomanip>

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
    default: {
        system("clear");
        std::cout << "Invalid input" << std::endl;
        confirm_by_enter();
    }
    }

    if (statement == 6) {
        return 0;
    } else {
        alert++;
        if (alert > 50) {
            system("clear");
            std::cout << "EXIT due to TypeError" << std::endl;
            return 0;
        }
        std::cout << statement << "  AWdadwad" << std::endl;
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