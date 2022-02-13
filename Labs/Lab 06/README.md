# Operations on Doubly Linked list

List ( int ignored = 0 )
Requirements:

None
 

Results:
Constructor. Creates an empty list.

~List ()
Requirements:

None

Results:
Destructor. Deallocates (frees) the memory used to store a list.

void insert ( Employee &emp )

Requirements:
None.

Results:
If the list is not empty, then inserts emp at the end.

Void remove (String id)
Requirements:

List is not empty.

Results:

Removes the data item whose employee id matched the parameter id. If the id doesn’t exist display a message “Record does not exist”


voidUpdateSalary (  int salary, String id)
Requirements:

List is not empty.

Results:

Locate the data item whose employee id matches the parameter id, then update the respective data item salary member with the parameter salary.

voidUpdateBonus ( int bonus, String id)
Requirements:
List is not empty.

Results:

Locate the data item whose employee id matches the parameter id, then update the respective data item bonus member with the parameter bonus.
 

void clear ()
Requirements:

None

Results:
Removes all the data items in a list.


boolisEmpty ()
Requirements:

None

Results:
Returns true if a list is empty. Otherwise, returns false.


void display ()
Requirements:

List is not empty.

Results:
Display the data items separated with two empty lines.

void sort ()
Requirements:

List is not empty.

Results:
Display the sorted data items on the basis of the employee salary.

Note: Write the code to sort the nodes on the basis of their data items. I.e. do not copy the data of nodes to each other.




Q2: Write code of the above explained ADT for circular singly linked list.


Q3: Write logical differences that you have noticed in all three (singly(previous lab),doubly and circular) implementations. (Write 3-4 lines only).
