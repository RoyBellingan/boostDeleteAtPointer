git clone --recursive git@github.com:RoyBellingan/boostDeleteAtPointer.git
cd boostDeleteAtPointer/
cmake .
make -j 8
./boostDeleteAtPointer

it should produce 
```JSON
Initial Json:
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
Removing invalid ptr /1/image 
past-the-end token not supported @ /1
------
Removing invalid ptr /0/image/invalid 
no referenced value @ /0/image/invalid
------
Removing /0/comment/0/text 
[
    {
        "image" : {
            "path" : "https://i.natgeofe.com/n/4f5aaece-3300-41a4-b2a8-ed2708a0a27c/domestic-dog_thumb_square.jpg?wp=1&w=170&h=170",
            "size" : 9100
        },
        "comment" : [
            {
                "likes" : [
                    {
                        "author" : "Coco",
                        "timestamp" : 123
                    },
                    {
                        "author" : "Izzy",
                        "timestamp" : 456
                    }
                ],
                "timestamp" : 123456
            }
        ]
    }
]

------
Removing /0/comment/0/likes/1 
[
    {
        "image" : {
            "path" : "https://i.natgeofe.com/n/4f5aaece-3300-41a4-b2a8-ed2708a0a27c/domestic-dog_thumb_square.jpg?wp=1&w=170&h=170",
            "size" : 9100
        },
        "comment" : [
            {
                "likes" : [
                    {
                        "author" : "Coco",
                        "timestamp" : 123
                    }
                ],
                "timestamp" : 123456
            }
        ]
    }
]

------
Removing /0/comment/0 
[
    {
        "image" : {
            "path" : "https://i.natgeofe.com/n/4f5aaece-3300-41a4-b2a8-ed2708a0a27c/domestic-dog_thumb_square.jpg?wp=1&w=170&h=170",
            "size" : 9100
        },
        "comment" : [

        ]
    }
]

------
Removing /0/image 
[
    {
        "comment" : [

        ]
    }
]

------

```

