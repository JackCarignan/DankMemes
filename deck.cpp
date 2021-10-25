// Jack Carignan's Double-Ended Queue
// AKA: How to smash vectors together

/*
Make a double-ended queue. 
Store everything in a vector. 
The class methods, which can be achieved using a circular array and potentially modulo operation, should be constant time. 
Write thorough tests for functionality and correctness.  
Please reread ZyBooks to see how the various methods should work.
You can submit at most one project per week.
*/

#include <iostream>
#include <vector>

class Deque{
    private:
        std::vector<int> _front {};
        std::vector<int> _back {};

        int _frontIndex {-1};
        int _backIndex {-1};
 
    public:
        size_t capacity(){
            return _front.capacity() + _back.capacity();
        }

        size_t size(){
            return _front.size() + _back.size();
        }

        void push_back(int item){
            _back.push_back(item);
            _backIndex++;
        }

        void pop_back(){
            _back.pop_back();
            _backIndex--;
        }

        void push_front(int item){
            _front.push_back(item);
            _frontIndex++;
        }

        void pop_front(){
            _front.pop_back();
            _frontIndex--;
        }

        std::string full(){
            if (_front.size() + _back.size() == _front.capacity() + _back.capacity()){
                return "true";
            }
            else {
                return "false";
            }
        }

        std::string empty(){
            if (_front.size() + _back.size() == 0){
                return "true";
            }
            else {
                return "false";
            }
        }

        int front(){
            if (_front.size() > 0){
                return _front[_frontIndex];
            }
            else if (_back.size() > 0){
                return _back[0];
            }
            else {
                return 0;
            }
        }

        int back(){
            if (_back.size() > 0){
                return _back[_backIndex];
            }
            else if (_front.size() > 0){
                return _front[0];
            }
            else {
                return 0;
            }
        }
        
        void clear(){
            _front.clear();
            _back.clear();
        }

};


int main(){
    Deque deck;

    deck.push_back(10);
    deck.push_back(11);
    deck.push_back(12);
    std::cout << std::endl; // separates output to look clean

    std::cout << "Front & back items: " << deck.front() << " & " << deck.back() << std::endl;   // deque has items {10,11,12}
    std::cout << "Deque size: " << deck.size() << std::endl;
    std::cout << "Deque capacity: " << deck.capacity() << std::endl;
    std::cout << "Is deque empty: " << deck.empty() << std::endl;
    std::cout << "Is deque full: " << deck.full() << std::endl;

    deck.push_front(3);
    deck.push_front(4);
    deck.push_front(5);
    deck.push_back(13);
    deck.push_front(6);
    std::cout << std::endl; // separates output to look clean

    std::cout << "Front & back items: " << deck.front() << " & " << deck.back() << std::endl;   // deque has items {6,5,4,3,10,11,12,13}
    std::cout << "Deque size: " << deck.size() << std::endl;
    std::cout << "Deque capacity: " << deck.capacity() << std::endl;
    std::cout << "Is deque empty: " << deck.empty() << std::endl;
    std::cout << "Is deque full: " << deck.full() << std::endl;
    std::cout << std::endl; // separates output to look clean

    deck.pop_back();
    deck.pop_front();
    deck.pop_front();
    deck.pop_front();

    std::cout << "Front & back items: " << deck.front() << " & " << deck.back() << std::endl;   // deque has items {3,10,11,12}
    std::cout << "Deque size: " << deck.size() << std::endl;
    std::cout << "Deque capacity: " << deck.capacity() << std::endl;
    std::cout << "Is deque empty: " << deck.empty() << std::endl;
    std::cout << "Is deque full: " << deck.full() << std::endl;
    std::cout << std::endl; // separates output to look clean

    deck.clear();   // deletes everything from deque

    std::cout << "Front & back items: " << deck.front() << " & " << deck.back() << std::endl;     // should return 0 and 0
    std::cout << "Deque size: " << deck.size() << std::endl;
    std::cout << "Deque capacity: " << deck.capacity() << std::endl;
    std::cout << "Is deque empty: " << deck.empty() << std::endl;
    std::cout << "Is deque full: " << deck.full() << std::endl;
    std::cout << std::endl; // separates output to look clean

    return 0;
}