#include "boost/json.hpp"
#include "util.h"
#include <iostream>

using namespace std;
namespace bj = boost::json;

int main() {
	auto raw  = R"(
[
    {
        "image" : {
            "path" : "https://i.natgeofe.com/n/4f5aaece-3300-41a4-b2a8-ed2708a0a27c/domestic-dog_thumb_square.jpg?wp=1&w=170&h=170",
            "size" : 9100
        },
        "comment" : [
            {
                "text" : "this is cool",
                "timestamp" : 123456,
                "likes" : [
                    {
                        "author" : "Coco",
                        "timestamp" : 123
                    },
                    {
                        "author" : "Izzy",
                        "timestamp" : 456
                    }
                ]
            }
        ]
    }
]

)";
	boost::system::error_code ec;
	auto json = bj::parse(raw);
	
	cout << "Initial Json:\n";
	pretty_print(cout,json);
	
	cout << "Removing invalid ptr /1/image \n";
	auto res = json.delete_at_pointer("/1/image",ec);
	cout << ec.message() << " @ " << res.second << "\n------\n";
	
	cout << "Removing invalid ptr /0/image/invalid \n";
	res = json.delete_at_pointer("/0/image/invalid",ec);
	cout << ec.message() << " @ " << res.second << "\n------\n";
	
	
	cout << "Removing /0/comment/0/text \n";
	json.delete_at_pointer("/0/comment/0/text",ec);
	pretty_print(cout,json);
	cout << "\n------\n";
	
	cout << "Removing /0/comment/0/likes/1 \n";
	json.delete_at_pointer("/0/comment/0/likes/1",ec);
	pretty_print(cout,json);
	cout << "\n------\n";
	
	cout << "Removing /0/comment/0 \n";
	json.delete_at_pointer("/0/comment/0",ec);
	pretty_print(cout,json);
	cout << "\n------\n";
	
	cout << "Removing /0/image \n";
	json.delete_at_pointer("/0/image",ec);
	pretty_print(cout,json);
	cout << "\n------\n";
}
