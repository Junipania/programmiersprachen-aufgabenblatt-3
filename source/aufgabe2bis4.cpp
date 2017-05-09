#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{

    std::list<unsigned int> l0(100);

    for (auto& l : l0){ 
		l = std::rand()%100;
	}
    std::cout<<l0.front();
    std::cout<<"\n";
    std::cout<<l0.back();
    std::cout<<"\n";
    std::cout<<"\n";

    std::vector<int> v0(l0.size());
    std::copy(std::begin(l0), std::end(l0), std::begin(v0));
    std::cout<<*v0.begin();
    std::cout<<"\n";
    std::cout<<*(v0.end()-1);
    std::cout<<"\n";
    std::cout<<"\n";



    std::set<int> s1{};
    unsigned int i = 0;
    unsigned int c = 0;
    while(i<=100){
        for (auto& l : l0){
            if(i != l){
                c += 1;
            }
        }
        if( c == l0.size()){
            s1.insert(i);
        }
        i += 1;
        c = 0;
    }
    std::cout<<"\n";
    std::copy(std::begin(s1), std::end(s1), std::ostream_iterator<int>(std::cout, "\n"));


    return 0;
}


