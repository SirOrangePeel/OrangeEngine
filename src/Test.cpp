# include "VectorT.h"
# include <string>

int main()
{
    //Library Test Functions
    VectorT<int> intVec;
    VectorT<char> charVec(5);

    cout << "intVec.Cap: " << intVec.GetCapacity() << endl;
    cout << "intVec.Size: " << intVec.GetSize() << endl;
    cout << endl;
    cout << "charVec.Cap: " << charVec.GetCapacity() << endl;
    cout << "charVec.Size: " << charVec.GetSize() << endl;
    cout << endl;

    intVec.PushBack(69);
    intVec.PushBack(10);
    intVec.PushBack(1000000);

    charVec.PushBack('a');
    charVec.PushBack('b');
    charVec.PushBack('c');
    charVec.PushBack('d');
    charVec.PushBack('e');
    charVec.PushBack('f');

    cout << "Pushes Completed" << endl;

    for(std::size_t i = 0; i < intVec.GetSize(); i++){
        cout << "intVec Element " << i << ": " << intVec.At(i) << endl;
    }
    cout << endl;

    for(std::size_t i = 0; i < charVec.GetSize(); i++){
        cout << "charVec Element " << i << ": " << charVec.At(i) << endl;
    }
    cout << endl;

    intVec.PopBack();

    charVec.PopBack();
    charVec.PopBack();
    charVec.PopBack();

    cout << "Pops Completed" << endl;

    for(std::size_t i = 0; i < intVec.GetSize(); i++){
        cout << "intVec Element " << i << ": " << intVec.At(i) << endl;
    }
    cout << endl;
    for(std::size_t i = 0; i < charVec.GetSize(); i++){
        cout << "charVec Element " << i << ": " << charVec.At(i) << endl;
    }
    cout << endl;

    cout << "intVec.Cap: " << intVec.GetCapacity() << endl;
    cout << "intVec.Size: " << intVec.GetSize() << endl;
    cout << endl;
    cout << "charVec.Cap: " << charVec.GetCapacity() << endl;
    cout << "charVec.Size: " << charVec.GetSize() << endl;
    cout << endl;

    cout << "Reserving Space" << endl;
    intVec.Reserve(100);

    charVec.Reserve(3);

    cout << "intVec.Cap: " << intVec.GetCapacity() << endl;
    cout << "intVec.Size: " << intVec.GetSize() << endl;
    cout << endl;
    cout << "charVec.Cap: " << charVec.GetCapacity() << endl;
    cout << "charVec.Size: " << charVec.GetSize() << endl;

    return 0;
}