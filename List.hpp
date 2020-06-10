#pragma once
template <typename T>
class List {
public:
    List();
    ~List();

    // �������� ������� �������� � ������
    void pop_front();

    // ���������� �������� � ����� ������
    void push_back(T data);

    // ������� ������
    void clear();

    // ��������� ���������� ��������� � ������
    int GetSize() { return Size; }

    // ������������� ��������
    T& operator[](const int index);

    // ���������� �������� � ������ ������
    void push_front(T data);

    // ���������� �������� � ������ �� ���������� �������
    void insert(T data, int index);

    // �������� �������� � ������ �� ���������� �������
    void removeAt(int index);

    // �������� ���������� �������� � ������
    void pop_back();

    // ��������� ������ ���������� ��������
    void get_pNext(const int index);

    // ��������� ������ ����������� ��������
    void get_pPrev(const int index);

    // ��������� ������ ������ ������
    void get_data(const int index);

    // ����� ������ � ������
    void goFront();

    // ����� ������ � �����
    void goBack();

    template <typename T>
    class Node {
    public:
        Node* pNext;
        Node* pPrev;
        T data;

        //����������� ������ ������
        Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    int Size;
    Node<T>* head; //��������� ���� ������ �� ������
    Node<T>* tail; //��������� ���� ������ �� �����
};

//����������� �����������
template <typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

//����������
template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head; //������ ��������� ������
                          //� ���������� ���� ����� head
    head = head->pNext;   //���������� � head ����� ��������� ������

    delete temp; //� ������� head �������

    Size--; //��������� ������ �� 1
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {        //���� ��� �� ������ ��������,
        head = new Node<T>(data); //�� ������ ������ ������� �
        tail = head;              //���������� ��� ����� � head
    }                             //� ������ head ���������� � tail
    else {
        Node<T>* current = this->head; //������ ��������� ������� �
                                       //����������� ��� ����� head
        while (current->pNext != nullptr) { //��� �� ������ ���� �� ��������
            current = current->pNext;       //��������� �������
        }
        current->pNext = new Node<T>(data, nullptr, current); //� ��������� pNext ���������� ��������
                                                              //���������� ��������� �� ����������
                                                              //������ ������
        tail = current->pNext; //� ��������� �� ����� ������
    }                          //���������� ��������� �������
    Size++; //����������� ������ �� 1
}

template <typename T>
void List<T>::clear()
{
    while (Size) {      //���� ������ �� ����� ����
        pop_front();    //�������� ������� �������� ��������
    }                   //� ������ ������
}

template <typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0; //������� ��������� ��������

    Node<T>* current = this->head; //������ ��������� ������� �
                                   //����������� ��� ����� head
    while (current != nullptr) {   //��� �� ������ ���� �� ��������
        if (counter == index) {    //������ ��� ������� � ���� ��� ��
            return current->data;  //�� ���������� ������ ������
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::push_front(T data)
{
    Node<T>* current = this->head; //������ ��������� ������� �
                                   //����������� ��� ����� head
    head = new Node<T>(data, head); //������ ����� ������� � head
                                    //� ����������� ������ �� ������� head
    current->pPrev = head; //� ��������� �� ���������� �������
                           //�������� head ����� ������ �� ��������� head
    Size++; //����������� ������ �� 1
}

template <typename T>
void List<T>::insert(T data, int index)
{

    if (index == 0) {       //���� ������ 0, ��
        push_front(data);   //������ ��������� �������
    }                       //� ������ ������
    else {
        Node<T>* previous = this->head; //������ ��������� ������� �
                                        //����������� ��� ����� head
        Node<T>* next = this->head;     //������ ��������� ������� �
                                        //����������� ��� ����� head

        for (int i = 0; i < index - 1; i++) { //���� ������� ������� ����� ������
            previous = previous->pNext;       //� ������� ����� �������� �����
        }
        for (int i = 0; i < index; i++) {     //���� ������� ������� ����� �����
            next = next->pNext;               //� ������� ����� �������� �����
        }

        previous->pNext = new Node<T>(data, previous->pNext, previous); //� ��������� pNext �����������
                                                                        //���������� ����� ������� � �
                                                                        //������ �� ���������� ����� �����
                                                                        //����������� �������� � � ������ ��
                                                                        //��������� ����� �� ��������� pNext
                                                                        //�����������
        next->pPrev = previous; //� ������ �� ���������� �����
                                //����� �����������

        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index)
{
    if (index == 0) {   //���� ������ 0 �� ������ �������
        pop_front();    //������� ������� � ������
    }
    else {
        Node<T>* previous = this->head; //������ ����� ������� � head
                                        //����������� ��� ����� head
        Node<T>* next = this->head;     //������ ����� ������� � head
                                        //����������� ��� ����� head
        for (int i = 0; i < index - 1; i++) { //���� ������� ������� ����� ������
            previous = previous->pNext;       //� ������� ����� �������� �����
        }
        for (int i = 0; i < index; i++) {     //���� ������� ������� ����� �����
            next = next->pNext;               //� ������� ����� �������� �����
        }

        Node<T>* toDelete = previous->pNext; //������ ����� ������� ����������
                                             //����� ����������

        previous->pNext = toDelete->pNext;   //���������� � pNext ����������� �����
                                             //�������� �������� ����� ����������
        next->pPrev = previous; //� ������ �� ���������� �����
                                //����� �����������

        delete toDelete; //������� �������

        Size--; //��������� ������ �� 1
    }
}

template <typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1); //������� ��������� ������� �����
                        //������� removeAt ��������� ������
                        //����������
}


//get_pNext, get_pPrev, get_data
//������� ��������� ������� � ������� � ������� ����� ������
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


//�������� �� ������ � ������� ��������
//� ��������� ������� ��
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

//�������� �� ������ � ���������� ��������
//� ��������� ������� ��
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