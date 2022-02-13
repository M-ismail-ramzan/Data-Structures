## Check .pdf for Docs on Code.

LINKED LIST AND OUEUES

#lmplentation of Citizens Database in C++
## Develop a Database of Citizens for the Country. The System consists of following parts:

1. Citizens Basic Information Database (CBID).

2. Citizens Criminal Information Database (CCID).




## Citizens Basic Information Database CBID


CBID is the centralized system which means CCID would be connected to it. Each record would be 
identified by CNIC in CBID, then further linked to related CCID record. CBID record contains 
following information of each citizen.
i.  CNIC (4-digit unique number)

ii.  Name

iii.  Father Name

iv.  Gender

v.  Address

vi.  Nationality


## CBID must have following features:

i.  Data Structure must be strongly connected that is, each node contains the address of its next

node as well as previous node.

ii.  List must be maintained in Ascending order based on CNIC upon new Record entry.

iii.  Locating and Updating Record must be based on CNIC.



Citizens Criminal Information Database CCID

CCID is to keep Citizens criminal record. Each record contains following information of each 
citizen.
i.  CNIC (4-digit unique number)

ii.  Crimes

a. Details of each Crime.

b. Punishment

c. Fine

## CCID must have following features:

i.  Data Structure must be strongly connected that is, each node has the address of the next node
and the previous node and the last node can access head of the list.

ii.  List must be maintained in Ascending order based on CNIC upon new Record entry.

iii.  Locating and Updating Record must be based on CNIC.


iv.  “Crimes” is a Singly Linked List, each Node of a List contains all the information related to 
that Crime/Case.
v.  As, CBID is the centralized Database; So, Node in CBID and CCID having same CNIC must have a 
two-way relationship i.e. If pointer is at some Node in CBID and wants to access criminal record of 
that person, it should be able to directly access that Node in CCID without the need of searching 
the whole Criminal Database to locate and see criminal record against concerned CNIC and 
vice-versa.


## General Functionalities to Include:
All following functionalities will be implemented in the Database class.

i.  Database Initialization: Upon running the program, it should read data for each Database from 
related Data Files and store it in a Singly Linked-List-Based-Queue following FIFO rule — This 
queue class is named Datapipeline and a skeleton for it is provided in the CitizensDatabase.h file. 
After loading all data into the Datapipeline Queue, program should start populating each Database 
(CBID and CCID ) with related Queue Data following First-In-First- Out Rule i.e. FIFO.
ii.  Search person by CNIC in CBID and display all Record from CBID and CCID

iii.  Search person by CNIC in CCID and display all Record from CBID and CCID

iv.  Search person by CNIC and display all Record from CBID and CCID

v.  Update record in CBID i.e. Getter and Setter functions for: Name, F. Name, Address, 
Nationality.
vi.  Add new crime and related data into Crimes-List of CCID.

vii.  Delete crime from Crimes-List of CCID.

viii.  Update Crimes-List record data i.e. Details, Charges, Punishment, Fine. Identify it on CNIC Crime































