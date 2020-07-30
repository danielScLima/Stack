// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "stack.h"

TEST_CASE( "Testing the insert call in the stack", "[single-file]" )
{
	StackDataStructure s;

	REQUIRE( s.topNode() == nullptr );
	s.insertNode("home");

	NodeOfStack* node = s.removeNode();
	REQUIRE( node != nullptr );
	REQUIRE( node->data.compare("home") == 0 );

	//cleaning
	delete node;
}

TEST_CASE( "Testing the leak ocurence", "[single-file]" )
{
	StackDataStructure s;

	REQUIRE( s.topNode() == nullptr );
	s.insertNode("home");
}

TEST_CASE( "Testing the insert and remove calls in the stack", "[single-file]" )
{
    SECTION( "Inserting" )
	{
		StackDataStructure s;
		s.insertNode("home");
        s.insertNode("cat");
		NodeOfStack* node = s.topNode();
		REQUIRE( node->data.compare("cat") == 0 );
		node = s.removeNode();
		delete node;
		
		node = s.topNode();
		REQUIRE( node->data.compare("home") == 0 );
		node = s.removeNode();
		delete node;
		
		REQUIRE( s.topNode() == nullptr );
    }
}

SCENARIO( "Teste the insert in the stack", "[single-file]" )
{
    GIVEN( "A stack with 3 elements" )
	{
        StackDataStructure s;
		s.insertNode("home");
		s.insertNode("cat");
		s.insertNode("roof");

        WHEN( "A single entry is removed" )
		{
			NodeOfStack* rem = s.removeNode();
			REQUIRE( rem->data.compare("roof") ==0 );
			delete rem;

			THEN( "It should exist 2 other nodes" )
			{
				NodeOfStack* top = nullptr;
				while (s.topNode() != nullptr)
				{
					top = s.removeNode();
					assert( top != nullptr);
					delete top;
				}
			}
		}
	}
}

SCENARIO( "Teste the insert and delete in the stack", "[single-file]" )
{
    GIVEN( "A stack " )
	{
        StackDataStructure s;

        WHEN( "5 nodes are inserted" )
		{
            REQUIRE( s.insertNode("home") != nullptr );
			REQUIRE( s.insertNode("cat") != nullptr );
			REQUIRE( s.insertNode("roof") != nullptr );
			REQUIRE( s.insertNode("red") != nullptr );
			REQUIRE( s.insertNode("blue") != nullptr );

            THEN( "It should 5 nodes, in order" )
			{
				NodeOfStack* node = nullptr;
				node = s.removeNode();
                
				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("blue") ==0 );
				delete node;

				node = s.removeNode();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("red") ==0 );
				delete node;

				node = s.removeNode();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("roof") ==0 );
				delete node;

				node = s.removeNode();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("cat") ==0 );
				delete node;

				node = s.removeNode();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("home") ==0 );
				delete node;
            }
        }
    }
}

