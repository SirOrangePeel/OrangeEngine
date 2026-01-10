# include "VectorT.h"

int main()
{
    VectorT<int> intVector(5);

    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);
    intVector.push_back(4);
    intVector.pop();

    for(std::size_t i = 0; i < intVector.get_size(); i++)
        cout << "Element " << i << ": " << intVector.get(i) << endl;

    VectorT<double> doubleVector;
    doubleVector.push_back(69);

    cout << doubleVector.get_capacity() << endl;
    cout << doubleVector.get_size() << endl;

    return 0;
}