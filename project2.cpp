#include <iostream>
using namespace std;
class library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node *next;
        Node *prev;
    };

public:
    Node *head;
    library()
    {
        head = NULL;
    }
    void mainmenu();
    void menu();
    void insert_record();
    void search_record();
    void update_record();
    void delete_record();
    void sort();
    void show_all();
    void student_registery();

private:
    struct node
    {
        int data;
        struct node *next;
    };

public:
    struct node *front = NULL;
    struct node *rear = NULL;
    struct node *temp;
    void Insertstudent();
    void deletestudent();
    void displaystudents();
    void bookmanagment();
    void book_issue();
    void programming();
    void refrences();
    void Discovery();
    void Engineering();
};
void library::mainmenu()
{
    int choice;
    cout << "1 ADMIN" << endl;
    cout << "2 STUDENT" << endl;
    cin >> choice;
    if (choice == 1)
    {
        menu();
    }
    else
    {
        book_issue();
    }
}
void library::menu()
{
p:
    int choice;
    cout << "WELCOME ADMIN LOGIN";
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    cout << "\n1)Book Manegment";
    cout << "\n2)student Registery!";
    cout << "\n3)Exit";
    cout << endl
         << "\nenter your choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        bookmanagment();
        break;

    case 2:
        student_registery();
        break;

        // case 3:
        //     book_issue();
        //     break;

    case 3:
        cout << "\nthankyou!";
        exit(0);
        break;

    default:
        cout << "\ninvalid choice please try again!";
    }
    goto p;
}
void library::bookmanagment()
{
p:
    int choice;
    cout << "1)insert a new record:" << endl;
    cout << "2)search record" << endl;
    cout << "3)update record" << endl;
    cout << "4)Delete record" << endl;
    cout << "5)show all record";
    cout << "6)get back to main()";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert_record();
        break;

    case 2:
        search_record();
        break;

    case 3:
        update_record();
        break;

    case 4:
        delete_record();
        break;

    case 5:
        sort();
        show_all();
        break;

    case 6:
        menu();
        break;

    default:
        cout << "not valid entry!" << endl;
    }
    goto p;
}
void library::student_registery()
{
p:
    int choice;
    cout << "WELCOME TO STUDENT REGISTERY!" << endl;
    cout << "_____________________________" << endl;
    cout << "PRESS 1 TO REGISTR STUDENTS" << endl;
    cout << "PRESS 2 TO DELETE OLD BATCH" << endl;
    cout << "PRESS 3 TO SEE STUDENTS LIST" << endl;
    cout << "PRESS 4 TO GO TO MENU" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Insertstudent();
        break;

    case 2:
        deletestudent();
        break;

    case 3:
        displaystudents();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "INVALID CHOICE!";
    }
    goto p;
}
void library ::insert_record()
{
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    Node *temp = new Node();
    cout << endl
         << "BOOK ID: ";
    cin >> temp->id;
    cout << endl
         << "Book name: ";
    cin >> temp->name;
    cout << endl
         << "Author Name: ";
    cin >> temp->author;
    cout << endl
         << "Pusblisher name: ";
    cin >> temp->publisher;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
        temp->prev = ptr;
        ptr = temp;
        cout << "\nBook inserted successfully!!!!";
    }
}
void library::search_record()
{
    int t_id;
    int found = 0;
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    if (head == NULL)
    {
        cout << "No record found";
    }
    else
    {
        cout << "Book id";
        cin >> t_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "---------------------------" << endl;
                cout << "library manangement system:" << endl;
                cout << "---------------------------" << endl;
                cout << "BOOK ID =>" << ptr->id << endl;
                cout << "BOOK NAME =>" << ptr->name << endl;
                cout << "BOOK AUTHOR =>" << ptr->author << endl;
                cout << "BOOK PUBLISHER =>" << ptr->publisher << endl;
                found++;
            }
            ptr = ptr->next;
            if (found == 0)
            {
                cout << "record not found";
            }
        }
    }
}
void library::update_record()
{
    int t_id;
    int found = 0;
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    if (head == NULL)
    {
        cout << "No record found";
    }
    else
    {
        cout << "Book id";
        cin >> t_id;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "---------------------------" << endl;
                cout << "library manangement system:" << endl;
                cout << "---------------------------" << endl;
                cout << "BOOK ID =>";
                cin >> ptr->id;
                cout << "BOOK NAME =>";
                cin >> ptr->name;
                cout << "BOOK AUTHOR =>";
                cin >> ptr->author;
                cout << "BOOK PUBLISHER =>";
                cin >> ptr->publisher;
                found++;
                cout << "updated book successfully!";
            }
            ptr = ptr->next;
            if (found == 0)
            {
                cout << "record not found";
            }
        }
    }
}
void library ::delete_record()
{
    int t_id;
    int found = 0;
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    if (head == NULL)
    {
        cout << "No record found";
    }
    else
    {
        cout << "Book id";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node *ptr = head;
            head = head->next;
            free(ptr);
            cout << "ENTRY DELETED SUCCESFULLY!";
            found++;
        }
        else
        {
            Node *temp = head;
            Node *ptr = head->next;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    temp->next = ptr->next;
                    ptr->next->prev = temp;
                    free(ptr);
                    cout << "Record deleted successfully";
                    found++;
                    break;
                }
                temp = ptr;
                ptr = ptr->next;
            }
        }
        if (found == 0)
        {
            cout << "ID IS INVALID!";
        }
    }
}
void library ::sort()
{
    if (head == NULL)
    {
        cout << "linked list is empty!";
        menu();
    }
    int count = 0;
    int t_id;
    string t_name, t_author, t_publisher;
    Node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    for (int i = 1; i <= count; i++)
    {
        Node *ptr = head;
        for (int j = 1; j < count; j++)
        {
            if (ptr->id > ptr->next->id)
            {
                t_id = ptr->id;
                t_name = ptr->name;
                t_author = ptr->author;
                t_publisher = ptr->publisher;

                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->author = ptr->next->author;
                ptr->publisher = ptr->next->publisher;

                ptr->next->id = t_id;
                ptr->next->name = t_name;
                ptr->next->author = t_author;
                ptr->next->publisher = t_publisher;
            }
            ptr = ptr->next;
        }
    }
}
void library ::show_all()
{
    int t_id;
    int found = 0;
    cout << "---------------------------" << endl;
    cout << "library manangement system:" << endl;
    cout << "---------------------------" << endl;
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "BOOK ID =>" << ptr->id << endl;
        cout << "BOOK NAME =>" << ptr->name << endl;
        cout << "BOOK AUTHOR =>" << ptr->author << endl;
        cout << "BOOK PUBLISHER =>" << ptr->publisher << endl;
        ptr = ptr->next;
    }
}

