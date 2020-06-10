#pragma once
template <typename T>
class List {
public:
    List();
    ~List();

    // Удаление первого элемента в списке
    void pop_front();

    // Добавление элемента в конец списка
    void push_back(T data);

    // Очистка списка
    void clear();

    // Получение количества элементов в списке
    int GetSize() { return Size; }

    // Перегруженный оператор
    T& operator[](const int index);

    // Добавление элемента в начало списка
    void push_front(T data);

    // Добавление элемента в список по указанному индексу
    void insert(T data, int index);

    // Удаление элемента в списке по указанному индексу
    void removeAt(int index);

    // Удаление последнего элемента в списке
    void pop_back();

    // Получение адреса следующего элемента
    void get_pNext(const int index);

    // Получение адреса предыдущего элемента
    void get_pPrev(const int index);

    // Полчуение адреса данной ячейки
    void get_data(const int index);

    // Вывод списка с начала
    void goFront();

    // Вывод списка с конца
    void goBack();

    template <typename T>
    class Node {
    public:
        Node* pNext;
        Node* pPrev;
        T data;

        //конструктор ячейки списка
        Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    int Size;
    Node<T>* head; //указатель типа ячейки на голову
    Node<T>* tail; //указатель типа ячейки на конец
};

//стандартный конструктор
template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

//деструктор
template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head; //создаём временную ячейку
                          //и записываем туда адрес head
    head = head->pNext;   //записываем в head адрес следующей ячейки

    delete temp; //а прежний head удаляем

    Size--; //уменьшаем размер на 1
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {        //если нет ни одного элемента,
        head = new Node<T>(data); //то просто создаём элемент и
        tail = head;              //записываем его адрес в head
    }                             //а старый head записываем в tail
    else {
        Node<T>* current = this->head; //создаём временный элемент и
                                       //присваиваем ему адрес head
        while (current->pNext != nullptr) { //идём по списку пока не встретим
            current = current->pNext;       //последний элемент
        }
        current->pNext = new Node<T>(data, nullptr, current); //в указатель pNext последнего элемента
                                                              //записываем созданную из переданных
                                                              //данных ячейку
        tail = current->pNext; //в указатель на конец списка
    }                          //записываем последний элемент
    Size++; //увеличиваем размер на 1
}

template <typename T>
void List<T>::clear()
{
    while (Size) {      //пока размер не равен нулю
        pop_front();    //вызываем функцию удаления элемента
    }                   //с начала списка
}

template <typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0; //счётчик положения элемента

    Node<T>* current = this->head; //создаём временный элемент и
                                   //присваиваем ему адрес head
    while (current != nullptr) {   //идём по списку пока не встретим
        if (counter == index) {    //нужный нам элемент и если это он
            return current->data;  //то возвращаем данные ячейки
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::push_front(T data)
{
    Node<T>* current = this->head; //создаём временный элемент и
                                   //присваиваем ему адрес head
    head = new Node<T>(data, head); //создаём новый элемент в head
                                    //и присваиваем ссылку на прошлый head
    current->pPrev = head; //в указатель на предыдущий элемент
                           //прошлого head кладём ссылку на настоящий head
    Size++; //увеличиваем размер на 1
}

template <typename T>
void List<T>::insert(T data, int index)
{

    if (index == 0) {       //если индекс 0, то
        push_front(data);   //просто добавляем элемент
    }                       //в начало списка
    else {
        Node<T>* previous = this->head; //создаём временный элемент и
                                        //присваиваем ему адрес head
        Node<T>* next = this->head;     //создаём временный элемент и
                                        //присваиваем ему адрес head

        for (int i = 0; i < index - 1; i++) { //ищём элемент стоящий перед местом
            previous = previous->pNext;       //в которое нужно вставить новый
        }
        for (int i = 0; i < index; i++) {     //ищём элемент стоящий после места
            next = next->pNext;               //в которое нужно вставить новый
        }

        previous->pNext = new Node<T>(data, previous->pNext, previous); //в указатель pNext предыдущего
                                                                        //записываем новый элемент и в
                                                                        //ссылку на предыдущий кладём адрес
                                                                        //предыдущего элемента а в ссылку на
                                                                        //следующий адрес из указателя pNext
                                                                        //предыдущего
        next->pPrev = previous; //в ссылку на предыдущий кладём
                                //адрес предыдущего

        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index)
{
    if (index == 0) {   //если индекс 0 то просто удаляем
        pop_front();    //элемент стоящий в начале
    }
    else {
        Node<T>* previous = this->head; //создаём новый элемент в head
                                        //присваиваем ему адрес head
        Node<T>* next = this->head;     //создаём новый элемент в head
                                        //присваиваем ему адрес head
        for (int i = 0; i < index - 1; i++) { //ищём элемент стоящий перед местом
            previous = previous->pNext;       //в которое нужно вставить новый
        }
        for (int i = 0; i < index; i++) {     //ищём элемент стоящий после места
            next = next->pNext;               //в которое нужно вставить новый
        }

        Node<T>* toDelete = previous->pNext; //создаём новый элемент содержащий
                                             //адрес удаляемого

        previous->pNext = toDelete->pNext;   //записываем в pNext предыдущего адрес
                                             //элемента стоящего после удаляемого
        next->pPrev = previous; //в ссылку на предыдущий кладём
                                //адрес предыдущего

        delete toDelete; //удаляем элемент

        Size--; //уменьшаем размер на 1
    }
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1); //удаляем последний элемент через
                        //функцию removeAt передавая индекс
                        //последнего
}


//get_pNext, get_pPrev, get_data
//находим указанный элемент и выводим в консоль адрес ячейки
template <typename T>
void List<T>::get_pNext(const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            cout << current->pNext;
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::get_pPrev(const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            cout << current->pPrev;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::get_data(const int index)
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            cout << current;
        }
        current = current->pNext;
        counter++;
    }
}


//проходим по списку с первого элемента
//и поочерёдно выводим их
template <typename T>
void List<T>::goFront()
{
    int counter = 0;

    Node<T>* current = this->head;

    while (current != nullptr) {
        current->data.out();
        current = current->pNext;
        counter++;
    }
}

//проходим по списку с последнего элемента
//и поочерёдно выводим их
template <typename T>
void List<T>::goBack()
{
    int counter = this->Size;

    Node<T>* current = this->tail;

    while (current != nullptr) {
        current->data.out();
        current = current->pPrev;
        counter--;
    }
}