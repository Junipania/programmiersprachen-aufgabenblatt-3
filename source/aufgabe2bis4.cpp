#include <cstdlib>
#include <vector>
#include <list>
#include <set>
#include <map>
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

    std::set<unsigned int> s1{};
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

    std::set<unsigned int> s2{};
    unsigned int it = 0;
    for (it = 0; it <= 99; ++it){
        unsigned int co = 0;
        for(auto& s : s1){
            if(it != s){
                co += 1;
            }        
        }
        if (co == s1.size()){
            s2.insert(it);
        }
    }
    std::cout<<"\n";
    std::cout<<"Anzahl unterschiedliche Zahlen:"<<s2.size()<<"\n";

    std::map<float,float> m0;
    float count = 0.0;
    for (auto const &s : s2){
        for (auto& l : l0){
            if (l == s){
                count += 1.0;
            }
        }
        m0[s] = (count / l0.size());
        std::cout<<s<<":"<<m0.find(s)->second<<"\n";
    }
    return 0;
}