void library::Insertstudent()
{
    int student_id;
    string name, batch, passward;
    cout << "Insert student id:";
    cin >> student_id;
    cout << "Insert student name:";
    cin >> name;
    cout << "Insert student batch:";
    cin >> batch;
    cout << "Insert student passward:";
    cin >> passward;
    if (rear == NULL)
    {
        rear = new node();
        rear->next = NULL;
        rear->data = student_id;
        front = rear;
        cout << "student registered successfully!" << endl;
    }
    else
    {
        temp = new node();
        rear->next = temp;
        temp->data = student_id;
        temp->next = NULL;
        rear = temp;
    }
}
void library ::deletestudent()
{
    temp = front;
    if (front == NULL)
    {
        cout << "No student registered!";
        return;
    }
    else
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
            cout << "student deleted:" << front->data << endl;
            free(front);
            front = temp;
        }
        else
        {
            cout << "student deleted:" << front->data << endl;
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
}
void library ::displaystudents()
{
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        cout << "No student registered!" << endl;
        return;
    }
    cout << "\nRegistered Students are:";
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
void library::book_issue()
{
p:
    int choice;
    cout << "WELCOME TO BOOK CATAGORIES!" << endl;
    cout << "1>PROGRAMMING" << endl;
    cout << "2>REFRENCES" << endl;
    cout << "3>Discovery" << endl;
    cout << "4>Engineering" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        programming();
        break;

    case 2:
        refrences();
        break;

    case 3:
        Discovery();
        break;

    case 4:
        Engineering();
        break;

    default:
        cout << "Invalid Choice";
    }
    goto p;
}
void library::programming()
{
    int choice;
    cout << "\n-------PROGRAMMING---------" << endl;
    cout << "\n1> Clean Code" << endl;
    cout << "\n2> The pragmatric programming" << endl;
    cout << "\n3> Python crash" << endl;
    cout << "\n4> Code Complete" << endl;
    cin >> choice;
    if (choice == 1)
        cout << "\nClean Code Issued successfully" << endl;
    else if (choice == 2)
        cout << "\nThe pragramatic Programming Issued Successfully" << endl;
    else if (choice == 3)
        cout << "\npython crash Issued Successfully" << endl;
    else
    {
        cout << "\nCode Complete issued successfully" << endl;
    }
}
void library::refrences()
{
    int choice;
    cout << "\n-----------REFRENCES----------" << endl;
    cout << "1>\nengineering refrences" << endl;
    cout << "2>\nguide refrences" << endl;
    cout << "3>\nsoft refrences" << endl;
    cin >> choice;
    if (choice == 1)
        cout << "\nengineering refrences issued successfully" << endl;
    else if (choice == 2)
        cout << "\nguide refrences issued successfully" << endl;
    else
    {
        cout << "\nsoft refrences issued successfullyy" << endl;
    }
}
void library::Discovery()
{
    int choice;
    cout << "\n1> Discover Earth" << endl;
    cout << "\n2> Discover me!" << endl;
    cout << "\n3> The secret" << endl;
    cin >> choice;
    if (choice == 1)
        cout << "Discover Earth Issued succesfully" << endl;
    if (choice == 2)
        cout << "Discover me Issued succesfully" << endl;
    else
    {
        cout << "The secret issued succesfully" << endl;
    }
}
void library::Engineering()
{
    int choice;
    cout << "\n1> mechinary's Book" << endl;
    cout << "\n2> Structures" << endl;
    cout << "\n3> To Engineers human" << endl;
    cout << "\n4> Elon Musk Tesla" << endl;
    cin >> choice;
    if (choice == 1)
        cout << "\nmechinary's Book Issued succesfully" << endl;
    else if (choice == 2)
        cout << "\nstructures Issued sucessfully" << endl;
    else if (choice == 3)
        cout << "\nTo enginer Human Issued Successfully" << endl;
    else
        cout << "\nElon Musk tesla Issued Sucessfully" << endl;
}
int main()
{
    library lib;
    //  int x;
    // cout<<"enter your choice";
    // cin>>x
    lib.mainmenu();
    // lib.programming();
    return 0;
}
