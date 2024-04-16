#ifndef Included_Linkedlist_H
#define Included_Linkedlist_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <iterator>
#include "assert.h"
#include "StudentInfo.h"

using namespace std;

//********************************************************************************************** 
// Create a struct using template which will hold all the student information using a class
//**********************************************************************************************
template <class Type>
struct nodeType
{
  	Type info;
  	nodeType<Type> *next;
};


//*********************************************************************************
// This class specifies the members to implement an iterator to a linked list.
//*********************************************************************************
template <class Type>
class linkedListIterator
{
   public:
   	
       linkedListIterator(); 
	   // Default constructor
	   
       Type operator*(); 
	   // To overload dereferencing operator*
	   
       linkedListIterator<Type> operator++();
	   // Overload the pre-increment operator
	   
       bool operator==(const linkedListIterator<Type>& right) const;
	   // Overload the equality operator
	   
       bool operator!=(const linkedListIterator<Type>& right) const;
	   // Overload the not equal to operator


   private:
       nodeType<Type> *current;
	   // Pointer to point to the current node in the linked list
};


// Definition of the function of the class linkedListIterator
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current=NULL;
}


template <class Type>
Type linkedListIterator<Type>::operator* ()
{
    return current->info;
}


template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current=current->next;
    return *this;
}


template <class Type>
bool linkedListIterator<Type>::operator ==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}


template <class Type>
bool linkedListIterator<Type>::operator !=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}


//*********************************
// Base class - linkedListType
//*********************************
template <class Type>
class linkedListType
{
    public:
    	
        const linkedListType<Type>& operator =(const linkedListType<Type>& ); 	
		// Overload the assignment operator
		
        void initializeList(); 
		// Initialize the list to an empty state
        
		bool isEmptyList() const; 
		// To determine whether the list is empty
		
        void print() const; 
		// To output the data contained in each node
        
        int length() const; 
		// To return the no of nodes in the list
        
        void destroyList(); 
		// To delete all the nodes from the list
		
        Type front() const; 
		// To return the first element of the list
        
        Type back() const; 
		// To return the last element of the list
		
        linkedListIterator<Type> begin();
        // To return an iterator at the beginning of the linked list
        
        linkedListIterator<Type> end();
        // To return an iterator such that current is set to NULL
        
        linkedListType(); 
		// Default constructor
        
        linkedListType(const linkedListIterator<Type>& otherList); 
		// Copy constructor
        
        ~linkedListType(); 
		// Destructor- to delete all the nodes from the list

    protected:
    	
        int num; 
		// Variable to store the no. of elements in the list
		
        nodeType<Type> *first; 
		// Pointer to the first node of the list
		
        nodeType<Type> *last; 
		// Pointer to the last node of the list

    private:
    	
        void copyList(const linkedListType<Type>& otherList);
		// To make a copy of otherList
        
		nodeType<Type> *next;
};


template <class Type>
bool linkedListType<Type>::isEmptyList()const
{
    return (first=NULL);
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first=NULL;
    last=NULL;
    num=0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp; // Pointer to deallocate memory occupied by the node

    while(first!=NULL) // wWile there are nodes in the list
    {
        temp=first; // Set temp to current node
        first=first->next; // Advance first to the next node
        delete temp; // Deallocate the memory occupied by temp
    }
    
	last=NULL; // Initialize last to NULL, first has been set to NULL by while loop
    num=0;
}


template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); // Delete if the list has any nodes
}

template <class Type>
void linkedListType<Type>::print() const
{
    cout << "\tStudent Informations " << endl;
    cout << "........................................................................................." << endl;

    nodeType<Type> *current=first;
    
   	cout << "\tStudent name\t\t\t" << "Matric number\t" << "\tYear" << "\t     CGPA" << endl; 
	    
    while(current!=NULL)
	{   
	    cout << left;
        cout << "\t" << setw(32) << current-> info.get_StudentName() ;
        cout << "  " << setw(21) << current-> info.get_StudentMatric() ;
        cout << "  " << setw(10) << current-> info.get_StudentYear() ;
        cout << "  " << setw(8) << fixed << setprecision(2) << current-> info.get_Student_CGPA() << endl;
        current=current->next;
    }// end while
        cout << "........................................................................................." << endl;

}


template <class Type>
int linkedListType<Type>::length()const
{
    return num;
}


template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first!= NULL);
    return first; 
}


template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last!=NULL);
    return last;
}


template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}


template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}


