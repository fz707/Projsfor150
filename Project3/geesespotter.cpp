//
//  main.cpp
//  geesespotter
//
//  Created by Fardin Zaman on 10/28/20.
// TO SUBMIT TO MARMOSET

#include <iostream>
#include "geesespotter_lib.h"


char * createBoard(std::size_t xdim, std::size_t ydim){
    
    char * newboard= new char[xdim*ydim]{0};
   
    return  newboard;
    
}
void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){
    size_t max= xdim*ydim;
    for (std::size_t i{0}; i< max; i ++){
        
        if (board[i]==9){
            if( i-xdim<0){ // checks top row
                if ( i==0){ //top left or first value
                    board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1; // SCUFFED STATEMENT FOR ALL
                    board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                    board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]+=1;
                }
               else  if( i%xdim==xdim-1){ //means top right corner
                   // board[i-1]+=1;
                  //  board[i+xdim]+=1;
                  //  board[i+xdim-1]+=1;
                   board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1; // SCUFFED STATEMENT FOR ALL
                   board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                   board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]+=1;
                }
               else{        // top middle
                 //  board[i+1]+=1;
                 //  board[i-1]+=1;
                 //  board[i+xdim]+=1;
                 //  board[i+xdim-1]+=1;
                //   board[i+xdim+1]+=1;
                   board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1;
                   board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1;
                   board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                   board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]+=1;
                   board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]+=1;

               }
            }
            else if( i+xdim>=max){ // checks for bottom row
                if(i%xdim==0){ //looks for  bottom left corner piece
                //    board[i+1]+=1;
                  //  board[i-xdim]+=1;
                 //   board[i-xdim+1]+=1;
                    board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]+=1;
                }
                else if( i==max-1){ //last piece
                 //   board[i-1]+=1;
                 //   board[i-xdim]+=1;
                 //   board[i-xdim-1]+=1;
                    board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]+=1;
                }
                else{
                 //  board[i+1]+=1;
                  //  board[i-1]+=1;
                   // board[i-xdim]+=1;
                 //   board[i-xdim-1]+=1;
                 //   board[i-xdim+1]+=1;
                    board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1;
                    board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]+=1;
                    board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]+=1;
                    
                }
            }
            else{ // now any middle row
                if(i%xdim==0){ //left side piece
                //    board[i+1]+=1;  // right value
                //    board[i-xdim]+=1; //upper value
               //     board[i-xdim+1]+=1; //upper value +1
               //     board[i+xdim]+=1; //lower value
                 //   board[i+xdim+1]+=1; //lower value +1
                    board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]+=1;
                    board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                    board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]+=1;
                }
                else if((i+1)%xdim==0){ //right side piece
                  //  board[i-1]+=1;  // left value
                 //   board[i-xdim]+=1; //upper value
                 //   board[i-xdim-1]+=1; //upper value -1
                 //   board[i+xdim]+=1; //lower value
                //    board[i+xdim-1]+=1; //lower value -1
                    board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]+=1;
                    board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                    board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]+=1;
                }
                else{  //middle piece with up down left right etc.
               //     board[i+1]+=1;
              //      board[i-1]+=1;
               //     board[i-xdim-1]+=1;
              //      board[i-xdim]+=1;
              //      board[i-xdim+1]+=1;
               //     board[i+xdim-1]+=1;
              //      board[i+xdim]+=1;
              //      board[i+xdim+1]+=1;
                    board[i+1]==9 ? board[i+1]+=0 : board[i+1]+=1;
                    board[i-1]==9 ? board[i-1]+=0 : board[i-1]+=1;
                    board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]+=1;
                    board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]+=1;
                    board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]+=1;
                    board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]+=1;
                    board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]+=1;
                    board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]+=1;
                }
            }
        }
    }
}
         
void hideBoard(char * board, std::size_t xdim, std::size_t ydim){
    
    std::size_t max= xdim*ydim;
    for (std::size_t i=0; i<max; i++){
        
        board[i] |= hiddenBit(); //change back soon
    }
    
}
    
    
void cleanBoard(char * board){
    //cleans board
    delete[] board;
    board=nullptr;
}


