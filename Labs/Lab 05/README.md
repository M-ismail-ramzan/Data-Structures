# Task 1:
Problem:
A Doctors Assistant is managing patient appointments using singly list. List has nodes of patient
in which patient name is of type char. Following are the functions he will be needing to do his
work properly.
a. A constructor List(char ignored=0) to create an empty List
b. Insert an appointment void Append(char patientName). Doctor will attend patients on
First Come First Serve basis. So every new appointment will be added at the end of the
List
c. Appointment can be scheduled in the middle of the List if Doctor says so Void insertAt (
char patientName , int index)
d. Appointment can be cancelled by the patient void remove(char patientName)
e. Appointment can be replaced void replace ( char patientName )
f. An bool isEmpty() function to check if there any appointments left. Returns true if there
is no appointment left otherwise it will return false
g. A void display() function to print all appointments

h. A void split_appointments(int index) function to split appointments on two different
days
i. All appointments of the day can be cancelled if doctor is not available void clear()
(remove all data items from the list)
j. A destructor ~List(), deallocated the memory used to store the list

Test Cases:
1. Patients A, B, C, D come to get an appointment. A walks in first then B and at last D
2. Patient E comes in an emergency doctor decides to give him slot 2 right after Patient B
3. Patient D went out of city, so he won’t be able to come. He calls to get his appointment
cancelled
4. Patient F wants an appointment at the same day, but no slot is free. Meanwhile Patient B
calls to cancel his appointment. So assistant schedules Patient Fs appointment at the slot
of Patient B
5. Doctor asks assistant for the list of appointments in printed form
6. Doctor realizes he won’t be able to attend remaining patients. So, he asks his assistant to
split the appointment in half.
7. At the end of the day, assistant clears all the appointments of that day and run isEmpty()
function to see is there any appointments left
8. Then he frees all the memory used by the list of that day