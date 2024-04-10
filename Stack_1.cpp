#include<iostream>
#include<string>
using namespace std;
namespace NStack
{
	class TStack
	{
	private:
		int _top;
		int _size;
		int** _arr;
	public:
		TStack( void )throw( )
		{
			this->_top = -1;
			this->_size = 0;
			this->_arr = NULL;
		}
		TStack( const int size )throw( bad_alloc )
		{
			this->_top = -1;
			this->_size = size;
			this->_arr = new int*[ this->_size ];
			for( int index = 0; index < this->_size; ++ index )
				this->_arr[ index ] = NULL;
		}
		bool Empty( void )const throw( )
		{
			if( this->_top == -1 )
				return true;
			else
				return false;
		}
		bool Full( void )const throw( )
		{
			if( this->_top == this->_size - 1 )
				return true;
			else
				return false;
		}
		void Push( const int data )throw( string )
		{
			if( this->Full( ) )
				throw string("Stack is full");
			else
			{
				this->_top = this->_top + 1;
				this->_arr[ this->_top ] = new int( data );
			}
		}
		int Peek( void )const throw( string )
		{
			if( this->Empty( ) )
				throw string("Stack is empty");
			else
				return *( this->_arr[ this->_top ] );
		}
		void Pop( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("Stack is empty");
			else
			{
				delete this->_arr[ this->_top ];
				this->_arr[ this->_top ] = NULL;
				this->_top = this->_top - 1;
			}
		}
		~TStack( void )
		{
			this->Clear( );
		}
	private:
		void Clear( void )
		{
			if( this->_arr != NULL )
			{
				for( int index = this->_top; index >= 0 ; -- index )
				{
					delete this->_arr[ index ];
				}
				delete[] this->_arr;
				this->_arr = NULL;
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
	cout<<"Popped element is	:	"<<data<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit."<<endl;
	cout<<"1.Push."<<endl;
	cout<<"2.Pop."<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{	
	try
	{
		int choice, data;
		using namespace NStack;
		TStack stackInstance( 5 );
		while( ( choice = ::menu_list( ) ) != 0 )
		{
			try
			{
				switch( choice )
				{
				case 1:
					::accept_record( data );
					stackInstance.Push( data );
					break;
				case 2:
					data = stackInstance.Peek( );
					::print_record( data );
					stackInstance.Pop( );
					break;
				}
			}
			catch( string ex )
			{
				cout<<ex<<endl;
			}
		}
	}
	catch( ... )
	{
		cout<<"Exception"<<endl;
	}
	return 0;
}