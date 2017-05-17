#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

template<typename C, typename P>

C filter(C const& container, P const& p){
	C newcontainer{container.size()};
	auto it = std::copy_if(container.begin(), container.end(), newcontainer.begin(), p);
	newcontainer.resize(std::distance(newcontainer.begin(),it));
	return newcontainer;
}		

bool is_even(int n) {
	return n%2 == 0;
}


TEST_CASE("is_even","[is_even]"){

	std::vector<int> v{1,2,3,4,5,6};
	std::vector<int> alleven = filter(v, is_even);

	REQUIRE ( std::all_of(alleven.begin(), alleven.end(),is_even));

}

int main ( int argc , char* argv [])
{
    return Catch::Session().run(argc, argv);
}
