#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Link
{
    private:
    
    typedef struct _node
    {
        struct _node *next;
        struct _node *prev;
        char *key;
        char *value;
    }node_t;

    node_t *head;
    
    public:
    Link();
    virtual ~Link();
    node_t *gethead() {return this->head;}
    void sethead(node_t* temp) {this->head = temp;}
    void insert(char *key, char *value);
    Link::node_t* search(char *value, int type=0); 
    void del(char *value, int type=0);
    void destory();
    void print();
    friend Link *operator+( Link &ls1,Link &ls2);
};