#include<vector>
#include "AbstractSorter.hpp"

template <typename T>
class InsertionSorter : public AbstractSorter<T>
{
private:
public:
    InsertionSorter();
    void sort(std::vector<T> &, bool reverse = false);
};

template<typename T>
InsertionSorter<T>::InsertionSorter()
{
}

template<typename T>
void InsertionSorter<T>::sort(std::vector<T>& src_vec, bool reverse){

    if (src_vec.size() <=1){
        return;
    }
    
    T& key = src_vec[0];
    int dec;

    for (size_t i = 1; i < src_vec.size(); i++)
    {
        key = src_vec[i];
        dec = i-1;
        while (dec > -1 &&
              ((!reverse && key < src_vec[dec]) ||
              (reverse && key > src_vec[dec])))
        {
            src_vec[dec+1] = src_vec[dec];
            dec--;
        }
        src_vec[dec+1] = key;
    }
}
