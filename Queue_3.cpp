#include<iostream>
#include<string>
using namespace std;
namespace NList
{
	class TList;
	class TNode
	{
	private:
		int _data;
		TNode* _next;
	public:
		TNode( void )throw( )
		{
			this->_data = 0;
			this->_next = NULL;
		}
		TNode( int data )throw( )
		{
			this->_data = data;
			this->_next = NULL;
		}
		friend class TList;
	};//end of TNode class
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
		int GetData( void )const throw( string )
		{
			if( this->Empty( ) )
				throw string("List is empty");
			else
				return this->_head->_data;
		}
		void AddLast( const int data )throw( bad_alloc )
		{
			TNode* newnode = new TNode( data );
			if( this->Empty( ) )
			{
				this->_head = newnode;
				this->_tail = newnode;
			}
			else
			{
				this->_tail->_next = newnode;
				this->_tail = newnode;
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
namespace NQueue
{
	using namespace NList;
	class TQueue
	{
		TList list;
	public:
		bool Empty( void )const throw( )
		{
			return list.Empty( );
		}
		void EnQueue( const int data  )throw( string )
		{
			try
			{
				list.AddLast( data );
			}
			catch( bad_alloc ex )
			{
				throw string("Queue is full");
			}
		}
		int Peek( void )const throw( string )
		{
			try
			{
				return list.GetData( );
			}
			catch( string ex )
			{
				throw string("Queue is empty");
			}
		}
		void DeQueue( void )throw( string ) 
		{
			try
			{
				list.DeleteFirst(  );
			}
			catch( string ex )
			{
				throw string("Queue is empty");
			}
		}
	};
}

void accept_record( int& data )
{
	cout<<"Enter data	:	";
	cin>>data;
}
void print_record( const int& data )
{
	cout<<"Removed element is	:	"<<data<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.EnQueue."<<endl;
	cout<<"2.DeQueue."<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	try
	{
		int choice, data;
		using namespace NQueue;
		TQueue queueInstance;
		while( ( choice = ::menu_list( ) ) != 0 )
		{
			try
			{
				switch( choice )
				{
				case 1:
					::accept_record( data );
					queueInstance.EnQueue( data );
					break;
				case 2:
					data = queueInstance.Peek();
					::print_record( data );
					queueInstance.DeQueue( );
					break;
				}
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