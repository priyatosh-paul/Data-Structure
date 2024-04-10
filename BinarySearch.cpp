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
int binary_search( int* arr, const int size, const int key )
{
	int leftIndex = 0;
	int rightIndex = size - 1;
	while( leftIndex <= rightIndex )
	{
		int middleIndex = ( leftIndex + rightIndex ) / 2;
		if( key == arr[ middleIndex ] )
			return middleIndex;
		else if( key > arr[ middleIndex ] )
			leftIndex = middleIndex + 1;
		else
			rightIndex = middleIndex - 1;
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
	int  index = ::binary_search( arr, 5, key );
	::print_record( index );
	return 0;
}