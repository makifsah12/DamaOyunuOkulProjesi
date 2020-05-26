#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
using namespace std;
/*---------------------------------------------------------İstanbul Üniversitesi------------------------------------------------------------------------------*/
/*--------------------------------------------------------Bilgisayar Mühendisliği-----------------------------------------------------------------------------*/
/*----------------------------------------------------------2.Sınıf Bahar Dönemi--------------------------------------------------------------------------------*/
/*--------------------------------------------------------File Organisation Ödevi------------------------------------------------------------------------------*/
/*------------------------------------------------------------Mehmet Akif Şahin--------------------------------------------------------------------------------*/
/*---------------------------------------------------------------1306170028---------------------------------------------------------------------------------------*/
void printTable(char row[9][9]){// I am using this function because when you press the start game , you should see the board
    for(int i = 8; i >= 0; i--){
        for(int j = 0; j < 9; j++){
            cout << row[i][j];
        }cout << endl;
    }
}
int findPlaceOfLetter(char a,char array[9][9]){//this is for convert letter to integer , i mean when you write a3 , i should find the place of a for moving properly
    for(int i = 0; i < 9; i++){
        if(a == array[0][i]){
            return i;
        }
    }
}
int shouldWeEat(char row[9][9], int x1,int x2){//As i mentioned in function name , this is for checking that should we eat for non stamp pieces
    if(row[0][0] == '+'){
        if(row[x2][x1] == 'w' ){
            if(      (row[x2+1][x1] == 'B'||row[x2+1][x1] == 'b') && (row[x2+2][x1] == '_')){
                return 1;
            }else if((row[x2][x1-1] == 'B'||row[x2][x1-1] == 'b') && (row[x2][x1-2] == '_')){
                return 1;
            }else if((row[x2][x1+1] == 'B'||row[x2][x1+1] == 'b') && (row[x2][x1+2] == '_')){
                return 1;
            }
        }
    }
    if(row[0][0] == '-'){
        if(row[x2][x1] == 'b' ){
            if(      (row[x2][x1+1] == 'W'||row[x2][x1+1] == 'w') && (row[x2][x1+2] == '_')){
                return 1;
            }else if((row[x2-1][x1] == 'W'||row[x2-1][x1] == 'w') && (row[x2-2][x1] == '_')){
                return 1;
            }else if((row[x2][x1-1] == 'W'||row[x2][x1-1] == 'w') && (row[x2][x1-2] == '_')){
                return 1;
            }
        }
    }
    return 0;
}
int shouldWeEatAny(char row[9][9]){//This function is checking that should we eat , for every piece
    for(int i = 0;  i < 9 ; i++){
        for(int j = 0 ; j < 9; j++){
            if((shouldWeEat(row,i,j) == 1)) {
                return 1;
            }
        }
    }
    return 0;
}
int shouldWeContinueToEatForW(char row[9][9]){//when you eat any piece , we should check the continuity . so this is for it.
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            if(row[0][0] == '+'){
                if(row[j][i] == 'w' ){
                    if(      (row[j+1][i] == 'B'||row[j+1][i] == 'b') && (row[j+2][i] == '_')){
                        return 1;
                    }else if((row[j][i-1] == 'B'||row[j][i-1] == 'b') && (row[j][i-2] == '_')){
                        return 1;
                    }else if((row[j][i+1] == 'B'||row[j][i+1] == 'b') && (row[j][i+2] == '_')){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int shouldWeContinueToEatForB(char row[9][9]){//Same Purpose With Above Function But This Is For Piece B
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9; j++){
            if(row[0][0] == '-'){
                if(row[j][i] == 'b' ){
                    if(      (row[j][i+1] == 'W'||(row[j][i+1] == 'w')) && (row[j][i+2] == '_')){
                        return 1;
                    }else if((row[j-1][i] == 'W'||(row[j-1][i] == 'w')) && (row[j-2][i] == '_')){
                        return 1;
                    }else if((row[j][i-1] == 'W'||(row[j][i-1] == 'w')) && (row[j][i-2] == '_')){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
bool shouldWeEatForStamp(char row[9][9], int x1,int x2){//Same purpose with should we eat , but this is for stamp pieces
    if(row[0][0] == '+') {
        if (row[x2][x1] == 'W') {
            int i = 1;
            while (row[x2][x1 + i] == '_') {
                i++;
            }
            if ((row[x2][x1 + i] == 'b' || row[x2][x1 + i] == 'B') && row[x2][x1 + i + 1] == '_') {
                return 1;
            }
            int j = 1;
            while (row[x2][x1 - j] == '_') {
                j++;
            }
            if ((row[x2][x1 - j] == 'b' || row[x2][x1 - j] == 'B') && row[x2][x1 - j - 1] == '_') {
                return 1;
            }
            int k = 1;
            while (row[x2 + k][x1] == '_') {
                k++;
            }
            if ((row[x2 + k][x1] == 'b' || row[x2 + k][x1] == 'B') && row[x2 + k + 1][x1] == '_') {
                return 1;
            }
            int m = 1;
            while (row[x2 - m][x1] == '_') {
                m++;
            }
            if ((row[x2 - m][x1] == 'b' || row[x2 - m][x1] == 'B') && row[x2 - m - 1][x1] == '_') {
                return 1;
            }
        }
    }
    if(row[0][0] == '-') {
        if (row[x2][x1] == 'B') {
            int i = 1;
            while (row[x2][x1 + i] == '_') {
                i++;
            }
            if ((row[x2][x1 + i] == 'w' || row[x2][x1 + i] == 'W') && row[x2][x1 + i + 1] == '_') {
                return 1;
            }
            int j = 1;
            while (row[x2][x1 - j] == '_') {
                j++;
            }
            if ((row[x2][x1 - j] == 'w' || row[x2][x1 - j] == 'W') && row[x2][x1 - j - 1] == '_') {
                return 1;
            }
            int k = 1;
            while (row[x2 + k][x1] == '_') {
                k++;
            }
            if ((row[x2 + k][x1] == 'w' || row[x2 + k][x1] == 'W') && row[x2 + k + 1][x1] == '_') {
                return 1;
            }
            int m = 1;
            while (row[x2 - m][x1] == '_') {
                m++;
            }
            if ((row[x2 - m][x1] == 'w' || row[x2 - m][x1] == 'W') && row[x2 - m - 1][x1] == '_') {
                return 1;
            }
        }
    }
    return 0;
}
bool shouldWeEatAnyForStamp(char row[9][9]){// Same purpose with shouldWeEatAny , but this is for stamp pieces
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 1; j < 9; j++){
            if(shouldWeEatForStamp(row,i,j)){
                return 1;
            }
        }
    }
    return 0;
}
bool pieceControl(int x1,int x2,int y1,int y2,char row[9][9]) {//this function is controlling piece for blocking wrong moves
    int eat = 0;
    eat = shouldWeEatAny(row);
    if (row[y2][y1] == '_') {
        if(eat == 0 ){
            if         (((y1 - 1) == x1) && (y2 == x2)  ) {
                return true;
            } else if (  (y1     == x1)     && ((y2 - 1) == x2) && (row[x2][x1] == 'w') ) {
                return true;
            } else if (  (y1 + 1 == x1) &&  (y2 == x2) ) {
                return true;
            } else if (  (y1     == x1)    && (y2+1) == x2 && (row[x2][x1] == 'b') ) {
                return true;
            }
            else {
                return false;
            }
        }
        //this else block is for the blocking players moving if we can eat any piece or stamp
        else if(eat == 1){
            if ( (row[x2][(x1)] == 'b') && (row[(x2)][x1+1]=='w'||row[(x2)][x1+1]=='W') && (   (y1-2) == x1    ) && (  (   y2   ) == x2)  ) { // move piece to right for jumping from rival
                    return true;
            }else if (  (row[x2][(x1)] == 'b') && (row[(x2)][x1-1]=='w'||row[(x2)][x1-1]=='W') && (   (y1+2) == x1    ) && (  (   y2   ) == x2) ) { // move piece to left for jumping from rival
                    return true;
            }else if (  (row[x2][(x1)] == 'w') && (row[(x2)][x1+1]=='b'||row[(x2)][x1+1]=='B') && (   (y1-2) == x1    ) && (  (   y2   ) == x2)) { // move piece to right for jumping from rival
                    return true;
            }else if (  (row[x2][(x1)] == 'w') && (row[(x2)][x1-1]=='b'||row[(x2)][x1-1]=='B') &&   (   (y1+2) == x1    ) && (  (   y2   ) == x2) ) { // move piece to left for jumping from rival
                    return true;
            }else if (  (row[x2][(x1)] == 'w') && (row[(x2+1)][x1]=='b'||row[(x2+1)][x1]=='B') && (   (y1) == x1    ) && (  (   y2-2   ) == x2) ) { // move piece to front for jumping from rival
                    return true;
            }else if (  (row[x2][(x1)] == 'b') && (row[(x2-1)][x1]=='w'||row[(x2-1)][x1]=='W') && (    y1 == x1    ) && (  (   y2+2  )   == x2)) { // move piece to front for jumping from rival
                    return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}
void movePiece(int x1, int x2, int y1, int y2, char row[9][9]) {//this function is for moving piece , by the way , my algorithm is that if moving is correct then we can move the piece or stamp, every moving algorithm works same way
    FILE *file2;
    file2 = fopen("dama.txt", "r+");
//---------------------------------------------------------------------------------------------------------------------------------------------------
    //--changing array elements
    if(row[x2][x1] == 'w' && (y2 == 8)){
        row[x2][x1] = 'W';
    }
    if(row[x2][x1] == 'b' && (y2 == 1)){
        row[x2][x1] = 'B';
    }
    row[y2][y1] = row[x2][x1];
    if( (y1+2 == x1) && (y2 == x2)   ){ //this is for to take piece of rival by moving left
        row[x2][x1-1]  = '_';
    }
    if( (y1-2 == x1) && (y2 == x2)   ){ //this is for to take piece of rival by moving right
        row[x2][x1+1]  = '_';
    }
    if( (y1 == x1) && (y2-2 == x2)   ){ //this is for to take a piece of rival by going forward
        row[x2+1][x1] = '_';
        //we are using fseek one more time , because if we take rival's piece by moving forward, 3 column will be changed , so we should use one more time
        fseek(file2, (8-(x2+1)) * 11, SEEK_SET);
        fprintf(file2, "%c%c%c%c%c%c%c%c%c",row[(x2+1)][0],row[(x2+1)][1], row[(x2+1)][2], row[(x2+1)][3], row[(x2+1)][4], row[(x2+1)][5], row[(x2+1)][6],
                row[(x2+1)][7], row[(x2+1)][8]);
    }
    if( (y1 == x1) && (y2+2 == x2)   ){ //this is for to take a piece of rival by going back
        row[x2-1][x1] = '_';
        //we are using fseek one more time , because if we take rival's piece by moving forward, 3 column will be changed , so we should use one more time
        fseek(file2, (8-(x2-1)) * 11, SEEK_SET);
        fprintf(file2, "%c%c%c%c%c%c%c%c%c",row[(x2-1)][0],row[(x2-1)][1], row[(x2-1)][2], row[(x2-1)][3], row[(x2-1)][4], row[(x2-1)][5], row[(x2-1)][6],
                row[(x2-1)][7], row[(x2-1)][8]);
    }
    row[x2][x1] = '_';
    //--changing array elements
//---------------------------------------------------------------------------------------------------------------------------------------------------
    //--changing first piece
    fseek(file2, (8-x2) * 11, SEEK_SET);
    fprintf(file2, "%d%c%c%c%c%c%c%c%c",x2,row[x2][1], row[x2][2], row[x2][3], row[x2][4], row[x2][5], row[x2][6],
            row[x2][7], row[x2][8]);
    //--changing first piece
//---------------------------------------------------------------------------------------------------------------------------------------------
    //--changing second piece
    fseek(file2, (8-y2) * 11 , SEEK_SET);
    fprintf(file2, "%d%c%c%c%c%c%c%c%c",y2 ,row[y2][1],row[y2][2], row[y2][3], row[y2][4], row[y2][5], row[y2][6],
            row[y2][7], row[y2][8]);
    //--changing second piece
//---------------------------------------------------------------------------------------------------------------------------------------------
    //changing player turn
    fseek(file2, 88 , SEEK_SET);
    fprintf(file2, "%c" , row[0][0]);
    //changing player turn
//---------------------------------------------------------------------------------------------------------------------------------------------
    fclose(file2);
}
bool stampControl(int x1, int x2 , int y1 , int y2, char row[9][9]){//this is for checking correct moves for stamp
    if(row[y2][y1] == '_'){
        if( (y1 == x1) && (y2 > x2) ){  // down to up
            int i = 1; // pawn of riwal
            int rival = 0;
            int space = 0;
            int x = y2-x2;
            int count = 0;
            if(row[x2][x1] == 'W'){
                while(x != count)  {
                    if ( (row[x2 + i][x1] == 'b' || row[x2 + i][x1] == 'B')) {
                        rival++;
                    }
                    else if((row[x2 + i][x1]) == '_'){
                        space++;
                    }
                    if((row[x2+i][x1] == 'W' || row[x2+i][x1] == 'w')){
                        return 0;
                    }
                    count++;
                    i++;
                }
                if((rival == 1 || rival == 0) && (space > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }if(row[x2][x1] == 'B'){
                while(x != count)  {
                    if ( row[x2 + i][x1] == 'W' || row[x2 + i][x1] == 'w' ) {
                        rival++;
                    }
                    else if((row[x2 + i][x1]) == '_'){
                        space++;
                    }
                    if((row[x2+i][x1] == 'B' || row[x2+i][x1] == 'b')){
                        return 0;
                    }
                    count++;
                    i++;
                }
                if((rival == 1 || rival == 0) && (space > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        if( y1 == x1 && (y2 < x2) ){ //up to down
            int j = 1;
            int rival2 = 0;
            int space2 = 0;
            int k = x2-y2;
            int count2 = 0;
            if(row[x2][x1] == 'W'){
                while(k!= count2) {
                    if ((row[x2 - j][x1]) == 'b' || (row[x2 - j][x1]) == 'B' ) {
                        rival2++;
                    }
                    if ((row[x2 - j][x1]) == '_'){
                        space2++;
                    }
                    if((row[x2-j][x1] == 'W' || row[x2-j][x1] == 'w')){
                        return 0;
                    }
                    count2++;
                    j++;
                }

                if((rival2 == 1 || rival2 == 0) && (space2 > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(row[x2][x1] == 'B'){
                while(k!= count2) {
                    if ((row[x2 - j][x1]) == 'w' || (row[x2 - j][x1]) == 'W') {
                        rival2++;
                    }
                    if ((row[x2 - j][x1]) == '_'){
                        space2++;
                    }
                    if((row[x2-j][x1] == 'B' || row[x2-j][x1] == 'b')){
                        return 0;
                    }
                    count2++;
                    j++;
                }
                if((rival2 == 1 || rival2 == 0) && (space2 > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        if((y1 > x1) && (y2 == x2)){
            int i = 1; // pawn of riwal
            int rival = 0;
            int space = 0;
            int x = y1-x1;
            int count = 0;
            if(row[x2][x1] == 'W'){
                while(x != count)  {
                    if ( row[x2][x1+i] == 'b' || row[x2][x1 + i] == 'B' ) {
                        rival++;
                    }
                    else if((row[x2][x1 + i]) == '_'){
                        space++;
                    }
                    if( row[x2][x1+i] == 'w' || row[x2][x1 + i] == 'W' ){
                        return 0;
                    }
                    count++;
                    i++;
                }
                if((rival == 1 || rival == 0) && (space > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(row[x2][x1] == 'B'){
                while(x != count)  {
                    if ( row[x2][x1+i] == 'w' || row[x2][x1 + i] == 'W' ) {
                        rival++;
                    }
                    else if((row[x2][x1 + i]) == '_'){
                        space++;
                    }
                    if(row[x2][x1+i] == 'B' || row[x2][x1 + i] == 'b'){
                        return 0;
                    }
                    count++;
                    i++;
                }
                if((rival == 1 || rival == 0) && (space > 0)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

        if((y1 < x1) && (y2 == x2)){
            int j = 1;
            int rival2 = 0;
            int space2 = 0;
            int k = x1-y1;
            int count2 = 0;
            if(row[x2][x1]=='W') {
                while (k != count2) {
                    if ((row[x2][x1 - j]) == 'b' || (row[x2][x1 - j]) == 'B') {
                        rival2++;
                    }
                    if ((row[x2][x1 - j]) == '_') {
                        space2++;
                    }
                    if((row[x2][x1 - j]) == 'w' || (row[x2][x1 - j]) == 'W'){
                        return 0;
                    }
                    count2++;
                    j++;
                }
                if ((rival2 == 1 || rival2 == 0) && (space2 > 0)) {
                    return 1;
                } else {
                    return 0;
                }
            }if(row[x2][x1] == 'B'){
                while (k != count2) {
                    if ((row[x2][x1 - j]) == 'W' || (row[x2][x1 - j]) == 'w') {
                        rival2++;
                    }
                    if ((row[x2][x1 - j]) == '_') {
                        space2++;
                    }
                    if((row[x2][x1 - j]) == 'B' || (row[x2][x1 - j]) == 'b'){
                        return 0;
                    }
                    count2++;
                    j++;
                }
                if ((rival2 == 1 || rival2 == 0) && (space2 > 0)) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }else{
        return 0;
    }
}
bool stampControl2(int x1, int x2 , int y1 , int y2, char row[9][9]){//almost same with stamp control .but the only difference is when we should eat by stamp , Player should not move by any different piece
    if(row[y2][y1] == '_'){
        if( (y1 == x1) && (y2 > x2) ){  // down to up
            int i = 1; // pawn of riwal
            int rival = 0;
            int space = 0;
            int x = y2-x2;
            int count = 0;
            if(row[x2][x1] == 'W'){
                while(x != count)  {
                    if ( (row[x2 + i][x1] == 'b' || row[x2 + i][x1] == 'B')) {
                        rival++;
                    }
                    count++;
                    i++;
                }
                if((rival == 1 )){
                    return 1;
                }
                else{
                    return 0;
                }
            }if(row[x2][x1] == 'B'){
                while(x != count)  {
                    if ( row[x2 + i][x1] == 'W' || row[x2 + i][x1] == 'w' ) {
                        rival++;
                    }
                    count++;
                    i++;
                }
                if((rival == 1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        if( (y1 == x1) && (y2 < x2) ){ //up to down
            int j = 1;
            int rival2 = 0;
            int space2 = 0;
            int k = x2-y2;
            int count2 = 0;
            if(row[x2][x1] == 'W'){
                while(k!= count2) {
                    if ((row[x2 - j][x1]) == 'b' || (row[x2 - j][x1]) == 'B' ) {
                        rival2++;
                    }
                    count2++;
                    j++;
                }
                if((rival2 == 1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(row[x2][x1] == 'B'){
                while(k!= count2) {
                    if ((row[x2 - j][x1]) == 'w' || (row[x2 - j][x1]) == 'W') {
                        rival2++;
                    }
                    count2++;
                    j++;
                }
                if((rival2 == 1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        if((y1 > x1) && (y2 == x2)){
            int i = 1; // pawn of riwal
            int rival = 0;
            int space = 0;
            int x = y1-x1;
            int count = 0;
            if(row[x2][x1] == 'W'){
                while(x != count)  {
                    if ( row[x2][x1+i] == 'b' || row[x2][x1 + i] == 'B' ) {
                        rival++;
                    }
                    count++;
                    i++;
                }
                if((rival == 1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            if(row[x2][x1] == 'B'){
                while(x != count)  {
                    if ( row[x2][x1+i] == 'w' || row[x2][x1 + i] == 'W' ) {
                        rival++;
                    }
                    count++;
                    i++;
                }
                if((rival == 1)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

        if((y1 < x1) && (y2 == x2)){
            int j = 1;
            int rival2 = 0;
            int space2 = 0;
            int k = x1-y1;
            int count2 = 0;
            if(row[x2][x1]=='W') {
                while (k != count2) {
                    if ((row[x2][x1 - j]) == 'b' || (row[x2][x1 - j]) == 'B') {
                        rival2++;
                    }
                    count2++;
                    j++;
                }
                if ((rival2 == 1)) {
                    return 1;
                } else {
                    return 0;
                }
            }if(row[x2][x1] == 'B'){
                while (k != count2) {
                    if ((row[x2][x1 - j]) == 'W' || (row[x2][x1 - j]) == 'w') {
                        rival2++;
                    }
                    count2++;
                    j++;
                }
                if ((rival2 == 1)) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }else{
        return 0;
    }
}
void moveStamp(int x1, int x2 , int y1, int y2,char row[9][9]){ //this code block only for stamp moving , same purpose with movePiece
    FILE *file2;
    file2 = fopen("dama.txt", "r+");

    if( (y1 == x1) && (y2 > x2) ){ //this is for to take a piece of rival by going forward
        int i = 1;
        int x = y2-x2;
        int count = 0;
        while(x != count)  {
            if ((row[x2 + i][x1]) != 'b' && (row[x2 + i][x1]) != 'B' && (row[x2 + i][x1]) != 'w' && (row[x2 + i][x1]) != 'W' ) {
                i++;
            }
            if ((row[x2 + i][x1]) == 'b' || (row[x2 + i][x1]) == 'B' || (row[x2 + i][x1]) == 'w' || (row[x2 + i][x1]) == 'W' ) {
                break;
            }
            count++;
        }
        row[x2+i][x1] = '_';
        //we are using fseek one more time , because if we take rival's piece by moving forward, 3 column will be changed , so we should use one more time
        fseek(file2, (8-(x2+i)) * 11, SEEK_SET);
        fprintf(file2, "%c%c%c%c%c%c%c%c%c",row[(x2+i)][0],row[(x2+i)][1], row[(x2+i)][2], row[(x2+i)][3], row[(x2+i)][4], row[(x2+i)][5], row[(x2+i)][6],
                row[(x2+i)][7], row[(x2+i)][8]);

    }
    if( (y1 == x1) && (y2 < x2)   ){ //this is for to take a piece of rival by going back
        int j = 1;
        int k = x2-y2;
        int count2 = 0;
        while(k!= count2) {
            if ((row[x2 - j][x1]) != 'b' && (row[x2 - j][x1]) != 'B' && (row[x2 - j][x1]) != 'w' && (row[x2 - j][x1]) != 'W') {
                j++;
            }
            if ((row[x2 - j][x1]) == 'b' || (row[x2 - j][x1]) == 'B' || (row[x2 - j][x1]) == 'w' || (row[x2 - j][x1]) == 'W'){
                break;
            }
            count2++;
        }
        row[x2-j][x1] = '_';
        //we are using fseek one more time , because if we take rival's piece by moving back, 3 column will be changed , so we should use one more time
        fseek(file2, (8-(x2-j)) * 11, SEEK_SET);
        fprintf(file2, "%c%c%c%c%c%c%c%c%c",row[(x2-j)][0],row[(x2-j)][1], row[(x2-j)][2], row[(x2-j)][3], row[(x2-j)][4], row[(x2-j)][5], row[(x2-j)][6],
                row[(x2-j)][7], row[(x2-j)][8]);
    }

    if( (y1 > x1) && (y2 == x2)   ){  //this is for to take piece of rival by moving right
        int j = 1;
        int k = y1-x1;
        int count2 = 0;
        while(k!= count2) {
            if ((row[x2][x1 + j]) != 'b' && (row[x2][x1 + j]) != 'B' && (row[x2][x1 + j]) != 'w' && (row[x2][x1 + j]) != 'W') {
                j++;
            }
            if ((row[x2][x1 + j]) == 'b' || (row[x2][x1 + j]) == 'B' || (row[x2][x1 + j]) == 'w' || (row[x2][x1 + j]) == 'W'){
                break;
            }
            count2++;
        }
        row[x2][x1+j] = '_';
    }

    if( (y1 < x1) && (y2 == x2)   ){  //this is for to take piece of rival by moving left
        int i = 1;
        int k = x1-y1;
        int count = 0;
        while(k!= count) {
            if ((row[x2][x1 - i]) != 'b' && (row[x2][x1 - i]) != 'B' && (row[x2][x1 - i]) != 'w' && (row[x2][x1 - i]) != 'W') {
                i++;
            }
            if ((row[x2][x1 - i]) == 'b' || (row[x2][x1 - i]) == 'B' || (row[x2][x1 - i]) == 'w' || (row[x2][x1 - i]) == 'W'){
                break;
            }
            count++;
        }
        row[x2][x1-i] = '_';
    }

    row[y2][y1] = row[x2][x1];
    row[x2][x1] = '_';
//---------------------------------------------------------------------------------------------------------------------------------------------------
    //--changing first piece
    fseek(file2, (8-x2) * 11, SEEK_SET);
    fprintf(file2, "%d%c%c%c%c%c%c%c%c",x2,row[x2][1], row[x2][2], row[x2][3], row[x2][4], row[x2][5], row[x2][6],
            row[x2][7], row[x2][8]);
    //--changing first piece
//---------------------------------------------------------------------------------------------------------------------------------------------
    //--changing second piece
    fseek(file2, (8-y2) * 11 , SEEK_SET);
    fprintf(file2, "%d%c%c%c%c%c%c%c%c",y2 ,row[y2][1],row[y2][2], row[y2][3], row[y2][4], row[y2][5], row[y2][6],
            row[y2][7], row[y2][8]);
    //--changing second piece
//---------------------------------------------------------------------------------------------------------------------------------------------
    //changing player turn
    fseek(file2, 88 , SEEK_SET);
    fprintf(file2, "%c" , row[0][0]);
    //changing player turn
//---------------------------------------------------------------------------------------------------------------------------------------------
    fclose(file2);
}
void saveTxt(FILE *save,int x1,int y1,int x2,int y2,char board[9][9]){//This is for midterm . Function can save the moves .
    char c1,c2;
    c1=x1+'0'+48;
    c2=x2+'0'+48;
    save = fopen("hamleler.txt", "a+");              //record file
    if(board[0][0]=='+') {
        fprintf(save, "w:%c%d%c%d\n",c1,y1,c2,y2);
    }
    if(board[0][0]=='-') {
        fprintf(save, "b:%c%d%c%d\n",c1,y1,c2,y2);
    }
    fclose(save);
}
void resetTxt(FILE *save){//When Player start the new game we should reset the hamleler.txt , for new clean record
    save = fopen("hamleler.txt", "w+");
    fclose(save);
}
void changeplayer(char board[9][9]){//i wrote this function because , if turn is on player 2 and if user close the program , then when the program start , turn would be on player 1 , so i fixed this with this function
    FILE *file2;
    file2 = fopen("dama.txt", "r+");
    fseek(file2, 88 , SEEK_SET);
    fprintf(file2, "%c" , board[0][0]);
    fclose(file2);
}
void wincontrol(char board[9][9]){//we find the winner by looking pieces of players...
    int count1 = 0;
    int count2 = 0;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(board[i][j] == 'b' || board[i][j] == 'B'){
                count1++;
            }
            if(board[i][j] == 'w' || board[i][j]=='W'){
                count2++;
            }
        }
    }
    if(count1 == 0){
        cout << "player 1 won" << endl;
    }
    if(count2== 0){
        cout << "player 2 won" << endl;
    }
}

int main() {
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "----------------------Please Read Before You Start The Game--------------------------" << endl;
    cout << "--------------------Write Moves With Capital Letters Ex: A3A4------------------------" << endl;
    cout << "---If You Can't See The Board After You Move,You Most Probably Make Moving Mistake---" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;

    //Welcome part
    printf("\n");
    printf(".....Welcome To The Checker Game.....\n");
    printf("\n");
    //Welcome Part

    //menu design
    printf("1 - Start New Game\n");
    printf("2 - Continue Game\n");
    printf("3 - Exit Game  \n\n");
    //menu design


    char checkerTable[9][9] = {'+', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                               '1', '_', '_', '_', '_', '_', '_', '_', '_',
                               '2', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w',
                               '3', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w',
                               '4', '_', '_', '_', '_', '_', '_', '_', '_',
                               '5', '_', '_', '_', '_', '_', '_', '_', '_',
                               '6', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                               '7', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b',
                               '8', '_', '_', '_', '_', '_', '_', '_', '_',};


    FILE *myfile;
    myfile = fopen("dama.txt", "r+");
    FILE *hamleler;
    hamleler = fopen("hamleler.txt","r+");
    fclose(hamleler);
    printf("Please Make Your Choice \n");
    cout << endl;
    int choice;
    scanf_s("%d", &choice);
    switch (choice) {
        case 1: {
            for(int i = 8; i>= 0; i--){
                for(int j = 0; j < 9; j++){
                    fprintf(myfile, "%c", checkerTable[i][j]);
                }fprintf(myfile,"\n");
            }
            fclose(myfile);
        }
        resetTxt(hamleler);
        case 2: {
            for (int i = 8; i >= 0; i--) {
                for (int j = 0; j < 9; j++) {
                    fscanf_s(myfile, "%c", &checkerTable[i][j]);
                }
                fscanf_s(myfile, "\n");
            }
            printTable(checkerTable);
            if(checkerTable[0][0] == '+'){
                cout << "turn for player 1" << endl;
            }else{
                cout << "turn for player 2" << endl;
            }

            for (int i = 0; i < 1000; i++) { // I wanted to put while but İ could not, because it gave an error because of compiler , so i decided to put 1000 into for loop
                wincontrol(checkerTable);
                cout << "enter your move" << endl;
                char startLetter, targetLetter;
                int startNumber, targetNumber;
                if (shouldWeEatAny(checkerTable) == 1) {
                    while (1) {
                        cin >> startLetter >> startNumber >> targetLetter >> targetNumber;
                        if ((abs(targetNumber - startNumber) == 2) || abs(targetLetter - startLetter) == 2) {
                            break;
                        } else {
                            cout << "you must attack to rival" << endl;
                        }
                    }
                }
                else if(shouldWeEatAnyForStamp(checkerTable)==1){
                    while (1){
                        cin>>startLetter>>startNumber>>targetLetter>>targetNumber;
                        int d1 = findPlaceOfLetter(startLetter,checkerTable);
                        int d2 = findPlaceOfLetter(targetLetter,checkerTable);
                        if(stampControl2(d1,startNumber,d2,targetNumber,checkerTable) == 1){
                            break;
                        }else{
                            cout << "you must attack to rival with stamp" << endl;
                        }
                    }
                }
                else {
                    cin >> startLetter >> startNumber >> targetLetter >> targetNumber;
                }

                if (startNumber < 99) {
                    int x1 = findPlaceOfLetter(startLetter, checkerTable);
                    int y1 = findPlaceOfLetter(targetLetter, checkerTable);

                    if(checkerTable[startNumber][x1] == 'W' || checkerTable[startNumber][x1] == 'B'){
                        if(stampControl(x1,startNumber,y1,targetNumber,checkerTable) == 1){
                            if(checkerTable[startNumber][x1] == 'W'  && (checkerTable[0][0] == '+')){
                                if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 1 && shouldWeEatAnyForStamp(checkerTable) == 1){
                                    moveStamp(x1, startNumber, y1, targetNumber, checkerTable);
                                    saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                    checkerTable[0][0] = '+';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 0 && shouldWeEatAnyForStamp(checkerTable) == 0){
                                        checkerTable[0][0] = '-';
                                        changeplayer(checkerTable);
                                        cout << "turn for player 2" << endl;
                                    }
                                    else{
                                        cout << "turn for player 1" << endl;
                                    }
                                }
                                else if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 0 || shouldWeEatAnyForStamp(checkerTable) == 0){
                                    moveStamp(x1, startNumber, y1, targetNumber, checkerTable);
                                    saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                    checkerTable[0][0] = '-';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 2" << endl;
                                }
                            }
                            if(checkerTable[startNumber][x1] == 'B'  && (checkerTable[0][0] == '-')){
                                if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 1 && shouldWeEatAnyForStamp(checkerTable) == 1){
                                    moveStamp(x1, startNumber, y1, targetNumber, checkerTable);
                                    saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                    checkerTable[0][0] = '-';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 0 && shouldWeEatAnyForStamp(checkerTable) == 0){
                                        checkerTable[0][0] = '+';
                                        changeplayer(checkerTable);
                                        cout << "turn for player 1" << endl;
                                    }
                                    else {
                                        cout << "turn for player 2" << endl;
                                    }
                                }
                                else if(stampControl2(x1,startNumber,y1,targetNumber,checkerTable) == 0 || shouldWeEatAnyForStamp(checkerTable) == 0){
                                    moveStamp(x1, startNumber, y1, targetNumber, checkerTable);
                                    saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                    checkerTable[0][0] = '+';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 1" << endl;
                                }
                            }
                            else{
                                cout << "";
                            }
                        }else{
                            cout << "";
                        }
                    }
                    if(checkerTable[startNumber][x1] == 'w' || checkerTable[startNumber][x1] == 'b'){
                        if (pieceControl(x1, startNumber, y1, targetNumber, checkerTable)) {
                            if ((checkerTable[startNumber][x1] == 'w') && (checkerTable[0][0] == '+')) {
                                movePiece(x1, startNumber, y1, targetNumber, checkerTable);
                                saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                if ((shouldWeContinueToEatForW(checkerTable) == 1) &&
                                    ((abs(targetNumber - startNumber) == 2) || abs(y1 - x1) == 2)) {
                                    checkerTable[0][0] = '+';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 1" << endl;
                                } else {
                                    checkerTable[0][0] = '-';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 2" << endl;
                                }
                            } else if ((checkerTable[startNumber][x1] == 'b') && (checkerTable[0][0] == '-')) {
                                movePiece(x1, startNumber, y1, targetNumber, checkerTable);
                                saveTxt(hamleler,x1,startNumber,y1,targetNumber,checkerTable);
                                if ((shouldWeContinueToEatForB(checkerTable) == 1) &&
                                    ((abs(targetNumber - startNumber) == 2) || abs(y1 - x1) == 2)) {
                                    checkerTable[0][0] = '-';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 2" << endl;
                                } else {
                                    checkerTable[0][0] = '+';
                                    changeplayer(checkerTable);
                                    printTable(checkerTable);
                                    cout << "turn for player 1" << endl;
                                }
                            } else {
                                cout << "";
                            }
                        }else{
                            cout << "";
                        }
                    }
                    else {
                        cout << "";
                    }
                }
            }
            break;
        }
        case 3: {
            printf("The game is over..\nThis window will be closed");
            break;
        }
    }
}
