template <typename T>

class smallVector

{

    public:

        smallVector (int c=4)

         :capacity(c), size(0) {arr = new T[c];}

        /* Fill up here with your code */

        T* arr;

        int size;

        int capacity;

};

int push_back(int a);
int clear();
operator[]
getpointer()

/* Fill up here with your code */

 


int main ()

{

    /* This object should contain an <int> array with the capacity of 4 */

    smallVector<int> s1(4);   

    cout << s1.size << ", "

         << s1.capacity << endl;

 

    /* The internal array capacity must be doubled if needed */

    for (int i=0; i < 10; i++)

        s1.pushback( i* 10 );

    for (int i=0; i < s1.size; i++)

        cout << s1[i] << ", "

        << s1.size << ", " << s1.capacity << endl;

   

    s1.clear();

    cout << s1.size << ", "

         << s1.capacity << endl;

    for (int i=0; i < 8; i++)

        s1.pushback( i );

   

    int* p1 = s1.getPointer();

    for (int i=0; i < s1.size; i++)

        cout << *(p1+i) << ", "

        << s1.size << ", " << s1.capacity << endl;

}