template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list

    if(first!=NULL) // make the list empty if it is nonempty
        destroyList();
    
	if(otherList.first == NULL) //otherList is empty
    {
        first=NULL;
        last=NULL;
        num=0;
    }
   
    else
    {
        current=otherList.first; // current points to the list to be copied
        num = otherList.count;

        first = new nodeType <Type>; //copy the first node and create the node
        first->info= current->info;
        first->next=NULL;
        last=first;
        current=current->next;

    while (current!=NULL) // copy the remaining list
    {
        newNode = new nodeType<Type>;
        newNode->info = current->info;
        newNode->next = NULL;

        last->next = newNode;
        last = newNode;

        current=current->link;
     }//end while
   
   }//end else

}//end copylist

template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListIterator<Type>& otherList)
{
     first = NULL;
     copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator= (const linkedListType<Type>& otherList)
{
      if (this != &otherList) // to avoid self-copy
      {
          copyList(otherList);
      }
      return *this;
}

//*******************************************
// Derived class - Unordered Linked List
//*******************************************
template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
    public:
        bool search(const string searchItem) const;
		// To determine whether searchItem is in the list
		
        void insertFirst(const Type& newItem);
		// To insert newItem at the beginning of the list
		
        void insertLast(const Type& newItem);
		//To insert newItem at the end of the list
		
        void deleteNode(const string deleteItem);
		// To delete deleteItem from the list
		
    private:
    	
    	int num;
    	// Variable to store the no. of elements in the list
};


template <class Type>
bool unorderedLinkedList<Type>::search(const string searchItem) const
{
    bool found = false;
    
    nodeType<Type> *current; //pointer to traverse the list
 
    current =this->first;  //start the search at the first node
 
    while (current != NULL && !found)
	{
        if (current-> info.get_StudentMatric() == searchItem)
            found = true;
        else
            current = current->next;
	}// end while

	if (found)
	{
		cout << "\tStudent information found in Unordered Linked List" << endl;
        cout << "........................................................................................." << endl;   		
		cout << "\tStudent name\t\t\t" << "Matric number\t" << "\tYear" << "\t     CGPA" << endl;  
		       
        cout << left;
        cout << "\t" << setw(32) << current-> info.get_StudentName() ;
        cout << "  " << setw(21) << current-> info.get_StudentMatric() ;
        cout << "  " << setw(10) << current-> info.get_StudentYear() ;
        cout << "  " << setw(8) << fixed << setprecision(2) << current-> info.get_Student_CGPA() << endl;
        cout << "........................................................................................." << endl;
	}// end if
	
	else 
		cout << "\tNo data found in the unordered linked list...";

 
    return found;
}//end search


template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; // pointer to create the new node
    newNode = new nodeType<Type>; // create the new node
    nodeType<Type> *first;
    nodeType<Type> *last;
    newNode->info = newItem;
    
    newNode->next=this->first; //insert newnode
    this->first=newNode;

    num++;

    if(this->last == NULL) // if list is empty, newNode is the last node in the list
    	this->last=newNode;
    	
}// end insertFirst


template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
   	newNode->info = newItem; //store the new item in the node
  	newNode->next = NULL; //set the link field of newNode to NULL
   	nodeType<Type> *first;
   	nodeType<Type> *last;

    if (first == NULL)
    {
        first= newNode;
        last= newNode;
        num++;
    }// end if
    
    else
    {
        last->next= newNode;
        last= newNode;
        num++;
    }
}// end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const string deleteItem)
{
    nodeType<Type> *current; // pointer to traverse the list
    nodeType<Type> *trailCurrent; // pointer just before current
    nodeType<Type> *first;
    nodeType<Type> *last;
    bool found;

    if (this->first == NULL) //Case 1; the list is empty.
        cout << "\n\tUnable to delete from an empty unordered linked list." << endl;
        
    else
    {
        //Case 2  The node need to be deleted is the 1st node
        if (this->first-> info.get_StudentMatric() == deleteItem)
         {
            current = this->first;
            this->first = this->first->next;
            num--;
            if (this->first == NULL) // list has only one node
                this->last = NULL;
            delete current;
          }
          
          else // search the list for the node with given info
          {
              found = false;
              trailCurrent= this->first;//set trailCurrent points to 1st node
              current= this->first->next;//set current points to 2nd node

              while (current !=NULL && !found)
              {
                  if (current->info.get_StudentMatric() != deleteItem)
                  {
                      trailCurrent= current;
                      current= current->next;
                  }
                  
                  else
                    found = true;
              }// end while

              if(found)//if found, delete the node
              {
                  trailCurrent->next = current->next;
                  num--;

                  if (this->last == current)//Case 3, node to be deleted was the last node
                    this->last = trailCurrent; //update the value of last

                  delete current;//delete the node from the list
                  
                  cout << "\n\tThe student info with matric number " <<  deleteItem << " deleted from the Unordered Linked List." << endl;
              }
              
              else
                cout << "\n\tThe student info with matric number " <<  deleteItem << " is not in the Unordered Linked List." << endl; // case4
          }//end else
    }//end else
}//end deleteNode



