#include<iostream>
#include<iomanip>

using namespace std;

const int Row = 5;
const int Col = 10;

void display(bool seats[Row][Col]){

    system("cls");

    cout<<" ";
    for(int i = 1; i <= Col; i++){

        cout<<setw(3)<<i;
    }
    cout<<endl;

    for(int i = 0; i < Row; i++){

        cout<<static_cast<char>('A' + i)<<" ";


            for(int j = 0; j < Col; j++){

                if(seats[i][j]){

                    cout<<setw(3)<<"X";
                }
                else{

                    cout<<setw(3)<<"-";
                }
            }
            cout<<endl;
        }
    }
    


void reservation(bool seats[Row][Col], int col, char row){
    
    system("cls");

    if(seats[row-'A'][col - 1]){

        cout<<"Seat is already booked!"<<endl;
    }
    else{
        
        seats[row - 'A'][col - 1] = true;
        cout<<"Your seat is booked successfully!"<<endl;
    }
}

int main(){

    bool seats[Row][Col] = {false};
    int col;
    char row;

    display(seats);

    while(true){

        cout<<"Enter Row (A-E): ";
        cin >> row;
        cout<<"Enter Column (1-10): ";
        cin >> col;

        if(row < 'A' || row > 'E' && col < 1 || col > 10){

            cout<<"Enter valid row and column!"<<endl;
            continue;
        }
        reservation(seats, row, col);
        display(seats);

        char choice;
        cout<<"Do you want to book more seats : (Y/N) ";
        cin >> choice;

        if(choice != 'Y' && choice != 'y'){

            break;
        }
        
    }
}