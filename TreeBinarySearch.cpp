#include<iostream>
#include<string>
#include<stack>
using namespace std;
namespace NTree
{
	class BSTree;
	class TNode
	{
	private:
		TNode* _left;
		int _data;
		TNode* _right;
	public:
		TNode( const int data = 0 )throw( )
		{
			this->_left = NULL;
			this->_data = data;
			this->_right = NULL;
		}
		friend class BSTree;
	};
	class BSTree
	{
	private:
		TNode* _rootNode;
	public:
		BSTree( void )throw( )
		{
			this->_rootNode = NULL;
		}
		bool Empty( void )const throw( )
		{
			if( this->_rootNode == NULL )
				return true;
			else
				return false;
		}
		void AddNode( const int data )throw( bad_alloc )
		{
			TNode* newnode = new TNode( data );
			if( this->Empty( ) )
				this->_rootNode = newnode;
			else
			{
				TNode* trav = this->_rootNode;
				while( true )
				{
					if( data < trav->_data )
					{
						if( trav->_left == NULL )
						{
							trav->_left = newnode;
							break;
						}
						else
							trav = trav->_left;
					}
					else //if( data > trav->_data )
					{
						if( trav->_right == NULL )
						{
							trav->_right = newnode;
							break;
						}
						else
							trav= trav->_right;
					}
				}
			}
		}
		TNode* FindNode( const int data, TNode*& parentNode )
		{
			TNode* trav = this->_rootNode;
			parentNode = NULL;
			while( trav != NULL  )
			{
				if( data == trav->_data )
					return trav;
				parentNode = trav;
				if( data < trav->_data )
					trav = trav->_left;
				else
					trav = trav->_right;
			}
			parentNode = NULL;
			return NULL;
		}
		void DeleteNode( const int data )throw( string )
		{
			TNode* parentNode;
			TNode* targetNode = this->FindNode( data, parentNode );
			if( targetNode != NULL )
			{
				if( targetNode->_left  != NULL && targetNode->_right != NULL )
				{
					TNode* trav = targetNode;
					parentNode = trav;
					trav = trav->_left;
					while( trav->_right != NULL )
					{
						parentNode = trav;
						trav = trav->_right;
					}
					targetNode->_data = trav->_data;
					targetNode = trav;
				}
				if( targetNode->_left == NULL )
				{
					if( targetNode == this->_rootNode )
						this->_rootNode = this->_rootNode->_right;
					else if( targetNode == parentNode->_left )
						parentNode->_left = targetNode->_right;
					else
						parentNode->_right = targetNode->_right;
				}
				else if( targetNode->_right == NULL )
				{
					if( targetNode == this->_rootNode )
						this->_rootNode = this->_rootNode->_left;
					else if( targetNode == parentNode->_left )
						parentNode->_left = targetNode->_left;
					else
						parentNode->_right = targetNode->_left;
				}
				delete targetNode;
			}
			else
				throw string("Data not found");
		}
		void NonRecursivePreOrder( void )
		{
			stack<TNode*> stack;
			TNode* trav = this->_rootNode;

			while( !stack.empty( ) || trav != NULL )
			{
				if( trav != NULL )				
					cout<<trav->_data<<"	";
				if( trav->_right != NULL )
				{
					stack.push( trav->_right );
					trav = trav->_left;
				}
				else
				{
					if( stack.empty( ) )
						trav = NULL;
					else
					{
						trav = stack.top( );
						stack.pop( );					
					}
				}
			}
		}
		void NonRecursiveInOrder( void )
		{
			stack<TNode*> stack;
			TNode* trav = this->_rootNode;

			while( !stack.empty( ) || trav != NULL )
			{
				if( trav != NULL )
				{
					stack.push( trav );
					trav = trav->_left;
				}
				else
				{
					trav = stack.top( );
					stack.pop();
					cout<<trav->_data<<"	";
					trav = trav->_right;
				}
			}
		}
		void PreOrder( void )
		{
			this->PreOrder( this->_rootNode );
			cout<<endl;
		}
		void InOrder( void )
		{
			this->InOrder( this->_rootNode );
			cout<<endl;
		}
		void PostOrder( void )
		{
			this->PostOrder( this->_rootNode );
		}
	private:
		void PreOrder( TNode* ptrNode )
		{
			if( ptrNode == NULL )
				return;
			cout<<ptrNode->_data<<"	";
			this->PreOrder( ptrNode->_left );
			this->PreOrder( ptrNode->_right );
		}
		void InOrder( TNode* ptrNode )
		{
			if( ptrNode == NULL )
				return;
			this->InOrder( ptrNode->_left );
			cout<<ptrNode->_data<<"	";
			this->InOrder( ptrNode->_right );
		}
		void PostOrder( TNode* ptrNode )
		{
			if( ptrNode == NULL )
				return;
			this->PostOrder( ptrNode->_left );
			this->PostOrder( ptrNode->_right );
			cout<<ptrNode->_data<<" ";
		}
	};
}
int main( void )
{
	using namespace NTree;
	BSTree tree;
	tree.AddNode( 70 );
	tree.AddNode( 50 );
	tree.AddNode( 90 );
	tree.AddNode( 40 );
	tree.AddNode( 60 );
	tree.AddNode( 80 );
	tree.AddNode( 100 );

	tree.InOrder( );
	cout<<endl;
	tree.NonRecursiveInOrder( );
	return 0 ;
}