//*****************************************
// Derived class - Ordered Linked List
//*****************************************
template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
	public:
		
 		bool search(const string searchItem) const; 
		//Function to determine whether searchItem is in the list.
    	
		void insert(const Type& newItem); 
		//Function to insert newItem in the list.
    	
		void insertFirst(const Type& newItem); 
		//Function to insert newItem at the beginning of the list.
    	
		void insertLast(const Type& newItem); 
		//Function to insert newItem at the end of the list.
    	
		void deleteNode(const string deleteItem); 
		//Function to delete deleteItem from the list.
		
	private:
		
    	int num; 
    	// Variable to store the no. of elements in the list
};
 
 
template <class Type>
bool orderedLinkedList<Type>::search(const string searchItem) const
{
    bool found = false;
    
    nodeType<Type> *current; //pointer to traverse the list
 
    current =this->first;  //start the search at the first node
 
    while (current != NULL && !found)
	{
        if (current-> info.get_StudentMatric() == searchItem)
            found = true;
            
        else
            current = current->next;
	}
 
	if (found)
	{	
		cout << "\tStudent information found in Ordered Linked List" << endl;
        cout << "........................................................................................." << endl;
   		cout << "\tStudent name\t\t\t" << "Matric number\t" << "\tYear" << "\t     CGPA" << endl;  
		       
        cout << left;
        cout << "\t" << setw(32) << current-> info.get_StudentName() ;
        cout << "  " << setw(21) << current-> info.get_StudentMatric() ;
        cout << "  " << setw(10) << current-> info.get_StudentYear() ;
        cout << "  " << setw(8) << fixed << setprecision(2) << current-> info.get_Student_CGPA() << endl;
        cout << "........................................................................................." << endl;
	
	}
	
	else 
		cout << "\tNo data found in the ordered linked list...";

 
    return found;
}//end search
 
 
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;  //pointer to create a node
 
    bool  found;
 
    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newItem in the node
    newNode->next = NULL;      //set the link field of the node to NULL
 
    if (this->first == NULL)  //Case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->num++;
    }
    
    else
    {
        current = this->first;
        found = false;
 
        while (current != NULL && !found) //search the list
        
           if (current-> info.get_StudentMatric() >= newNode -> info.get_StudentMatric())
               found = true;
           else
           {
               trailCurrent = current;
               current = current->next;
           }
 
        if (current == this->first)      //Case 2
        {
            newNode->next = this->first;
            this->first = newNode;
            this->num++;
        }
        
        else                       //Case 3
        {
            trailCurrent->next = newNode;
            newNode->next = current;
 
            if (current == NULL)
                this->last = newNode;
 
            this->num++;
        }
        
    }//end else

}//end insert

 
template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst
 
 
template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast
 

template<class Type>
void orderedLinkedList<Type>::deleteNode(const string deleteItem)
{
    nodeType<Type> *current; // pointer to traverse the list
    nodeType<Type> *trailCurrent; // pointer just before current
    nodeType<Type> *first;
    nodeType<Type> *last;
    bool found;

    if (this->first == NULL) //Case 1; the list is empty.
        cout << "\n\tUnable to delete from an empty ordered linked list." << endl;
   
    else
    {
        //Case 2  The node need to be deleted is the 1st node
        if (this->first-> info.get_StudentMatric() == deleteItem)
         {
            current = this->first;
            this->first = this->first->next;
            num--;
            if (this->first == NULL) // list has only one node
                this->last = NULL;
            delete current;
          }
          
          else // search the list for the node with given info
          {
              found = false;
              trailCurrent= this->first;//set trailCurrent points to 1st node
              current= this->first->next;//set current points to 2nd node

              while (current !=NULL && !found)
              {
                  if (current->info.get_StudentMatric() != deleteItem)
                  {
                      trailCurrent= current;
                      current= current->next;
                  }
                  else
                    found = true;
              }// end while

              if(found)//if found, delete the node
              {
                  trailCurrent->next = current->next;
                  num--;

                  if (this->last == current)//Case 3, node to be deleted was the last node
                    this->last = trailCurrent; //update the value of last

                  delete current;//delete the node from the list
                  
                  cout << "\n\tThe student info with matric number " <<  deleteItem << " deleted from the Ordered Linked List." << endl;
              }
              else
                cout << "\n\tThe student info with matric number " <<  deleteItem << " is not in the Ordered Linked List." << endl; // case4
          
		  }//end else
   
   }//end else

}// end deleteNode
#endif
