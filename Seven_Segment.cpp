#include <iostream>
#include <vector>
using namespace std;
#define RED "\033[1;31m" // ini adalah warna
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m" // warna putih
vector<int> Decimal_to_SevenSegment(int N){
    vector<int> segment;
    switch(N){ // menginisiasikan segment dengan formula pencetakan sesuai nilai dari N
        case 0:
            segment = {1,1,1,0,1,1,1};
            break;
        case 1:
            segment = {0,0,1,0,0,1,0};
            break;
        case 2:
            segment = {1,0,1,1,1,0,1};
            break;
        case 3:
            segment = {1,0,1,1,0,1,1};
            break;
        case 4:
            segment = {0,1,1,1,0,1,0};
            break;
        case 5:
            segment = {1,1,0,1,0,1,1};
            break;
        case 6:
            segment = {1,1,0,1,1,1,1};
            break;
        case 7:
            segment = {1,0,1,0,0,1,0};
            break;
        case 8:
            segment = {1,1,1,1,1,1,1};
            break;
        case 9:
            segment = {1,1,1,1,0,1,1};
            break;
    }
    return segment;
}
void Draw_Table(vector<int> segment, int N){
    string binary;
    while(N >= 1){ // konversi desimal ke dalam binary
        if(N % 2 == 1){
            binary.insert(0, "1");
            N/=2;
        }else{
            binary.insert(0, "0");
            N/=2;
        }
    }
    while(binary.length() < 4){
        binary.insert(0, "0");
    }
    cout<<"=========================================\n";
    cout<<"|| " << BLUE << "Binary" << " || a | b | c | d | e | f | g " << RESET <<"||\n";
    cout<<"-----------------------------------------\n";
    cout<< "||  "<< YELLOW << binary << "  || "<< segment[0] <<" | "<< segment[1] <<" | "<< segment[2] <<" | "<< segment[3] <<" | "<< segment[4] <<" | "<< segment[5] <<" | "<< segment[6]  << RESET <<" ||\n";
    cout<<"=========================================\n";
}
void Print_SevenSegment(vector<int> segment){
    string horizontal = "=====\n";
    string vertical = "|| ";
    for(int i = 0; i < segment.size(); i++){ // iterasi setiap elemen dari segment
        if(i % 3 == 0 || i == 0){ // kondisi horizontal, index 0,3,dan 6
            if(segment[i] == 1){
                cout<< RED << horizontal << RESET;
            }else{ // segment[i] == 0
                cout<< "\n";
            }
        }else{ // kondisi vertical, index 1,2,4,dan 5
            if(segment[i] == 1){
                cout<< RED << vertical << RESET;
            }else{
                cout<< "   ";
            }
            if(i == 2 || i == 5){ // khusus index 2 dan 5 (vertikal), kita akan mencetak new line untuk pindah kebaris berikutnya
                cout<< "\n";
            }
        }
    }
}
int main(){
    cout<< "\n=========== Decimal to Seven_Segment ===========\n";
    cout<< GREEN <<"Name    : King Ahmad Ilyas \nNIM     : D121231095 \nInformatika B\n\n" << RESET;
    bool Exit = false;
    while (Exit == false){
        int N;
        cout<< "Enter number to display (0-9), input else to exit : ";
        cin>> N;
        if(N < 10 && N >= 0){
            vector<int> segment = Decimal_to_SevenSegment(N);
            cout<< "\n" << N <<" to Seven_Segment Representation in Table : \n";
            Draw_Table(segment, N);
            cout<< "Seven Segment Display of " << N << " : \n";
            Print_SevenSegment(segment);
            cout<< "\n";
        }else{
            cout<< GREEN <<"\nProgram End\n\n" << RESET;  
            Exit = true; // jika user memasukkan angka selain 0 - 9, maka program berakhir
        }
    }
    return 0;
}