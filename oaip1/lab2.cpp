#include <iostream>
#include <string>
#include <iomanip>
//#include <algorithm>

char temp; //переменные для временного хранения промежуточных данных
int temp_int;

enum Rent_state_type { //перечеслитель, нужен по условию лабы
    RENT_DISABLED,
    RENT_ACTIVE
};

struct Reader_type //Собственно, структура
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
/*
    Функция, которая при вызове выводит меню и поле ввода пункта меню
    В return возвращает состояние(int)
*/ 
    system("clear"); //чистим экран. Если ругается на Windows, поменять на system("cls"), либо гуглим
    std::cout << "\tMenu: " << std::endl;
    std::cout << "1. Show struct array " << std::endl;
    std::cout << "2. Sort struct array " << std::endl;
    std::cout << "3. Search struct array " << std::endl;
    std::cout << "4. Delete struct" << std::endl;
    std::cout << "5. Exit " << std::endl;
    std::cout << "\nInput: " << std::endl;

    //принимаем значение
    int statement;
    std::cin >> statement;
    return statement;
}

void confirm_by_enter() {
    /*
    Фукнция, которая по своей сути останавнивает выполнение кода выводом cin.
    Тык чисто по нажатию Enter сделать поленился, так что надо чето ввести

    Если какой-либо кейс выбрасывает в меню, проверь, не забыл ли confirm_by_enter(); в конце
    */
    std::cout << "Press ENTER to countinue" << std::endl;
    std::cin >> temp; //temp - переменная-заглушка, ничего в себе не хранит
}


int loop(int alert, int statement, int arr_size, struct Reader_type arr[]) {
    /*
    основная функция, вызывает сама себя
    */


    switch (statement = menu_echo()) { //вызываем меню, записываем callback в statement, и заряжаем switch одной строкой
    case 1: { // вывод массива структур циклом
        system("clear");
        for (int i = 0; i < arr_size; i++) {
            std::cout << "----- Object No." << i + 1 << "-----" << std::endl;
            std::cout << "Name: " << arr[i].name << std::endl;
            temp_int = arr[i].id; //напрямую std::cout из битового поля недоступен. Делаем обход через переменную
            std::cout << "ID: " << temp_int << std::endl;
            std::cout << "Book name: " << arr[i].book_name << std::endl;
            std::cout << "Lease: " << arr[i].lease << std::endl;
            std::cout << "\n";
        }
        confirm_by_enter();
    }
    break;
    case 2: { //сортировка по ID(это поле в структуре такое)
        /*
        Принцип такой:
            1. Собираем массив всех ID(temp_arr)
            2. Сортируем пузырьком
            3. Циклом выводим структуры с совпадающим ID
            (id не должны повторяться, иначе будет каша)
            ((перед преподом аргументируем аля ИРЛ id тоже уникальны))
        */
        system("clear");
        int temp_arr[arr_size];

        //пузырек с киберфорума
        for (int i = 0; i < arr_size; i++) {
            temp_arr[i] = arr[i].id;
        }
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
        //конец пузырька

        for (int i = 0; i < arr_size; i++) {
            for (int j = 0; j < arr_size; j++) {
                if (temp_arr[i] == arr[j].id) { //сей цикл найдет совпадающие id в сорт. массиве и в структ. И выведет ее
                    std::cout << "----- Object No." << i + 1 << "-----" << std::endl;
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
    case 3: { //поиск по ID
        system("clear");
        std::cout << "Input ID: ";
        int find_id;
        bool toggle=false;
        std::cin >> find_id; //принимаем ID с клавы
        for (int i = 0; i < arr_size; i++) { // в цикле ищем объект с нужным id

            if (find_id == arr[i].id && !toggle) {
                std::cout << "\n----- Object " << "-----" << std::endl;
                std::cout << "Name: " << arr[i].name << std::endl;
                temp_int = arr[i].id;
                std::cout << "ID: " << temp_int << std::endl;
                std::cout << "Book name: " << arr[i].book_name << std::endl;
                std::cout << "Lease: " << arr[i].lease << std::endl;
                std::cout << "\n";
                toggle = true;
                confirm_by_enter();
                //break; // как только находим объект прерываем цикл, т.к. дело сделано
            }

        }
        if(!toggle){
            std::cout << "\nNo match\n" << std::endl;
            confirm_by_enter();
        }
        
    }
    break;
    case 4: {
        delete[] arr;
        //не доделано
    }
    case 5: {
        //выход из программы. Отдельный кейс 5, чтобы switch не выполнял default
    }
    break;
    default: {
        //ругаемся, statement неправильный
        system("clear");
        std::cout << "Invalid input" << std::endl;
        confirm_by_enter();
    }
    break;
    }

    if (statement == 5) {
        //выход если statement 5
        system("clear");
        return 0;
    } else {
        /*
            Защита от дурака. Начинается вакханалия, если в cin, ждущий int, приходит string
        */
        alert++;
        if (alert > 50) {
            system("clear");
            std::cout << "EXIT due to TypeError" << std::endl;
            return 0;
        }

        //дело сделано, запускаем функцию еще раз(выводим меню)

        //рекурсия ё-мое
        loop(alert, statement, arr_size, arr);
    }
    return 0;
}

int main() {
    //первее всего вполняется main
    int alert = 0, statement = 0, arr_size = 0;
    system("clear");

    /*
        При запуске проги первым делом собираем массив с клавы
        Не совсем по условию, на самом деле, но так проще
    */
    std::cout << "Input arr size: " << std::endl;
    std::cin >> arr_size;

    Reader_type arr[arr_size]; //объявляем массив струтур
    for (int i = 0; i < arr_size; i++) { // циклом собираем данные
        std::cout << "----- Object No." << i + 1 << "-----" << std::endl; 
        std::cout << "Input name: ";    
        std::cin >> arr[i].name;

        std::cout << "Input ID: ";
        std::cin >> temp_int; // обход ограничения ввода в битовое поле
        arr[i].id = temp_int;

        std::cout << "Input book name: ";
        std::cin >> arr[i].book_name;

        std::cout << "Input lease: ";
        std::cin >> arr[i].lease;

        if (arr[i].lease) { //устанавливаем значение из перечеслителя (0 или 1)
            arr[i].rent_state = RENT_ACTIVE;
        } else {
            arr[i].rent_state = RENT_DISABLED;
        }

        std::cout << "\n";
    }
    std::cout << "Done!" << std::endl;
    confirm_by_enter();

    //массив собрали, мы молодцы, теперь запускаем рекурсию
    //передаем в функцию все, что надо. Если не аккуратно передавать, то могут быть проблемы с облостями видимости
    loop(alert, statement, arr_size, arr);
    return 0;
}