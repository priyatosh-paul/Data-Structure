#include<iostream>
#include<string>
using namespace std;
namespace NQueue
{
	class TQueue
	{
	private:
		int _rear;
		int _front;
		int _size;
		int** _arr;
	public:
		TQueue( void )throw( )
		{
			this->_rear = this->_front = -1;
			this->_size = 0;
			this->_arr = NULL;
		}
		TQueue( const int size )throw( bad_alloc )
		{
			this->_rear = -1;
			this->_front = -1;
			this->_size = size;
			this->_arr = new int*[ this->_size ];
			memset( this->_arr, NULL, sizeof( int* ) * this->_size );
		}
		bool Empty( void )const throw( )
		{
			if( this->_rear == -1 )
				return true;
			else
				return false;
		}
		bool Full( void )const throw( )
		{
			if( ( ( this->_rear + 1 ) % this->_size )  == this->_front )
				return true;
			else
				return false;
		}
		void EnQueue( const int data )throw( string, bad_alloc )
		{
			if( this->Full( ) )
				throw string("Queue is full");
			else
			{
				if( this->_rear == -1 )
					this->_front = 0;
				this->_rear = ( this->_rear + 1 ) % this->_size;
				this->_arr[ this->_rear ] = new int( data );
			}
		}
		int Peek( void )const throw( string )
		{
			if( this->Empty( ) )
				throw string("Queue is empty.");
			else
				return *( this->_arr[ this->_front ] );
		}
		void DeQueue( void )throw( string )
		{
			if( this->Empty( ) )
				throw string("Queue is empty.");
			else
			{
				if( this->_rear == this->_front )
				{
					delete this->_arr[ this->_front ];
					this->_arr[ this->_front ] = NULL;
					this->_rear = -1;
					this->_front = -1;
				}
				else
				{
					delete this->_arr[ this->_front ];
					this->_arr[ this->_front ] = NULL;
					this->_front = ( this->_front + 1 ) % this->_size;
				}
			}
		}
		~TQueue( void )
		{
			this->Clear( );
		}
	private:
		void Clear( void )
		{
			if( this->_arr != NULL )
			{
				for( int index = 0; index < this->_size; ++ index )
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
		TQueue queueInstance( 5 );
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