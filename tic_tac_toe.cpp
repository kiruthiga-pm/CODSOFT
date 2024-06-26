#include<iostream>
using namespace std;
void display_board(char g_board[3][3]){
    cout<<"-------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"|";
        for(int j=0;j<3;j++){
            cout<<g_board[i][j]<<"|";
        }
        cout<<endl<<"-------"<<endl;
    }
}
bool check_win(char g_board[3][3],char player){
    if(g_board[0][0]==player && g_board[1][1]==player && g_board[2][2]==player){
        return true;//main diagonal
    }
    else if(g_board[2][0]==player && g_board[1][1]==player && g_board[2][0]==player){
        return true;//secondary diagonal
    }
    else{
        for(int i=0;i<3;i++){
        if(g_board[i][0]==player && g_board[i][1]==player && g_board[i][2]==player){
            return true;//row
        }
        else if(g_board[0][i]==player && g_board[1][i]==player && g_board[2][i]==player){
            return true;//column
        }
        }
    }
    return false;
}
int main(){
    char g_board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char player='X';
    display_board(g_board);
    int turn=0;
    int row,col;
    bool result;
    while(turn<=9){
        cout<<"Player: "<<player<<endl;
        cout<<"Enter row and column: "<<endl;
        cin>>row>>col;
        if(g_board[row][col]==' '){
                g_board[row][col]=player;
        }
        display_board(g_board);
        result=check_win(g_board,player);
        if(result==true){
            cout<<"Player "<<player<<" is won"<<endl;
            break;
        }
        else if(result==false && turn < 9){
            player=(player=='X')?'O':'X';
            turn++;
        }
        else{
            cout<<"Match draw"<<endl;
        }
    }
}
