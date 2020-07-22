class RoomStack

{

    public:

        RoomStack () {}

        void push(Furniture* s);

        Furniture* pop();

        bool isEmpty();

        int getOccupied() {return occupied;}

        void printInfo ();

    private:

        vector<Furniture*> elem;

        int occupied;

};

 
class Desk:public RoomStack{
public:
     
     
}
class Chair:public RoomStack{
public:
    
}
class Cabinet:public RoomStack{
public:
    
}
int main()

{

    RoomStack st;

    Furniture* pf;

    st.push(new Desk("Desk-1"));

    st.push(new Chair("Chair-1"));

    st.push(new Cabinet("Cabinet-1"));

    st.push(new Desk("Desk-2"));

 

    st.printInfo();

    while (!st.isEmpty())

    {

        pf = st.pop();

        pf->printInfo();

        cout << "Occupied space: "

          << st.getOccupied() << endl;

    }

    st.printInfo();

}