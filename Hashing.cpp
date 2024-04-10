#include<iostream>
using namespace std;

#define SIZE 5
int get_hashcode( int data )
{
	int result = 0;
	int prime = 31;
	result = result + prime * data;
	return result;
}
void add( int* arr, int data )
{
	int hashCode = ::get_hashcode( data );
	int slot = hashCode % SIZE;
	arr[ slot ] = data;
}
int search( int* arr, int key )
{	
	int slot = ::get_hashcode( key ) % SIZE;
	if( key == arr[ slot ] )
		return slot;
	else
		return -1;
}
void print_record( int* arr, int size )
{
	for( int index = 0; index < size; ++ index )	
		cout<<index <<"		"<<arr[ index ]<<endl;	
}
int main( void )
{
	int arr[ SIZE ];
	add( arr, 85 );
	add( arr, 31 );
	add( arr, 27 );
	add( arr, 73 );
	add( arr, 59 );
	::print_record( arr, SIZE );

	int index = ::search( arr, 23 );
	cout<<index<<endl;
	return 0;
}