void printBoard(char * board, std::size_t xdim, std::size_t ydim){
    
    std::size_t max= xdim*ydim;
    for(std::size_t i=0; i<max; i++){
    
        
        if((board[i] & markedBit())== markedBit()){
        std::cout << 'M';
        }
        else if( (board[i] & hiddenBit()) == hiddenBit()){
            std::cout << '*';
        }
        else{
            std::cout <<(int )board[i] ;
        }
         
        if((i+1)%xdim==0){
            std::cout<< std::endl;
        }
    }
}
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    //reveals a value
    int convertedarrR = xloc+(xdim*yloc);
    std::size_t max= xdim*ydim;
    if ( (board[convertedarrR] & markedBit())== markedBit()){
        return 1;
    }
    if ( (board[convertedarrR] & hiddenBit()) != hiddenBit() ){
        return 2;
    }
    
    
    if ( (board[convertedarrR] & valueMask()) ==9){
        board[convertedarrR] &= valueMask();
        return 9;
    }
    else if ( (board[convertedarrR] & valueMask()) !=0){
        board[convertedarrR] &= valueMask();
        return 0;
    }
    else{
        board[convertedarrR] &=valueMask();
        for ( std::size_t i=0; i<max; i++){
            if (i==convertedarrR){
                
                if( i-xdim<0){ // checks top row
                    if ( i==0){ //top left or first value
                        board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask(); // SCUFFED STATEMENT FOR ALL
                        board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                        board[i+xdim+1]!=9 ? board[i+xdim+1]+=0 : board[i+xdim+1]&=valueMask();
                    }
                   else  if( i%xdim==xdim-1){ //means top right corner
                       // board[i-1]+=1;
                      //  board[i+xdim]+=1;
                      //  board[i+xdim-1]+=1;
                       board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask(); // SCUFFED STATEMENT FOR ALL
                       board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                       board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]&=valueMask();
                    }
                   else{        // top middle
                     //  board[i+1]+=1;
                     //  board[i-1]+=1;
                     //  board[i+xdim]+=1;
                     //  board[i+xdim-1]+=1;
                    //   board[i+xdim+1]+=1;
                       board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask();
                       board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask();
                       board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                       board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]&=valueMask();
                       board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]&=valueMask();

                   }
                }
                else if( i+xdim>=max){ // checks for bottom row
                    if(i%xdim==0){ //looks for  bottom left corner piece
                    //    board[i+1]+=1;
                      //  board[i-xdim]+=1;
                     //   board[i-xdim+1]+=1;
                        board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]&=valueMask();
                    }
                    else if( i==max-1){ //last piece
                     //   board[i-1]+=1;
                     //   board[i-xdim]+=1;
                     //   board[i-xdim-1]+=1;
                        board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]&=valueMask();
                    }
                    else{
                     //  board[i+1]+=1;
                      //  board[i-1]+=1;
                       // board[i-xdim]+=1;
                     //   board[i-xdim-1]+=1;
                     //   board[i-xdim+1]+=1;
                        board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask();
                        board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]&=valueMask();
                        board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]&=valueMask();
                        
                    }
                }
                else{ // now any middle row
                    if(i%xdim==0){ //left side piece
                    //    board[i+1]+=1;  // right value
                    //    board[i-xdim]+=1; //upper value
                   //     board[i-xdim+1]+=1; //upper value +1
                   //     board[i+xdim]+=1; //lower value
                     //   board[i+xdim+1]+=1; //lower value +1
                        board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]&=valueMask();
                        board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                        board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]&=valueMask();
                    }
                    else if((i+1)%xdim==0){ //right side piece
                      //  board[i-1]+=1;  // left value
                     //   board[i-xdim]+=1; //upper value
                     //   board[i-xdim-1]+=1; //upper value -1
                     //   board[i+xdim]+=1; //lower value
                    //    board[i+xdim-1]+=1; //lower value -1
                        board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]&=valueMask();
                        board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                        board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]&=valueMask();
                    }
                    else{  //middle piece with up down left right etc.
                   //     board[i+1]+=1;
                  //      board[i-1]+=1;
                   //     board[i-xdim-1]+=1;
                  //      board[i-xdim]+=1;
                  //      board[i-xdim+1]+=1;
                   //     board[i+xdim-1]+=1;
                  //      board[i+xdim]+=1;
                  //      board[i+xdim+1]+=1;
                        board[i+1]==9 ? board[i+1]+=0 : board[i+1]&=valueMask();
                        board[i-1]==9 ? board[i-1]+=0 : board[i-1]&=valueMask();
                        board[i-xdim]==9 ? board[i-xdim]+=0 : board[i-xdim]&=valueMask();
                        board[i-xdim-1]==9 ? board[i-xdim-1]+=0 : board[i-xdim-1]&=valueMask();
                        board[i-xdim+1]==9 ? board[i-xdim+1]+=0 : board[i-xdim+1]&=valueMask();
                        board[i+xdim]==9 ? board[i+xdim]+=0 : board[i+xdim]&=valueMask();
                        board[i+xdim-1]==9 ? board[i+xdim-1]+=0 : board[i+xdim-1]&=valueMask();
                        board[i+xdim+1]==9 ? board[i+xdim+1]+=0 : board[i+xdim+1]&=valueMask();
                    }
                }
            }
        }
        return 0;
    }
    

}

int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
   int convertedarr = xloc+(xdim*yloc); //converts x loc and y loc to board space value
    if( (board[convertedarr] & markedBit()) != markedBit()   && ( (board[convertedarr] & hiddenBit()) ==hiddenBit())){ //checks with 1 0000 to see if unmarked + not revealed
       board[convertedarr] |= markedBit();  //marks it
        return 0;
       }
    else if((board[convertedarr] & markedBit())== markedBit()  && ( (board[convertedarr] & hiddenBit()) ==hiddenBit())){ //checks to see if marked + not revealed
        board[convertedarr] ^= markedBit(); //unmarkss it
        return 0;
    }
    else{ //revealed so it returns 2;
        return 2;
    }
}


bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){
    int counter=0;
    std::size_t max= xdim*ydim;
    for (std::size_t i{0}; i<max; i++ ){
        
        if ((board[i] & hiddenBit())==hiddenBit()){
            if((board[i] & valueMask())!=9 ){
                counter++;
            }
        }
    }
    if (counter==0){
        return true;
    }
    if (counter!=0){
        return false;
    }
    return false;
}
