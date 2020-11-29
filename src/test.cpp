#include "linklist.h"

int main()
{
    Link test;
    test.insert("hello", "world");
    test.insert("Good","Staff");
    cout<< "search===================="<<endl;
    char *temp = test.search("hello")->value;
    if(temp != NULL) cout << temp << endl;
    else cout<< "No result is found"<<endl;
    cout<< "Insert===================="<<endl;
    test.print();
    cout<< "Delete===================="<<endl;
    test.del("Staff", 1);
    test.print();
    cout<< "Destroy===================="<<endl<<endl;
    test.destory();
    test.print();
    test.insert("hello", "world");
    test.insert("Good","Staff");
    test.print();
    cout<< "new link list============="<<endl;
    Link Link1, *result;
    Link1.insert("game","minecraft");
    Link1.insert("video","nihao");
    Link1.print();
    cout<< "test operator overload============="<<endl;
    result = Link1 + test; 
    result->print();
    cout<<"search value: "<< result->search("Good")->value <<endl;
    delete(result);
    


}