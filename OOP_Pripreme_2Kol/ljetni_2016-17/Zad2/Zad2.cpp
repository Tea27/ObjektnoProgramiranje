/*(15) Napisati template klasu koja predstavlja red (engl. queue). Implementirati potrebne funkcije. Red ima
ogranicenu maksimalnu velicinu, velicinu, funkcije za dodavanje na kraj reda (enqueue), skidanje elementa
sa pocetka reda (dequeue). Ako red dosegne maksimalnu veliˇcinu, funkcija za dodavanje elemenata treba
baciti iznimku.*/

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Queue {
    vector<T> arr;
    size_t size;
    size_t maxSize;
public:
    Queue() {
        maxSize = 100;
        size = 0;
    }
    Queue(size_t size) {
        maxSize = size;
        size = 0;
    }
    void Enqueue(T x) {
        try {
            if (maxSize == size) {
                throw exception();
            } 
            else {
                arr.push_back(x);
                size++;
                cout << "vel " << size << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Queue is full "<< endl;
            
        }
        
    }
    void Dequeue() {
        arr.pop_back();
        size--;
    }
    void Print() {
        for (auto el : arr) {
            cout << el << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> queue(2);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Print();
    queue.Enqueue(6);
    queue.Dequeue();
    queue.Enqueue(6);
    queue.Print();
}


