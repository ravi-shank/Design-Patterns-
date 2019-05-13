#include<iostream>
#include<vector>
using namespace std;


// An abstract Iterator class which will be inherited by all type of iterator class
template<class T>
class MyVectorIterator;

template <class T>
class Iterator
{
        public:
            virtual bool hasNext()=0;
            virtual  void next()=0;
            virtual T getCurrent()=0;
            virtual void begin()=0;
            virtual void end()=0;
            virtual bool isEnd()=0;
};


// A collection data type
template<class T>
class MyVector
{
    private:
        vector<T>m_vector;
    public:

        MyVector(){}
        ~MyVector(){}

        void append(T item)
        {
            m_vector.push_back(item);
        }

        int size()
        {
            return m_vector.size();
        }

        T getItem(int index)
        {
            return m_vector[index];
        }
        MyVectorIterator<T>* getIterator()
        {
            return new MyVectorIterator<T> (this);
        }


};


// MyVectorIterator class
template<class T>
class MyVectorIterator: public Iterator<T>
{
    private:
        MyVector<T>* m_vector_ptr;
        int itr_count;
    public:
        MyVectorIterator(MyVector<T>* myVec)
        {
            m_vector_ptr = myVec;
            itr_count = 0;
        }

        bool hasNext()
        {
            if(itr_count+1 < m_vector_ptr->size())
                return true;
            return false;
        }

        void next()
        {
            itr_count++;
        }

        T getCurrent()
        {
            if(itr_count < m_vector_ptr->size())
                return m_vector_ptr->getItem(itr_count);
            else
                return T(); // to return the default value of T data type
        }

        void begin()
        {
            itr_count=0;
        }

        void end()
        {
            itr_count= m_vector_ptr->size()-1;
        }
        bool isEnd()
        {
            if(itr_count == m_vector_ptr->size())
                return true;
            return false;
        }
};


int main()
{
    MyVector<int>v;
    v.append(1); v.append(2); v.append(3); v.append(4); v.append(5); v.append(6);

    MyVectorIterator<int> *itr = v.getIterator();
    for(itr->begin(); !itr->isEnd(); itr->next())
        cout<< itr->getCurrent()<<endl;

}



