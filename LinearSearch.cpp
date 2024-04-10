#include<iostream>
using namespace std;
void accept_record( int* arr, const int size )
{
	for( int index = 0; index < 5; ++ index )
	{
		cout<<"Enter number	:	";
		cin>>arr[ index ];
	}
}
void accept_key( int& key )
{
	cout<<"Enter key	:	";
	cin>>key;
}
void print_record( int* arr, const int size )
{
	for( int index = 0; index < 5; ++ index )
	{
		cout<<arr[ index ]<<"	";
	}
	cout<<endl;
}
int linear_search( int* arr, const int size, const int key )
{
	for( int index = 0; index < size; ++ index )
	{
		if( key == arr[ index ] )
			return index;
	}
	return -1;
}
void print_record( const int index )
{
	if( index == -1 )
		cout<<"Key Not Found"<<endl;
	else
		cout<<"Key found at index	:	"<<index<<endl;
}
int main( void )
{	
	int arr[ 5 ];	
	::accept_record( arr, 5 );
	::print_record( arr, 5 );
	int key;
	::accept_key( key );
	int  index = ::linear_search( arr, 5, key );
	::print_record( index );
	return 0;
}