#ifndef Linked_list_H_
#define Linked_list_H_
//Create New Node
Node *Create_node(u32 value);
//Add Node
void Add(Node *node);
//Search
Node *Search(u32 value);
//Insert New Node --> After Node
void InsertAfter(Node *P_after, Node *P_new);
//Delete Node
void Delete(Node *P_delete);
//Display All
void DisplayAll();
//Display Node
void Display_Node(Node *P_Display);
//Delete node using value
void Delete_node_using_value(u32 value);
//Add and Insert
void Add_and_Insert(u32 value,u32 Index);
#endif