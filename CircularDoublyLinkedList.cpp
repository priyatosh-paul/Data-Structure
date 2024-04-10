#include<iostream>
#include<string>
using namespace std;
namespace NList
{
	class TList;
	class TNode
	{
	private:
		TNode* _prev;
		int _data;
		TNode* _next;
	public:
		TNode( const int data = 0 )throw( )
		{
			this->_prev = NULL;
			this->_data = data;
			this->_next = NULL;
		}
		friend class TList;
	};
	class TList
	{
	private:
		TNode* _head;
		TNode* _tail;
	public:
		TList( void )throw( )
		{
			this->_head = NULL;
			this->_tail = NULL;
		}
		bool Empty( void )const throw( )
		{
			if( this->_head == NULL )
				return true;
			else
				return false;
		}
		void AddFirst( const int data  )throw( bad_alloc )
		{
			TNode* newnode = new TNode( data );
			if( this->Empty( ) )
			{
				this->_tail = newnode;
				this->_head = newnode;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;
			}
			else
			{
				newnode->_next = this->_head;
				this->_head->_prev = newnode;
				this->_head = newnode;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;
			}
		}
		void AddLast( const int data  )throw( bad_alloc )
		{
			TNode* newnode = new TNode( data );
			if( this->Empty( ) )
			{				
				this->_head = newnode;
				this->_tail = newnode;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;
			}
			else
			{
				this->_tail->_next = newnode;
				newnode->_prev = this->_tail;
				this->_tail = newnode;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;
			}
		}
		int GetNodeCount( void ) const throw( )
		{
			int nodeCount = 0;
			if( !this->Empty( ) )			
			{				
				TNode* trav = this->_head;		
				do
				{
					++ nodeCount;
					trav = trav->_next;
				}
				while( trav != this->_head );				
			}
			return nodeCount;
		}
		void AddNodeAtSpecifiedPosition( const int position , const int data )
		{
			if( position <= 0 )
				throw string("Invalid position");
			else if( position == 1 )
				this->AddFirst( data );
			else if( position > this->GetNodeCount( ) )
				this->AddLast( data );
			else
			{
				TNode* trav = this->_head;
				for( int count = 1; count < position - 1; ++ count )
				{
					trav = trav->_next;
				}				
				TNode* newnode = new TNode( data );
				newnode->_next = trav->_next;
				trav->_next->_prev = newnode;
				trav->_next = newnode;
				newnode->_prev = trav;
			}
		}
		void DeleteFirst( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("List is empty");
			else if( this->_head == this->_tail )
			{
				delete this->_head;
				this->_head = this->_tail = NULL;			
			}
			else
			{
				TNode* ptrNode = this->_head;
				this->_head = this->_head->_next;				
				delete ptrNode;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;
			}
		}
		void DeleteLast( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("List is empty");
			else if( this->_head == this->_tail )
			{
				delete this->_head;
				this->_head = this->_tail = NULL;			
			}
			else
			{
				this->_tail = this->_tail->_prev;
				delete this->_tail->_next;
				this->_head->_prev = this->_tail;
				this->_tail->_next = this->_head;				
			}
		}
		void DeleteNodeFromSpecifiedPosition( const int position )
		{
			if( position <= 0 )
				throw string("Invalid position");
			else if( this->Empty( ) ) 
				throw string("List is empty");
			else if( position == 1 )
				this->DeleteFirst( );
			else if( position >= this->GetNodeCount( ) )
				this->DeleteLast( );
			else
			{
				TNode* trav = this->_head;
				for( int count = 1; count < position - 1; ++ count )
				{
					trav = trav->_next;
				}				
				TNode* ptrNode = trav->_next;
				trav->_next = ptrNode->_next;
				ptrNode->_next->_prev = trav;
				delete ptrNode;
			}
		}
		void ReverseList( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("List is empty");
			else
			{
				TNode* trav = this->_head;
				TNode* current;
				TNode* previous = this->_tail;
				do
				{
					current = trav;
					trav = trav->_next;
					current->_next = previous;
					current->_prev = trav;
					previous = current;
				}while( trav != this->_head );
				this->_tail = this->_head;
				this->_head = previous;
			}
		}
		void PrintList( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("List is empty");
			else
			{				
				TNode* trav = this->_head;		
				do
				{
					cout<<trav->_data<<"	";
					trav = trav->_next;
				}
				while( trav != this->_head );
				cout<<endl;
			}
		}
		~TList( void )
		{
			this->Clear( );
		}
	private:
		void Clear( void )
		{
			while( !this->Empty( ) )
				this->DeleteFirst( );
		}
	};
}
void accept_record( int& data )
{
	cout<<"Enter data	:	";
	cin>>data;
}
void accept_position( int& position )
{
	cout<<"Enter position	:	";
	cin>>position;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Add First."<<endl;
	cout<<"2.Add Last."<<endl;
	cout<<"3.Add Node At Specified Position"<<endl;
	cout<<"4.Delete First"<<endl;
	cout<<"5.Delete Last"<<endl;
	cout<<"6.Delete Node From Specified Position."<<endl;
	cout<<"7.Reverse List."<<endl;
	cout<<"8.Print List."<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	try
	{
		int choice, data, position;
		using namespace NList;
		TList listInstance;
		while( ( choice = ::menu_list( ) ) != 0 )
		{
			try
			{
				switch( choice )
				{
				case 1:
					::accept_record( data );
					listInstance.AddFirst( data );
					break;	
				case 2:
					::accept_record( data );
					listInstance.AddLast( data );
					break;
				case 3:
					::accept_position( position );
					::accept_record( data );
					listInstance.AddNodeAtSpecifiedPosition( position , data );
					break;
				case 4:
					listInstance.DeleteFirst( );
					break;
				case 5:
					listInstance.DeleteLast( );
					break;
				case 6:
					::accept_position( position );
					listInstance.DeleteNodeFromSpecifiedPosition( position );
					break;
				case 7:
					listInstance.ReverseList( );
					break;
				case 8:
					listInstance.PrintList();
					break;
				}
			}
			catch( bad_alloc ex )
			{
				cout<<ex.what()<<endl;
			}
			catch( string ex )
			{
				cout<<ex<<endl;
			}
		}
	}
	catch(...)
	{
		cout<<"Exception"<<endl;
	}
	return 0;
}