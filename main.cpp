/*
*** This program receives a group of names
*** and sorts them in a linked list
*** Author: Ehsan Ahmadi 11.11.2023
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

// A struct for making nodes in the linked list
struct node {
    string name;
    struct node *next;
};

class linked_list {
    private:
        node *head, *tail;

    // This constructor initializes an empty linked list 
    // with head and tail set to NULL. 
    public:
        linked_list() {
        head = NULL;
        tail = NULL;
        }

        // This method can add new items to the list
        void add_node(string input_name) {
            node *tmp = new node;
            tmp->name = input_name;
            tmp->next = NULL;

            if (head == NULL) {
                head = tmp;
                tail = tmp;
            }
            else {
                // Here, the tail->next pointer is updated to point to the new node(tmp)
                // and the tail pointer is moved to the newly added node. 
                tail->next = tmp;
                tail = tail->next;
            }
        }

        // Using bubble sort algorithm to sort the inputs
        void sort_list() {
            if (head == NULL || head->next == NULL) {
                return;  // Nothing to sort
            }

            node *current = head;
            node *index = nullptr;
            string temp;

            while (current != nullptr) {
                index = current->next;

                while (index != nullptr) {
                    if (current->name > index->name) {
                        temp = current->name;
                        current->name = index->name;
                        index->name = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
        // A method for displaying the list
        void display() {
            sort_list();  // Sort the list before displaying
            struct node* temp;
            if (head == NULL) {
                cout << "The List is Empty" << endl;
                return;
            }
            temp = head;
            while (temp != NULL) {
                cout << temp->name << "   ";
                temp = temp->next;
            }
            cout << " End of the list" << endl;
        }
};

int main() {

    linked_list linker;
    string name;
    string user_input;

    // Adding nodes as the user wishes
    cout << "How many names do you want to enter/ give an integer: " << endl;
    cin >> user_input;


    try {
        // Attempt to convert the string to an integer
        int qty = std::stoi(user_input);
        
        // If successful, get the names
        cout << "You want to add " << qty << " names " << endl;
        cout << "Now enter the names ... " << endl;

        for(int i = 0; i < qty + 1; ++i) {
            getline(cin, name);
            linker.add_node(name);
        } 
    }
    catch (const invalid_argument& e) {
        // Conversion failed (input is not an integer)
        std::cerr << "Invalid input. Please enter an integer." << std::endl;
        system("pause");
        return 0;
    }
    catch (const std::out_of_range& e) {
        // Conversion failed (input is out of the valid range for int)
        std::cerr << "Input is out of range for an integer." << std::endl;
        system("pause");
        return 0;
    }

    cout << "This is the sorted List of inputs: " << endl;

    // Display the list, while it is sorted
    linker.display();

    system("pause");
    return 0;

}
