# Linklist structure practice in C++

## structure

The structure containes 4 members

The contents are value and key can be used as a pair

1. key
2. value

The connection used the member

	3. next
 	4. prev

The private member "head" indicate the start of the link list



## Function

```c++
void insert(char *key, char *value);
Link::node_t* search(char *value, int type=0); 
void del(char *value, int type=0);
void destory();
void print();
friend Link *operator+( Link &ls1,Link &ls2);
```

### Note:

- insert can only support 1 result for now
- del can only delete one node each time
- the parameter "type" in search and delete is used to choose search for "key" or "value" in structure member
- The outside operator overloading allow using the "+" to combine two Linklist.
  - return type is a pointer to Link class
  - need to delete at the end



**An example usage is in the test,  more details can be read from source code**

****

