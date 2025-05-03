// calculating the area of a square, cube, rectangle or cuboid using classes
#include <iostream>
#include <cstdlib>

class shapes{

    private:
    int length;
    int breadth;
    int width;

    public:
    void square(int);
    void cube(int);
    void rectangle(int,int);
    void cuboid(int,int,int);
};

int main(){

    shapes s;
    int end=0;
    int choice;
    int boundary=0;

    int length1;
    int breadth1;
    int width1;

    while(end!=1){
        printf("The Menu\n1. Square\n2. Cube\n3. Rectangle\n4. Cuboid\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if (choice==1){
            while (boundary==0){
                printf("Enter side: ");
                scanf("%d",&length1);
                if (length1>0){
                    boundary=1;
                }else{
                    printf("Invalid Number! Enter again\n");
                }
            }boundary=0;

            s.square(length1);
        }

        if (choice==2){
            while (boundary==0){
                printf("Enter side: ");
                scanf("%d",&length1);
                if (length1>0){
                    boundary=1;
                }else{
                    printf("Invalid Number! Enter again\n");
                }
            }boundary=0;

            s.cube(length1);
        }
            

        if (choice==3){
            while (boundary==0){
                printf("Enter length: ");
                scanf("%d",&length1);
                printf("Enter breadth: ");
                scanf("%d",&breadth1);
                if(length1>0 && breadth1>0){
                    boundary=1;
                }else{
                    printf("Enter again!\n");
                }
            }boundary=0;

            s.rectangle(length1,breadth1);
        }

        if (choice==4){
            while (boundary==0){
                printf("Enter length: ");
                scanf("%d",&length1);
                printf("Enter breadth: ");
                scanf("%d",&breadth1);
                printf("Enter width: ");
                scanf("%d",&width1);
                if(length1>0 && breadth1>0 && width1>0){
                    boundary=1;
                }else{
                    printf("Enter again!\n");
                }       
            }boundary=0;
            
            s.cuboid(length1,breadth1,width1);
        }

        if (choice==5){
            printf("You have exited the program!\n");
            end=1;
        }
    }
    return 0;
}

// calculates the area of a square
void shapes::square(int x){
    length=x;
    printf("The area of the square is %d\n",length*length);
}

// calculates the area of a cube
void shapes::cube(int x){
    length=x;
    printf("The area of the cube is %d\n",6*length*length);
}

// calculates the area of a rectangle
void shapes::rectangle(int x,int y){
    length=x;
    breadth=y;
    printf("The area of the rectangle is %d\n",length*breadth);
}

// calculates the area of a cuboid
void shapes::cuboid(int x, int y, int z){
    length=x;
    breadth=y;
    width=z;
    int area = 2*((length*breadth)+(breadth*width)+(length*width));
    printf("The area of the cuboid is %d\n",area);
}