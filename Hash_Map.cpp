#include <iostream>
#include <vector>

using namespace std;

template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;

    Node(K k, V v) : key(k), value(v), next(nullptr) {
    }
};

template<typename K, typename V>
class HashTable {
private:
    vector<Node<K, V>*> table;
    int size;

    int hash(K key) {
        return static_cast<int>(key) % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size, nullptr);
    }

    void insert(K key, V value) {
        int index = hash(key);
        Node<K, V>* newNode = new Node<K, V>(key, value);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            // Handle collision using chaining
            Node<K, V>* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    V search(K key) {
        int index = hash(key);
        Node<K, V>* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return V(); // Key not found
    }

    void remove(K key) {
        int index = hash(key);
        Node<K, V>* current = table[index];
        Node<K, V>* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                cout << "Key: " << current->key << ", Value: " << current->value << endl;
                current = current->next;
            }
        }
    }


    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node<K, V>* current = table[i];
            while (current != nullptr) {
                Node<K, V>* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;
    HashTable<int, string> ht(tableSize); 

    int key , ch;
    string value;
    char choice;

    do {
        cout << "Enter key: ";
        cin >> key;
        cout << "Enter value: ";
        cin >> value;
        ht.insert(key, value);

        cout << "Do you want to add another key-value pair? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

     b: cout<<"Enter for further action\n 1. Search\n 2. Delete\n 3. Display\n 4. Exit"<<endl;
    cin>>ch;
    if (ch==1){
        cout << "Enter the key to search: ";
        cin >> key;
        string result = ht.search(key);
        if (result != "") {
            cout << "Value found: " << result << endl;
            goto b;
        } else {
            cout << "Key not found" << endl;
            goto b;
        }
    }
    else if(ch==2){
          c:  cout << "Enter the key to remove: ";
            cin >> key;
            string result = ht.search(key);
            if (result == "") {
                cout << "Key not found" << endl;
                goto c;}else{
            ht.remove(key);
                cout << "Key removed" << endl;
                goto b;}

    }else if(ch==3){
        ht.display();
        goto b;
    
    }else if (ch == 4){
        goto a;
    }else{
        cout<<"Invalid input. Try Again";
        goto b;
    }

   a: return 0;
}
