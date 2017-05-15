#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"




TEST_CASE("operator","[operator]"){

    std::vector<Circle> circles(10);

    for (auto& v : circles){
        v = Circle{float(std::rand()%10),{0.0, 0.0, 0.0}, {float(std::rand()%1000), float(std::rand()%1000)}};
    
    }
    
    for (int n = 10; n > 1; n--){
        for (int i= 0; i< n-1; i++){

            if (circles[i] > circles[i+1]){
                std::swap(circles[i], circles[i+1]);
            }
        }    
    }

    REQUIRE (std::is_sorted(circles.begin(), circles.end()));

}

TEST_CASE("sort","[sort]"){

    std::vector<Circle> sortieren(10);

    for (auto& s : sortieren){
        s = Circle{float(std::rand()%10),{0.0, 0.0, 0.0}, {float(std::rand()%1000), float(std::rand()%1000)}};
    }

    std::sort(sortieren.begin(), sortieren.end(), [] (Circle a, Circle b){
        return a > b;
    });
}

TEST_CASE("add","[add]"){

    std::vector<int> v1{1,2,3,4,5,6,7,8,9};
    std::vector<int> v2{9,8,7,6,5,4,3,2,1};
    std::vector<int> v3(9);

    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),[](int a,int b){
        return a + b;
    });

    REQUIRE(std::all_of(v3.begin(), v3.end(), [](int a){
        return a == 10;
    }));

}

int main(int argc, char* argv[]){

    return Catch::Session().run(argc, argv);

}
