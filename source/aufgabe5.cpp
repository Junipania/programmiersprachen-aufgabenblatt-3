#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

bool is_even(unsigned int i)
{
  return (i % 3) != 0;  
}

bool is_multiple_of_3(unsigned int i)
{
  return (i % 3) == 0;  
}

TEST_CASE ( " filter alle vielfache von drei " , " [ erase ] " )
{
    std::vector<unsigned int> v(100);

    for (auto& v0 : v){ 
		v0 = std::rand()%100;
    }
    v.erase( std::remove_if(v.begin(), v.end(), is_even), v.end() );

    REQUIRE ( std::all_of( v.begin(), v.end(), is_multiple_of_3));
}

int main ( int argc , char* argv [])
{
    return Catch::Session().run(argc, argv);
}
